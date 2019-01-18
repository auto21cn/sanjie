//moonforce--heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
                return
notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIY "你在心中默运九阴真经，一股真气在你的四肢百骸缓缓游走。\n" NOR);
        message("vision",
                YEL + me->name() +
"呼龛九阴，一丝真气从百会穴悠悠浮上，笼罩着全身......\n"
NOR,
                environment(me), me);
        me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}

