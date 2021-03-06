//Cracked by Roath
//Ansi 99.12

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int i;
        int f_time;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「心动三剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「心动三剑」只能在战斗中使用！\n");
                
        if (!PFM_D->valid_family(me, "蜀山剑派"))
                return notify_fail("不是蜀山的不能用「心动三剑」！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("mindsword", 1) < 80)
                return notify_fail("你的心剑修为还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->add_temp("apply/attack", (int)(me->query_skill("mindsword",1)/6));
        me->add_temp("apply/damage", (int)(me->query_skill("mindsword",1)/6));
        message_vision(HIW"\n$N集中精神，施展心剑的「心动三剑」，向$n发动会心攻击！\n"NOR,me,target);
        message_vision(HIR"\n心动心动，我心疯狂！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR"\n心动心动，花心怒放！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR"\n心动心动，心剑合一！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack", -(int)(me->query_skill("mindsword",1)/6));
        me->add_temp("apply/damage", -(int)(me->query_skill("mindsword",1)/6));
        if( me->query_temp("shushantop")) 
        {
                if( living(target)) 
                        target->receive_damage("kee",5*((int)me->query_skill("sword",1)),me,"pfm");
                        message_vision(HIR"\n$N突然使出心剑最终密招，暴喝而至！\n$n受到了严重的伤害！\n"NOR,me,target);
        }
        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

