// 增强perform功能
// add by bird
//perform.c
#include <ansi.h>
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

//bird 04/3/31 add performs checking
int show_perform(string arg)
{
         mixed *files;
         string dir=SKILL_D(arg)->perform_action_file(""); //获得skill的路径
         string pfms="";
         int i;

         if(!dir) return notify_fail("什么");
         files=get_dir(dir+"*.c",-1);
         for(i=0;i<sizeof(files);i++)
                   pfms+="『 "+files[i][0][0..<3]+" 』\n";
         write("你目前可以使用的招式有：\n");
         write(pfms);
         return 1;
}

int main(object me, string arg)
{
         object weapon, target;
         string martial, skill, perf;
         int show;

         seteuid(getuid());

         if( me->is_busy() )
                     return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");
         if( !arg ) show=1;
         if ( !wizardp(me) && environment(me)->query("no_fight"))
                     return notify_fail("这里不能施用外功。\n");

         if( arg&&sscanf(arg, "%s on %s", perf, arg)==2 ) {
                  target = present(arg, environment(me));
                  if( !target ) target = present(arg, me);
                  if( !target ) return notify_fail("这里没有 " + arg + "。\n");

                  if(!valid_kill(me,target,0)) return 0;
                  set_to_killer(me,target);
                  if( userp(me) && userp(target) &&
                  target->query_temp("netdead") )
                  return notify_fail("对方正在断线中，不能对其施用外功。\n");
                  arg=perf+" "+arg;
 } else if(arg&&sscanf(arg, "%s %s", perf, arg)==2 ) {
    arg=perf;
}
         if( weapon = me->query_temp("weapon") )
             martial = weapon->query("skill_type");
       else
             martial = "unarmed";

         if( stringp(skill = me->query_skill_mapped(martial)) ) {
             notify_fail("你所使用的外功中没有这种功能。\n");
             
             if(show) {show_perform(skill);return 1;}
             if( SKILL_D(skill)->perform_action(me, arg) ) {
                 if( random(120) < (int)me->query_skill(skill) )
                    me->improve_skill(skill, 1, 1);
                 return 1;
             } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                 if( random(120) < (int)me->query_skill(martial, 1) )
                    me->improve_skill(martial, 1, 1);
                 return 1;
             } 
             return 0;
       }   
             martial = "literate";
             if( stringp(skill = me->query_skill_mapped(martial)) ) {
                notify_fail("你所使用的外功中没有这种功能。\n");
             if(show) {show_perform(skill);return 1;}
             if( SKILL_D(skill)->perform_action(me, arg) ) {
                   if( random(120) < (int)me->query_skill(skill) )
                         me->improve_skill(skill, 1, 1);
                   return 1;
             } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                   if( random(120) < (int)me->query_skill(martial, 1) )
                        me->improve_skill(martial, 1, 1);
                   return 1;
             }
             return 0;

             }
             if(show) notify_fail("你现在没有可以使用的招式。\n");
             else notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
             return 0;
}
int help (object me)
{
       write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]
如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
       return 1;
}
