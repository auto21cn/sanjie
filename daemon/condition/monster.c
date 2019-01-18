// CONDITION monster.c
// Update by waiwai@2000/12/20

#include <ansi.h>

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
	me->clear_condition("monster");
	me->set("name",me->query_temp("oname"));
	me->delete_temp("mark/ifzhao");
	message_vision(WHT"$N恢复了人形。。。\n"NOR, me);
	}
	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;
	me->apply_condition("monster", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "monster";
}
