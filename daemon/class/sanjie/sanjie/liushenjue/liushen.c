// liushen.c 六神合一

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
                return notify_fail("你要对谁施展这一招「六神合一」？\n");

        if(!me->is_fighting())
                return notify_fail("「六神合一」只能在战斗中使用！\n");
		if(me->query("class")!="sanjie")
           return notify_fail("“六神合一”只有三界山门人才可以用！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("liushenjue", 1) < 100)
                return notify_fail("你的六神诀级别还不够，使用这一招会有困难！\n");

	me->delete("env/brief_message");

	message_vision(HIR"\n$N大喝一声“六神合一”！\n"NOR, me);


	me->set_temp("liushenjue_per", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete_temp("liushenjue_per");

	me->receive_damage("kee", 50);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(2);
	return 1;
}
