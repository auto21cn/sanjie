//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIG "稀世翡翠" NOR, ({ "flawless jade" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIG "一块美得无与伦比的大翡翠。\n" NOR);
                set("value", 100000);
		    set("unit", "块");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "cold");
                set("magic/power", 125);
	}
        setup();
}
