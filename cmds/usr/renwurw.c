// job.c
// creatied by passion@skxy
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
      object ob;
    mapping my;
    string line;
              if(!arg) ob = me;  
              else if (wizardp(me)) { ob = present(arg, environment(me));  
                   if (!ob) ob = find_player(arg);  
                   if (!ob) ob = find_living(arg);  
              if (!ob) return notify_fail("您要察看谁的状态？\n");  
              }   
                      else return notify_fail("你无权察看别人的状态。\n");  
     my = ob->query_entire_dbase();
/*
    if (!wizardp(ob) || arg == "") me = ob;
    else
    {
        if( arg ){
            me = present(arg, environment(ob));
            if (!me) me =  find_player(arg);
            if (!me) return notify_fail("你要察看谁的状态？\n");
        }
        else {
*/
            me = ob;
              line = sprintf(" 门派任务:\n"); 
            line += sprintf(" 你到目前为止总共完成了%s个门派任务，", 
              HIR+my["m_win"]+NOR,);
              line += sprintf("放弃了%s个门派任务,", 
              HIR+my["m_fangqi"]+NOR,);
             line += sprintf("失败了%s次.\n", 
              HIR+my["m_shibai"]+NOR,);
            write(line); 
            return 1;
        }
int help(object me)
{
    write(@HELP
指令格式 : job
这个指令可以显示出你所有完成过的任务。
HELP
    );
    return 1;
}




