//by dewbaby@sk_sjsh
//guang.c
//【无影波光】escape from combat


#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

              if((string)me->query("family/family_name") !="凌海神宫")
                return notify_fail("只有凌海神宫中人才会此法术!\n");

        if( me->query("gender") =="男性" )
                return notify_fail("凌波仙子只传女不传男，你从哪里偷学来的？\n");         


        message_vision(HIC"$N默念了几句咒语...\n\n"HIC"周身被粼粼波光罩住。\n", me);

        me->add("mana", -20);
        me->receive_damage("sen", 20);

        if(me->is_fighting() ) {
        if(random((int)me->query("combat_exp")) >=(int)target->query("combat_exp")/2) {
                           message_vision(WHT"$N"WHT"被波光笼罩，幻化成滴滴露水，消失在空气中.....\n"NOR, me);
            me->move("/u/dewbaby/wangxian/huxin");

            tell_room(environment(me),
        WHT"顷刻间，天空阴霾一片，冰雨扫城，只见"+me->query("name")+"从一片朦胧雨雾中走出。\n\n"NOR, ({me, me}) );
            
            } else {
        message_vision(WHT"$N念来念去念了半天，却发现毫不管用。\n"NOR, me, target);
            me->start_busy(1+random(1));
             }
        } else {        message_vision(WHT"$N"WHT"被波光笼罩，幻化成滴滴露水，消失在空气中.....\n"NOR, me); 
            me->move("/u/dewbaby/wangxian/huxin");
     
            tell_room(environment(me), 
        WHT"顷刻间，天空阴霾一片，冰雨扫城，只见"+me->query("name")+"从一片朦胧雨雾中走出。\n\n"NOR, ({me, me}) );        }

        return 1;
}



