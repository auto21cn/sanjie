// abandon.c
// modified by Tree

inherit F_CLEAN_UP;

// mon@xyj 10/15/98
void do_abandon(string yn, object me, string arg, int num, string flag);

int main(object me, string arg)
{
    mapping skills;
    string name, flag="";
    int num;

        if( !arg || arg=="" ) return notify_fail("你要放弃哪一项技能？\n");

    if (sscanf(arg,"%s %d",name,num)!=2) 
       if(sscanf(arg,"%s",name)==1) flag="all";
       else  return notify_fail("abandon|fangqi <skillname> <number>\n");
  
        skills=me->query_skills();

    if((string)name=="all")
      {
            if(flag=="all") write("你确定要放弃所有的技能么？(y/n)");
            else write("你确定要放弃所有小于"+chinese_number(num)+"级的技能么？(y/n)");
            input_to("do_abandon_all",me,num,flag);
            return 1;
      }

        if( !skills || undefinedp(skills[name]) )
            return notify_fail("你并没有学过这项技能。\n");

    if (num<0)
       return notify_fail("你怕是在做梦把？\n");

        if((int)skills[name]>=10) {
            write("你确定要放弃"+to_chinese(name)+
                    "？(y/n)");
            input_to("do_abandon",me,name,num,flag);
        } else
            do_abandon("yes",me,name,num,flag);
        
        return 1;
}

void do_abandon(string yn, object me, string arg, int num, string flag)
{
    int level;
     if(!me) return;

     if(!yn) {
         write("什么？\n");
         return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {

      level=me->query_skill(arg,1);
      if((flag=="all")||level==0)
        {
        if( !me->delete_skill(arg) ) 
          {
                    write("你没有学过这项技能。\n");
                    return;
              }
         write("你放弃了"+ chinese_number(level)+ "级的" + to_chinese(arg) + "。\n");
         return;
         }
      else {
      if (!level) 
      {
        write("没有这项技能。\n");
        return;
      }
      if (level>num) me->set_skill(arg,level-num);
      else      if( !me->delete_skill(arg) ) {
                write("你没有学过这项技能。\n");
                return;
           }}

        write("你放弃了"+ chinese_number(level>num?num:level)+ "级的" + to_chinese(arg) + "。\n");
        
        if(MISC_D->random_capture(me,8000,0)) return;

        return;
     } else {
         write("你决定保留这项技能。\n");
         return;
     }
}

void do_abandon_all(string yn, object me, int num, string flag)
{
     int level,i;
     mapping skills;
     string *sname;
     if(!me) return;

     if(!yn) {
         write("什么？\n");
         return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {
        skills = me->query_skills();
        sname  = sort_array( keys(skills), (: strcmp :) );
        for (i=0;i<sizeof(sname) ;i++ )
        {
          level = me->query_skill(sname[i],1);
          if(flag=="all") 
           {
             write("你放弃了"+chinese_number(level)+"级的"+to_chinese(sname[i])+"。\n");
             me->delete_skill(sname[i]);
           }
          else if(level<num) 
           {
             write("你放弃了"+chinese_number(level)+"级的"+to_chinese(sname[i])+"。\n");
             me->delete_skill(sname[i]);
           }
        }
        return;       
     } else {
         write("你决定保留这项技能。\n");
         return;
     }
}

int help()
{
        write(@TEXT
指令格式：abandon|fangqi <技能名称> <级数>

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由於我们假设你
的人物随时都会从他／她的各种动作、战斗中学习，因此有些技能会因为你经常地使
用而出现在你的技能列表中，这个人物就必须花费一些精神去「记住」所学过的一切
，然而，人的资质各有不同，灵性高的人能够学习许多技能而成为多才多艺的才子，
灵性较差的人就只能专心於特定几项技能，如果你学的技能种类太多，超过你的灵性
，你会发现人物的学习速度将比只学几种技能的人慢，超过越多，学习效果低落的情
况越严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著超人的
意志力练下去，不过这将会多花费你许多宝贵的时间。

格式： 
fangqi <技能名称> <级别>  放弃指定级数的技能 
fangqi <技能名称> 放弃指定技能（全部） 
fangqi all  放弃所有技能（有必要么？） 
fangqi all <级别> 放弃所有小于指定级别的技能 

                                       Tree修订
TEXT
        );
        return 1;
}

