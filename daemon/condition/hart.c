// Update by waiwai@2001/02/18

#include <ansi.h>

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 || wizardp(me) ) return 0;

	if( duration >= 1 ) {
        tell_object( me , HIY "你中了精灵之舞,只觉得全身经脉好像移位般,十分痛苦！！！\n" NOR);

	message("vision", 
	me->name(1) + "[1;37m身上的精灵之舞暗伤发作,整个人屈在地上表现出极为痛苦的表情！！！[0m \n",
	environment(me), me);

	if(me->is_fighting()) me->start_busy(1);

        me->add("kee",-150);
        me->add("sen",-150);
        me->add("force",-150);

       if( me->query("force") < 0 ) me->set("force",0);
	me->set_temp("death_msg",HIG"精灵之舞毒伤发作而死。。。\n"NOR);
//	me->set("killbyname","精灵之舞毒伤发作而死\n"NOR);

        me->apply_condition("hart",duration -1);
        COMBAT_D->report_status(me, 1);
	}
	return 1;
}
