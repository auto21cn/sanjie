//posui.c 破碎虚空
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
 return notify_fail("你要对谁施展「破碎虚空」？\n");
        if (!PFM_D->valid_family(me, "轩辕古墓"))
return notify_fail("不是古墓弟子怎么能用圣灵剑法？\n");
        if ( me->query("gender") =="女性" )  
                return notify_fail("女人发挥不出这招的威力。\n"); 
   if(environment(me)!=environment(target))
 return notify_fail("你现在没有了攻击目标!\n");
            if((string)me->query_skill_mapped("force")!="jiuyin-force")
  return notify_fail("欲施轩辕绝学，需九阴为根基啊。\n");
        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("你的内力不足！\n");
            if(me->query("max_force") < 1000 || me->query("force")<500)
   return notify_fail("内力不足，根本无法发挥轩辕绝学的威力。\n");
        if((int)me->query("kee") < 200 )
   return notify_fail("你身体太虚弱了，无法施展「破碎虚空」！\n");
      if((int)me->query_skill("mohuang-blade", 1) <200)
   return notify_fail("你的魔皇刀法练得不够纯熟，无法使出这招「破碎虚空」！\n");
         if((int)me->query_skill("jiuyin-force", 1) <200)
 return notify_fail("你对九阴领悟尚浅，不能使出「破碎虚空」！\n");

        if( time()-(int)me->query_temp("posui_end") < 4 )  
                return notify_fail("你现在真气不纯。\n"); 

        me->add("force", -50-(int)me->query("force_factor"));
 msg = HIW
 "$N凝神一吼，手中兵刃由下而上翻将上来，如天幕倒垂般卷向将过去！ 

                ┏━┓ ┏━┓ ┏━┓ ┏━┓ 
                ┃倒┃ ┃转┃ ┃乾┃ ┃坤┃             
                ┗━┛ ┗━┛ ┗━┛ ┗━┛ 


                      破·碎·虚·空\n"NOR;

        ap = me->query_skill("mohuang-blade", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1000 ) {
  msg += HIY "$n慌忙中左躲右闪，逃过了铺天盖地的一击！\n\n"NOR;
           message_vision(msg, me, target);
   } else {
        if(!target->is_busy()) target->start_busy(2);
                damage = (int)me->query_skill("mohuang-blade",1) / 10 +
        (int)me->query("sen") / 300 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 300 + random((int)me->query("kee") / 200 );
  msg += HIR "\n$n顿时被包围在一片无际的天幕中！\n\n" NOR;
     damage +=random(10);
                        target->receive_damage("sen", me->query("eff_sen")*damage/200,me,"pfm");
                        target->receive_damage("kee", me->query("eff_kee")*damage/200,me,"pfm");
       target->receive_wound("kee", me->query("eff_kee")*damage/300,me,"pfm");
                        me->improve_skill("mohuang-blade", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
//        me->start_busy(1+random(3));
        me->set_temp("posui_end",time());
        return 1;
}

