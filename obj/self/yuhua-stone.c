//Created by waiwai@2002/12/05
//343种随机颜色组合，配合NAME2_D

#include <ansi.h>

inherit ITEM;

void create()
{
	mapping name;
	
	name=NAME2_D->random_name("yuhua");
	set_name(name["name"], name["id"]);

	set_weight(500);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("long", "一粒色彩斑斓的小石子，每一粒都似乎在讲述着一个故事。\n");
	set("unit", "粒");
	set("value", 2000);
//	set("no_sell", 1);
	}
}

