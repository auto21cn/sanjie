// tulong.c 天打雷辟屠真龙

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天打雷辟屠真龙」？\n");
		if(me->query("class") != "sanjie" )
                return notify_fail("”天打雷辟屠真龙“只有三界山门人才可以用！\n");

        if(!me->is_fighting())
                return notify_fail("「天打雷辟屠真龙」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("zileidao", 1) < 200)
                return notify_fail("你的天打雷辟屠真龙级别还不够，使用这一招会有困难！\n");

  if (me->query_temp("sanjie_pfm_busy")) return notify_fail("绝招用的太多太滥就不灵了。\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N运足精神，身形一转，霹雳间连续向$n攻出了七招！\n"NOR,me,target);

            target->start_busy(1);
        message_vision(HIC"\n$N第一招——春雷暴极！"NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIC"\n$N第二招——沉雷地狱！"NOR,me,target);
        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIC"\n$N第三招——天旋雷轰！"NOR,me,target);
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第四招——冬雷霹雳！"NOR,me,target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第五招——狂雷震九宵！"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第六招——惊雷爆五岳！"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第七招——怒雷撕天裂地！"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }


  me->set_temp("sanjie_pfm_busy",1);
  me->set_temp("no_move",1);
  call_out("remove_no_move",3,me);
        call_out("remove_effect",3,me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("sanjie_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
