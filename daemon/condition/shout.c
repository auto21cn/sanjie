// shout.c
// by mudring@sjsh......

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        if( duration < 1 ) {
        write(HIW"经过一段时间的调息，你又可以纵声长啸了。\n"NOR);
                    me->delete("chblk/shout");
        return 0;
        }
        me->apply_condition("shout", duration - 1);
        
        return 1;
}

string query_type(object me)
{
        return "sleep";
}


