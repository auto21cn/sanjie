/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Created by waiwai@2000/07/10 

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "好东西" NOR, ({ "plll dan","plll" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", WHT
      "这是传说中的有起死回生功效的 "HIR"好东西"+WHT" 只要你\n"
      "还有一口气在，无论任何病痛它都可以治！\n" NOR);

		set("base_unit", "颗");
              set("unit", "些");
              set("no_putin", 1);
		set("value", 80000);
		set("base_value", 80000);
	       set("drug_type", "补品");
	}
	set_amount(1);

	setup();
}

void init() { add_action("do_eat", "eat"); }

int do_eat(string arg)
{
	object me = this_player();
	if (arg!="plll" && arg!="plll dan")	return 0;

	//By waiwai@2001/07/15
	if( environment(me)->query("no_plll") ) 
		return notify_fail(WHT"想投机取巧是不行的！！！\n"NOR);  
  
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity());
	message_vision( HIR "$N的脸上由白变红，红的象要滴出血来，慢慢的红色又退了下去！！\n" NOR, me); 
	add_amount(-1);
	return 1;
}
