//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIW "精美钻石" NOR, ({ "flawless diamond" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "一颗精光闪闪的精美钻石，华丽异常。\n" NOR);
                set("value", 100000);
		    set("unit", "颗");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "lighting");
                set("magic/power", 125);
	}
        setup();
}

