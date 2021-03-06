//天魔再现 by cigar

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="天魔再现";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｔｍｚｘ\n"
        +"条件：大力棒120级，火魔心法120级"
        +"能够同时伤害对方的精神和气血！";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天魔再现」？\n");

        if (!PFM_D->valid_family(me, "火云洞"))
                return notify_fail("你不是火云洞门人，怎么能使用野外火云绝技？\n");
                
        if((string)me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("不会火魔心法的人用不了天魔再现。\n");

        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("你的内力不足！\n");

        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("内力不足，无法发挥天魔再现的威力。\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你身体太虚弱了，无法施展「天魔再现」！\n");

        if((int)me->query_skill("dali-bang", 1) <120)
                return notify_fail("你的大力棒练得不够纯熟，无法使出这招「天魔再现」！\n");

        if((int)me->query_skill("huomoforce", 1) <100)
                return notify_fail("你对火魔心法领悟尚浅，不能使出「天魔再现」！\n");

        me->add("force", -35-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

        msg = HIR
"\n$N默运火魔神功，身形忽向斜后飞出，$n正要追击，却不料$N手中放出一道绚丽的光环，顿时天空中出现一个大力魔神，只见魔神手举天庭神棒，\n"
"如闪电，如雷火一般直贯$n胸前，仓惶间$n早已六神无主，不知如何是好\n" NOR;

        ap = me->query_skill("dali-bang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/400) <  dp/1000 ) 
        {
                msg += "$n"+HIG"身体立即直冲云霄，似有一种"+HIW"我于天斗，老天奈何于我"+HIG"的气势，躲过了这致命一击！\n\n"NOR;
                message_vision(msg, me, target);
        } 
        else 
        {
                damage = (int)me->query_skill("stick",1) / 10 +
        (int)me->query("sen") / 300 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 300 + random((int)me->query("kee") / 200 );
                msg += HIY "天魔一击顿时从$n的胸口直贯而过，$n的胸口顿时血流如注，大呼"+HIW"天既如此，我耐如何"+HIR"，$n现在已是风中残烛，命在旦夕！\n" NOR;
                damage +=random(50);
                target->receive_damage("sen", me->query("eff_sen")*damage/70, me, "pfm");
                target->receive_damage("kee", me->query("eff_kee")*damage/70, me, "pfm");
                me->improve_skill("dali-bang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        if( !target->is_fighting(me) ) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(2);
        return 1;
}


