//圣灵绝学 剑八
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
 return notify_fail("你要对谁施展「剑八式」？\n");
if(me->query("family/family_name")!="轩辕古墓")
return notify_fail("不是古墓弟子怎么能用圣灵剑法？\n");
   if(environment(me)!=environment(target))
 return notify_fail("你现在没有了攻击目标!\n");
            if((string)me->query_skill_mapped("force")!="jiuyin-force")
  return notify_fail("欲施圣灵绝学，需九阴为根基啊。\n");
        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("你的内力不足！\n");
            if(me->query("max_force") < 1000 || me->query("force")<500)
   return notify_fail("内力不足，根本无法发挥圣灵绝学的威力。\n");
        if((int)me->query("kee") < 200 )
   return notify_fail("你身体太虚弱了，无法施展「剑八」！\n");
      if((int)me->query_skill("shengling-sword", 1) <200)
   return notify_fail("你的圣灵剑法练得不够纯熟，无法使出这招「剑八」！\n");
         if((int)me->query_skill("jiuyin-force", 1) <200)
 return notify_fail("你对九阴领悟尚浅，不能使出「剑八」！\n");
        me->add("force", -50-(int)me->query("force_factor"));
 msg = HIW
 "\n$N身形渐渐变慢，突然一声怒喝，手中的剑幻化成一片光网
瞬间连出十剑，一个巨大的
"RED"
           ]@         
           ]b      ____        ]@
           ][      @~~~~J[~    ]@
        ___ P____  ]    i[     ]@
       ~~~~]@~~~   J_____U  d  ]@
           ][   /'__ J___   ]i ]@
           ]@'J~ ~~~~]~~d[' jl ]@
           d[       d[  ]@  J[ ]@
         ]%][       d'  ][  i' ]@
      _d~  ]@      a'   d[     ]@
           ][    _r~    ad     ]a
           J[   ~     _a'      J[
          _r                  J~ 
"NOR"\n"HIW"字浮现在$n眼前，\n"NOR;

        ap = me->query_skill("shengling-sword", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1200 ) {
  msg += HIY "$n慌忙中左躲右闪，狼狈的躲开了致命的八剑！\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = (int)me->query_skill("shengling-sword",1) / 10 +
        (int)me->query("sen") / 200 + random((int)me->query("sen") / 150 ) +
        (int)me->query("kee") / 250 + random((int)me->query("kee") / 150 );
  msg += HIR "\n$n顿时被这快如闪电的八剑击中！\n\n" NOR;
     damage +=random(10);
                        target->receive_damage("sen", me->query("eff_sen")*damage/100, me);
                        target->receive_damage("kee", me->query("eff_kee")*damage/100, me);
       target->receive_wound("kee", me->query("eff_kee")*damage/300, me);
                        me->improve_skill("shengling-sword", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
        me->start_busy(1+random(3));
        return 1;
}


