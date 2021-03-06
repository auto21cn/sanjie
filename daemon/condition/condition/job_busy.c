// job_busy.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    if (duration <= 1)
    {
        me->delete_temp("tongchuan");
        me->delete_temp("baohu");
        me->delete_temp("dajiu");
        return 0;
    }

    me->apply_condition("job_busy", duration - 1);
    return 1;
}

string query_type(object me) {return "job";}
