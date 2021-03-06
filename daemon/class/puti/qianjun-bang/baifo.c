#include <ansi.h>
inherit SSERVER;

string get_name(string str)
{
        str="拜佛五式";
        return str;
}

string get_help(string str)                
{
        str="指令: ｐｅｒｆｏｒｍ　ｂａｉｆｏ\n"
        +"条件：千钧棒法大于120级，最大内力大于1200，每用一次消耗100精神和200内力，"
        +"迅速向对方攻击五招，攻击力能让鬼神无一幸免。";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「拜佛五式」？\n");
        if(!me->is_fighting())
                return notify_fail("「拜佛五式」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 1200 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("sen") < 600 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("qianjun-bang", 1) < 120)
                return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");
        if (!PFM_D->valid_family(me, "方寸山三星洞"))
                return notify_fail("拜佛五式是方寸山三星洞的不传之秘，外人哪里能够领悟。\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_combatd(HIC"\n$N运足精神，身形一转使出灵台绝学"HIW"「拜佛五式」"NOR+HIC"连续向$n攻出了五招！\n"NOR,me,target,"");
        extra=(int)me->query_skill("qianjun-bang", 1);

        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra); 

        if(!target->is_busy())
                target->start_busy(1);
        
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);

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



