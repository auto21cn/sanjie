// mantian.c 摘星手 「满天星」

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
//        string mantian;
      string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");


        if((int)me->query_skill("dangmo-xinjing",1) < 100)
                return notify_fail("你荡魔心经的级别不够不能使用满天星!\n");

        if((int)me->query_skill("zhaixing-shou",1) < 100)
                return notify_fail("你的摘星手修为不够,目前还不能使用满天星绝技!\n");       

        if((int)me->query("force") < 200)
                return notify_fail("你内力现在不够, 不能使用满天星! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

        message_vision(HIY"$N使出摘星手绝技「满天星」，双手十指翻花，罩住了$n的全身要穴。\n"NOR,me,target);

        if( random(me->query("combat_exp")) > target->query("combat_exp") / 4 ) {
        message_vision(HIY"$N不知如何招架是好，结果身上七处穴道受制，立时动弹不得！\n"NOR,target);
                target->start_busy(me->query_skill("zhaixing-shou",1) / 20 - 1);
                me->add("force", -150);
        } else {
                message_vision(HIG "$N轻轻向后一跃，避开了这一招。$n招数用老，自己反而露出了破绽。\n" NOR,target,me);
                me->start_busy(1+random(3));
        }
//        message_vision(mantian, me, target);

        return 1;
}

