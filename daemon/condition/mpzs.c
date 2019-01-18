// [1;31m此文件禁止随意更改任何设置[0m
// Created by waiwai@2001/02/18
// 门派追杀"毒"文件

#include <ansi.h>

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int ratio;
	string mp;
	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

	mp = me->query("ZSmenpai");

	// 追杀限时三个小时
	if( me->query("vendettaFT") && time() - me->query("vendettaFT") > 10800 ){
		message("channel:rumor",
		HIY"【门派追杀】"HIR+log_id(me)+"被门派"HIW"「"+mp+"」"HIR"追杀因超时而被废止！\n"NOR,users());
		me->clear_condition("mpzs");
		me->remove_all_killer();
		me->delete("vendettaFT");
		me->delete("vendetta/"+mp);
		me->save();
	 	return 1;
	}

	if( !me->query("vendettaFT") || !userp(me) ) return 0;

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");

    	if (ratio > 0) 
		tell_object(me, "你觉得心中发虚，感觉到似乎正被门派"+mp+"追杀。。。\n");

	me->receive_damage("kee", duration/10);
	me->receive_damage("sen", duration/10);

//	me->apply_condition("mpzs", duration - 1);

	me->set_temp("death_msg",HIW"被门派"+mp+"追杀魂魄吓破而死。。。\n"NOR);

	if( !duration ) return 0;

	return CND_CONTINUE;
}

