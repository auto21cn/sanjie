//Created by waiwai@2001/04/25

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(WHT"桂花"NOR, ({ "gui hua","hua" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", WHT"一朵带着清香之气的浅白色的花朵！\n" NOR);
		set("base_unit", "朵");
              set("unit", "些");
		set("value", 1);
		set("no_sell",1);
		set("no_put",1);
	}
	set_amount(1);
	setup();
}
