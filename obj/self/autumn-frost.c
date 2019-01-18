// Created by aeddy@2001/03/23
// 晶莹霜华(autumn-frost)
// [1;31m此文件禁止更改和移动[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "晶莹霜华" NOR, ({ "autumn frost", "frost" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒晶莹的晶莹霜华，只有在深秋晴朗的凌晨才见得到的精灵。\n");
		set("value", 100);
		set("can_auction", 1); // 可合并标志
		set("des", 1); // drop时消失标志
		set("material", "ice");//冰水性物件标志
    };
	// drop时的特定输出信息
	set_temp("drop_msg", this_object()->query("name")+CYN" 随风而逝，消失在空气中不见了～～～\n"NOR);

	setup();
}

