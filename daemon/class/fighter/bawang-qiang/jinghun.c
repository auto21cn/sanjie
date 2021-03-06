//惊魂霸王枪 BY Cigar 2002.04.05

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon; 
        int damage, ap, dp;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"你要对谁施展「惊魂霸王枪」？\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"「惊魂霸王枪」只能在战斗中使用！\n"NOR); 
        
        if (!PFM_D->valid_family(me, "将军府"))
                return notify_fail(CYN"你不是将军府之人，那里偷学来的绝技？\n"NOR);
        
        if((string)me->query_skill_mapped("force")!="lengquan-force")
                return notify_fail(CYN"你必须用冷泉神功。\n"NOR);

        if((int)me->query("force") < 150+(int)me->query("force_factor") )
                return notify_fail(CYN"你的内力不足，用此招恐怕会有危险。\n"NOR);

        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("你的内力修为甚浅，不足以用[惊魂霸王枪]。\n"NOR);

        if((int)me->query("kee") < 200 )
                return notify_fail(CYN"你身体太虚弱了，无法施展「惊魂霸王枪」！\n"NOR);

        if( time()-(int)me->query_temp("jinghun_end") < 3 ) 
                return notify_fail(CYN"你现在精神无法集中，再用此绝技恐有损元气！\n"NOR); 
        
        if((int)me->query_skill("bawang-qiang", 1) <120)
                return notify_fail(CYN"你的霸王枪法不够纯熟，无法使出这招「惊魂霸王枪」！\n"NOR);

        if((int)me->query_skill("lengquan-force", 1) <120)
                return notify_fail(CYN"你对冷泉神功领悟尚浅，不能使出「惊魂霸王枪」！\n"NOR);

        me->add("force", -65-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = HIW "\n$N手举"+ weapon->query("name")+ HIW"直指苍天,只见枪头寒光点点,枪缨此时显得分外妖娆。";
        msg += "\n\n说时迟，那时快，$N双脚运力，急冲半空，稍是停顿，倒转枪头，俯冲而至，大喝一声≈≈\n\n" NOR;
        
        msg +=HIY "              ┏━┓                        ┏━┓  \n";       
        msg +=HIY "              ┃"+HIW"驚"+HIY"┃  ┏━━━━━━━━┓  ┃"+HIW"泣"+HIY"┃  \n";
        msg +=HIY "              ┃"+HIW"天"+HIY"┃  ┃"+HIR" 驚 魂 霸 王 槍 "+HIY"┃  ┃"+HIW"鬼"+HIY"┃  \n";
        msg +=HIY "              ┃"+HIW"地"+HIY"┃  ┗━━━━━━━━┛  ┃"+HIW"神"+HIY"┃  \n";
        msg +=HIY "              ┗━┛                        ┗━┛  \n";
// 　　　 msg +=HIW"这式"+HIR"惊魂霸王枪"+HIW"绝技真是融会了百家之长，实是绝学中的精华！\n" NOR;
        ap = me->query_skill("bawang-qiang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/200) <  dp/1000 ) 
        {
                msg += "\n\n$n"+HIC"身体急速后退，踉踉跄跄的夺过了这致命的一招，此时浑身早已冷汗淋漓。\n\n"NOR;
                message_vision(msg, me, target);
//              me->start_busy(1+random(1)); 
        } else {
                damage = (int)me->query_skill("parry",1) / 10 +
        (int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 400 + random((int)me->query("kee") / 200 );
                msg += HIW "\n\n只见寒光一闪，$N急冲几步，站定后远望山中景致，但见$n胸前已经被刺出一个血窟窿！\n\n" NOR;
                damage +=random(50);
                if(!target->is_busy()) target->start_busy(2);
                target->receive_damage("sen", me->query("eff_sen")*damage/250,me,"pfm");
                target->receive_damage("kee", me->query("eff_kee")*damage/180,me,"pfm");
                target->receive_wound("kee", me->query("eff_kee")*damage/200,me,"pfm");
                me->improve_skill("bawang-qiang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
//        me->start_busy(2);
        me->set_temp("jinghun_end",time()); 
        return 1;
}

