#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
         
        string str;

        if(me->is_busy()) return notify_fail("你正忙着呢！\n");
       
        if (stringp("/adm/daemons/ran_moneyd"->show_msg()))
           {
           str="/adm/daemons/ran_moneyd"->show_msg();
           write(CYN"\n天降财神，有宝落民间了！似乎在：\n"NOR+str);
           me->start_busy(2);
           }
           else 
           {write(HIR"\n哦噢！地上的财宝全收走了……\n\n"NOR);
            }
            
        return 1;
                 
}

