// [1;31m此文件禁止随意更改任何设置[0m
// Created by waiwai@2001/02/18
// 魂魄精灵"毒"文件
// 相关文件：
// elfnpc.c logind.c set.c damage.c 
// combatd.c quit.c score.c

#include <allobj.h>

#include <condition.h>

inherit F_CLEAN_UP;
#define ELF		WAI_NPC"elfnpc"

int update_condition(object me, int duration)
{
	int ratio;
	string elf, owner;
	object where, startroom, ob;
	int i;
	object *ob_list;
	ob_list = children(ELF);

	where = environment(me);
	startroom = me->query("Sroom");
	owner = ob_list->query("owner");

	if( sizeof(filter_array(owner,(:clonep:)))<1) {
	if( base_name(where) == me->query("Sroom") && me->query("hunpo")) {
	tell_object(me, "你的魂魄精灵消失了。。。\n");
	me->clear_condition("makestart");
	}
	} //else return CND_CONTINUE;

	if( duration < 1 ){
		me->delete("hunpo");
	 	return 0;
	}

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");

    	if (ratio > 80) 
		tell_object(me, "你觉得头脑发晕，身子轻飘飘的。\n");
    	else if (ratio > 60) 
		tell_object(me, "你觉得脑袋又痛又涨，身子已不大听使唤了。\n");
    	else if (ratio > 40) 
		tell_object(me, "你觉得呼吸困难，眼前一切都模糊了起来。\n");
    	else 
		tell_object(me, "你昏昏欲睡，马上就要倒在地下了。\n");

	me->receive_wound("sen", 10);
	me->receive_wound("kee", 10);

	if (me->query("mana") < 0) me->set("mana", 0);
	me->set_temp("death_msg",HIW"魂魄精灵原神消散而死。。。\n"NOR);

	me->apply_condition("makestart", duration-10);  

	if( time()-me->set("nowstart")>1800 && me->query("hunpo")) {
	tell_object(me, "你的驻留禁止已被解除。。。\n");
	me->delete("hunpo");
	me->clear_condition("makestart");
 	return 0;
	}

	if( !duration ) return 0;

	return CND_CONTINUE;
}

