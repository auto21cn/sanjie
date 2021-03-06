#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
        int damage,damagea,extra,exp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「超生渡化」？\n");
                if (!PFM_D->valid_family(me, "南海普陀山"))
                return notify_fail("[超生渡化]是南海普陀山不传之密！\n");
                if(!me->is_fighting())
                return notify_fail("「超生渡化」只能在战斗中使用！\n");
                if((int)me->query("max_force") < 400 )
                return notify_fail("你的内力不够！\n");
                if((int)me->query("force") < 400 )
                return notify_fail("你的内力不足！\n");

                if((int)me->query("sen") < 150 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                if((int)me->query_skill("buddhism", 1) < 160)
                return notify_fail("你的大乘佛法不够娴熟，使用这一招会有困难！\n");                
                if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("你的轮回杖法不够熟练，使用这一招会有困难！\n");
              
                if (me->query_skill_mapped("spells")!="buddhism")
                return notify_fail("「超生渡化」必须配合大乘佛法才能使用。\n");

                me->delete("env/brief_message");
                target->delete("env/brief_message");

        exp = (int)me->query("combat_exp"); 
            extra=(int)me->query_skill("lunhui-zhang");
            damagea=random((int)me->query_skill("lunhui-zhang"));
              message_vision(HIR"\n$N缓缓说道:佛曰：“以暴止暴，以杀止杀!”我今天就大开杀戒，代表佛祖来惩罚你们这些顽恶之徒！\n"NOR,me,target);
if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
{
              target->receive_damage("kee",damagea,me,"pfm");
              target->receive_wound("kee",damagea/2,me,"pfm");
              target->receive_damage("sen",damagea/3,me,"pfm");
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
                me->add_temp("apply/attack", extra*3); 
                me->add_temp("apply/damage", extra*3); 
                me->add("combat_exp", exp);  
                message_vision(HIY"\n天理循环，报应不爽！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n天网恢恢，疏而不漏！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n放下屠刀，立地成佛！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                me->add_temp("apply/attack", -extra*3); 
                me->add_temp("apply/damage", -extra*3); 
                me->add("combat_exp", -exp);  
               damage=(int)me->query_skill("staff")+random((int)me->query_skill("buddhism"));
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIC"\n$n在$N的超度之下，好象已经到了极乐世界．．．．\n"NOR,me,target);
              message_vision(HIC"\n$n呆呆的立在那里，不知所措。\n"NOR,me,target);
              target->receive_damage("kee",damage*2/3,me,"pfm");
              target->receive_wound("kee",damage/2,me,"pfm");
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
              me->receive_damage("sen", 30);
              me->add("force", -100);
              me->start_busy(2);
return 1;
}

