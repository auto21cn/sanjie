//by dewbaby@sk_sjsh
//九剑·情绝

#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        int lvl;
        object weapon;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使「情绝」。\n");

        if( (int)me->query_skill("kongwujian", 1) < 120 )
                return notify_fail("你的空无剑不够娴熟，无法施展出「情绝」。\n");
        if ((int)me->query_skill("linghai-force", 1) < 120)
                return notify_fail("你的凌海心法火候不够，无法施展出「情绝」。\n");
        if ((int)me->query_skill("lingbo-steps", 1) < 120)
                return notify_fail("你的凌波微步火候不够，无法施展出「情绝」。\n");
        if ( (int)me->query("max_force") < 2000)
                return notify_fail("你的内力不够，无法施展出「情绝」。\n");
        if ( (int)me->query("force") < 500)
                return notify_fail("你的真气不够，无法施展出「情绝」。\n");
        if ((int)me->query("kee") < 500)
                return notify_fail("你的气血不够，无法施展出「情绝」。\n");
     
        lvl = me->query_skill("kongwujian", 1);
     message_vision(WHT"$N神情轻蔑地看着$n。\n\n"NOR,me,target);
     message_vision(WHT"$N凝神定气，突然手中"+ weapon->name() +HIY"化为九道金色剑气朝$n射去！\n"NOR,me, target);
 
        me->add("force", -(200 +random(100)) );
        me->add("kee", -50);
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/damage",lvl/2);
        me->add_temp("apply/sword", lvl/3);

        message_vision(HIY"$N身形如风，手中剑气影射不断！\n"NOR,me,target);
message_vision(WHT"$n"+WHT"被被迎面而来的剑气逼得连连后退，似乎颇为吃力。\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
message_vision(HIY"一剑                  "+BLINK+HIC+"泪洒西厢月\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"二剑             "+BLINK+WHT+"迢迢银汉隔\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"三剑             "+BLINK+HIB+"囚来高塔倾\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"四剑             "+BLINK+HIW+"哭到长城裂\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"五剑             "+BLINK+BLU+"百宝影无寻\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"六剑             "+BLINK+HIR+"红楼梦难歇\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"七剑             "+BLINK+HIC+"不如抛此情\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"八剑             "+BLINK+HIM+"去做花间蝶\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"九剑             "+BLINK+WHT+"情绝情难了\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->start_busy(2+random(1));
        me->add_temp("apply/attack", -lvl/2);
        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/sword", -lvl/3);
        return 1;
}


