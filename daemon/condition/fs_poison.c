#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{         
         tell_object(me, HIY "你突然觉得一股恶臭从腹中升起，不禁大呕起来！\n" NOR );
         tell_room(environment(me), HIY + me->name()+"脸上浮着一层黑气，脚步蹒跚，突然吐出一堆秽物！\n" NOR,({ me }));               
         me->receive_wound("sen", 25);
         me->set_temp("death_msg","腐尸毒发作死了。\n");     
         me->apply_condition("fs_poison", duration - 1);   
         if( duration < 1 ) return 0;   
         return CND_CONTINUE;
}
