//Created by waiwai@2001/03/23
//冬之雪雨(winter-rain)
// [1;31m此文件禁止更改和移动[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "冬之雪雨" NOR, ({ "winter rain", "winter", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("long", "这是一滴晶莹的冬之雪雨的雨滴。\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // drop时消失标志
		set("material", "water");//水性物件标志
	};
	// drop时的特定输出信息
	set_temp("drop_msg", this_object()->query("name")+CYN" 随风而逝，消失在空气中不见了～～～\n"NOR);

	setup();
}

