// bat_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 50+random(200));
        me->receive_wound("sen", 50+random(200));
        me->apply_condition("bat", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "你中的" HIC "七彩蝙蝠毒" HIW "终于发作完了！\n" NOR );
        else
        tell_object(me, HIW "你中的" HIC "七彩蝙蝠毒" HIW  "发作了！\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}

