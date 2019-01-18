//Created by waiwai@2001/03/23
//夏之甘霖(springA-rain)
// [1;31m此文件禁止更改和移动[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "夏之甘霖" NOR, ({ "summerA rain", "summerA", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("long", "这是一滴晶莹的夏之甘霖的雨滴。\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // drop时消失标志
		set("material", "water");//水性物件标志
    };
	// drop时的特定输出信息
	set_temp("drop_msg", this_object()->query("name")+CYN" 随风而逝，消失在空气中不见了～～～\n"NOR);

	setup();
}

