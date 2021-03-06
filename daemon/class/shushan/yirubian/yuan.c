//yuan.c... by koker 2001.03.21

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「无怨无悔」？\n");
        if(!me->is_fighting())
                return notify_fail("「无怨无悔」只能在战斗中使用！\n");
        if (!PFM_D->valid_family(me, "蜀山剑派"))
                return notify_fail("不是蜀山剑派的不能用「无怨无悔」！\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("yirubian", 1) < 70)
                return notify_fail("你的忆如鞭法还不精湛，使用这一招会有困难！\n");

        msg = HIR"\n$N轻轻的叹了口气，手中的长鞭在天空中画了个圈，突然鞭梢直逼$n！\n"NOR;
        ap = me->query_skill("whip");
        ap = ap*ap*ap / 20;
        dp = target->query("combat_exp"); 
        chance = (int)(random( ap + dp ) / dp * 100);
        if (target->is_busy()) chance *= 3;
        if( chance > 26 ) 
        {
                damage = me->query_skill("whip") * 2 + me->query("force_factor");
                if (damage > 800) damage = 750+random(75);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm");
                target->start_busy(random(2)+3);
                msg += CYN"结果$n被$N的「无怨无悔」拦腰而过！\n"NOR;
        }
        
        else 
                msg += "但是被$n躲开了。\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
   
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-200-me->query("force_factor"));
        me->start_busy(2);
        return 1;
}

