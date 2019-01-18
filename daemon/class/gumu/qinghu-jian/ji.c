#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("qinghu-jian",1);
        if ( extra < 50) return notify_fail("你的[青狐剑法]还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［疾·打风刃］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        msg = MAG  "$N凝聚起天地间万千妖魔的无边力量，霎时风起云涌，一式－ 疾·打风刃 －如急电般劈向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N手中"+ weapon->name()+ HIB "幻出奇异的光华刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N手中"+ weapon->name()+ HIR "发出摄人心魄的呼啸向$n劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "$N手中"+ weapon->name()+ HIW "竟然发出妙不可言的奇香扑向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "风云中诸魔齐现，$N手中"+ weapon->name()+ HIC "鬼神莫测已然到了$n的眼前！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(1+random(2));       

        return 1;
}

