//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIM "水晶" NOR, ({ "crystal" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIM "一块粉色的水晶。\n" NOR);
                set("value", 50000);
		    set("unit", "块");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "magic");
                set("magic/power", 100);
	}
        setup();
}
