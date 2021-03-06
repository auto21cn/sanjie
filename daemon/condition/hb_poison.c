// hb_poison.c 寒冰攻击

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
         if(!living(me)) {
                 message("vision", HIB+me->name() + "冷得手脚都已发直。\n"NOR, environment(me), me);
         }
         else {
                 tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的寒毒发作了！\n"NOR);
                 message("vision",HIB + me->name() + "发起抖来，冷得全身缩成一团，手脚僵硬。\n"NOR,environment(me), me);
         }
         me->receive_damage("kee", 35);
         me->receive_wound("sen", 30);
         me->receive_wound("kee", 30);         
         me->set_temp("death_msg","中寒冰攻击死了。\n");
         me->apply_condition("hb_poison", duration - 1);
         if( duration < 1 ) return 0;
         return CND_CONTINUE;
}

string query_type(object me)
{
         return "poison";
}
