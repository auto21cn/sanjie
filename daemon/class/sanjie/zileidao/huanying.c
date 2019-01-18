#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"开什么玩笑，没装备刀怎么使「无形幻影」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("zileidao", 1) < 90 )
   return notify_fail(WHT"你的紫雷刀法不够娴熟，还使不出「无形幻影」。\n"NOR);
    if( (int)me->query_skill("huntianforce", 1) < 70 )
         return notify_fail(RED"你的混天宝鉴修为还不够，「无形幻影」不成招式。\n"NOR);
    if ((int)me->query("max_force")<300)
   return notify_fail(RED"你的内力修为不足，无法运足「无形幻影」的内力。\n"NOR);
    if ((int)me->query("force")<200)   
          return notify_fail(HIC"你现在内力不够，没能将「无形幻影」使完！\n"NOR);
  
    msg = HIC "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀光席卷而来，\n $n奋力一架，但$N刀分数路，$n只架住一刀！\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3||
   random((int)target->query("combat_exp")) < (me->query("combat_exp")) )
    {
   //me->start_busy(2);
  // target->start_busy(random(3));
   damage = (int)me->query_skill("zileidao", 1);
   damage = damage + random(damage);
   target->receive_damage("kee", damage);
   target->receive_wound("kee", damage/3);
//   target->add("eff_kee", -damage/2);
   target->receive_damage("sen", damage/3);
//   target->add("eff_sen", -damage/4);
   msg += HIC"$n根本没法躲避，顿时几刀都砍在$n肩头！\n"+HIR"$n鲜血溅起，$n自觉眼前一片鲜红，遮住视线！\n"NOR;
   me->add("force", -damage/5);
     me->start_busy(random(3));
   if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                                  } 
    }else
    {
   me->start_busy(2);
   msg += HIY"可是$p早以看出那是虚招，毫不在意地坦然面对，果真只有架住的是实招。\n"NOR;
    }
    message_vision(msg, me, target);
    return 1;
}
