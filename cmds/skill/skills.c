// Created By Longer@sjsh
// skills.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

string *base_sk = ({"force","unarmed","blade",
                   "sword","spear","mace",
                   "spells","throwing","parry",
                   "literate","axe","staff",
                   "whip","stick","archery",
                   "rake","dodge","hammer",
                   "fork","dagger"});
                   
string *spc_sk = ({"makeup","qin","xiao","caijian",
                   "fuqin","medical"});

int main(object me, string arg)
{
  object ob;
  mapping skl, lrn, map;
  string *sname, *mapped;
  int i,flag1,flag2,flag3;

  flag1 = 0;  //基本功夫
  flag2 = 0;  //独门功夫
  flag3 = 0;  //特殊功夫

  seteuid(getuid());

  if(!arg)
    ob = me;
  else
  {
    ob = present(arg, environment(me));
    if (!ob) ob = find_player(arg);
    if (!ob) ob = find_living(arg);
    if (!ob) return notify_fail("你要察看谁的技能？\n");
  }
  if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
    return notify_fail("你要察看谁的技能？\n");
  if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me) && !me->is_apprentice_of(ob) && getuid(ob)!=me->query("bonze/dadangid") && getuid(ob)!=me->query("couple/id"))
    return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

  skl = ob->query_skills();
  if(!sizeof(skl))
  {
    write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
    return 1;
  }
  write((ob==me ? "你" : ob->name()) +"目前所学过的技能：（共"+HIR+chinese_number(sizeof(skl))+NOR+"项技能）\n");

  sname  = sort_array( keys(skl), (: strcmp :) );
  map = ob->query_skill_map();
  if( mapp(map) ) mapped = values(map);
  if( !mapped ) mapped = ({});
  lrn = ob->query_learned();
  if( !mapp(lrn) ) lrn = ([]);

  for(i=0; i<sizeof(skl); i++)
  {
    if(member_array(sname[i],spc_sk)!=-1)
    {
      flag3 = 1;
    }
    else if(member_array(sname[i],base_sk)!=-1)
    {
      flag1 = 1;
    }
    else flag2 = 1; 
  }
      
  if(flag1==1)
  {
    printf(NOR HIW"┏━"HBGRN"  基本功夫  "NOR HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR,);
    for(i=0; i<sizeof(skl); i++)
    {
      if(member_array(sname[i],base_sk)!=-1)
      {
        printf(NOR HIW"┃"NOR"%s%-40s" NOR "   - %-10s %4d/%7d"HIW"  ┃"NOR"\n", 
              (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIR"  " : "  ",
              to_chinese(sname[i]) + " (" + sname[i] + ")",
              SKILL_D(sname[i])->level_description(skl[sname[i]]),
              skl[sname[i]], (int)lrn[sname[i]],);
      }
    }
  }
  if(flag2==1)
  {
    if(flag1==1)
      printf(NOR HIW"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
    printf(NOR HIW"┏━"HBGRN"  独门功夫  "NOR HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR,);
    for(i=0; i<sizeof(skl); i++)
    {
      if((member_array(sname[i],spc_sk)==-1)&&(member_array(sname[i],base_sk)==-1))
      {
        printf(NOR HIW"┃"NOR"%s%s%-40s" NOR "   - %-10s %4d/%7d"HIW"  ┃"NOR"\n", 
              (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIR : "",
              (member_array(sname[i], mapped)==-1? "  ": HIR"☆"HIY),
              to_chinese(sname[i]) + " (" + sname[i] + ")",
              SKILL_D(sname[i])->level_description(skl[sname[i]]),
              skl[sname[i]], (int)lrn[sname[i]],);
      }
    }
  }
  if(flag3==1)
  {
    if((flag1==1)||(flag2==1))
      printf(NOR HIW"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
    printf(NOR HIW"┏━"HBGRN"  特殊功夫  "NOR HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR,);
    for(i=0; i<sizeof(skl); i++)
    {
      if(member_array(sname[i],spc_sk)!=-1)
      {
        printf(NOR HIW"┃"NOR"%s%s%-40s" NOR "   - %-10s %4d/%7d"HIW"  ┃"NOR"\n", 
              (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIR : "",
              (member_array(sname[i], mapped)==-1? "  ": HIY"☆"HIG),
              to_chinese(sname[i]) + " (" + sname[i] + ")",
              SKILL_D(sname[i])->level_description(skl[sname[i]]),
              skl[sname[i]], (int)lrn[sname[i]],);
      }
    }
  }
      printf(NOR HIW"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
  write("\n");
  return 1;
}

int help(object me){
        write(@HELP
指令格式 : skills|jineng [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}


