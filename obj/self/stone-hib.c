//Last modified by waiwai@2001/03/23

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB "蓝色神石" NOR, ({ "blue stone", "stone" }) );
	set_weight( 10000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块蓝色的神石，里面含有一些稀有的物质。\n");
		set("value", 100);
		set("can_auction", 1);
    };
}

