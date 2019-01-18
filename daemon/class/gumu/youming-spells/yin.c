//轩辕古墓 幽明神通 雾隐
//by junhyun@SK
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

        if (!PFM_D->valid_family(me, "轩辕古墓"))
                return notify_fail("开玩笑吧？你不是古墓弟子怎么会召唤黑雾？\n");

        message_vision("$N喃喃的念了几句咒文。\n", me);

        me->add("mana", -25);
        me->receive_damage("sen", 20);

        if(me->is_fighting() ) {
                if(random((int)me->query("max_mana")) >(int)target->query("max_mana")/2) {
                        message_vision(HIB"随有一挥，平地起来一团黑雾，瞬间包围着$N消失的无影无踪......\n"NOR, me);
                        me->move("/d/gumu/beiji");
                        tell_room(environment(me),
HIB"突然起了一阵黑雾，"+me->query("name")+"从黑雾中走了出来。\n\n"NOR, ({me, me}) );

                } else {
                        message_vision(HIW"$N转身想跑，却被$n一个箭步拦住。\n"NOR, me, target);
                        me->start_busy(2);
                }
        } else {
                message_vision(HIB"随有一挥，平地起来一团黑雾，瞬间包围着$N消失的无影无踪......\n"NOR, me);
                me->move("/d/gumu/beiji");
                tell_room(environment(me),
HIB"突然起了一阵黑雾，"+me->query("name")+"从黑雾中走了出来\n\n"NOR, ({me, me}) );

        }

        return 5+random(5);
}

