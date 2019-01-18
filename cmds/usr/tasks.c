// File：/cmds/usr/task.c
// modified by mudring@sjsh......


#include <ansi.h>
int main(object me, string str)
{
        string output;
/*
        int   cur_time;
        cur_time = time();
        if( (cur_time-me->query("last_taskup")) < 40 )             
                return notify_fail("你迟点才可以再查看task指令。\n");
        me->set("last_taskup", cur_time);
*/
        if( (int)me->query("sen") < 200 )
            return notify_fail("身体这么糟，也想做task？\n");
        me->add("sen",-20); 
        me->start_busy(2);


        output =HIR"          ★"HIY"   三界神话使命榜   "HIR"★\n" NOR;
        output += "———————————————————————————\n";
        output += TASK_D->dyn_quest_list();
        output += "———————————————————————————\n\n";
        output += YEL"  ☆"HIW"表示未完成使命     "HIR"★"WHT"表示已经完成的使命\n"NOR;

        me->start_more(output);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: task

这个指令是用来得知目前的所有使命.

HELP
        );
        return 1;
}

