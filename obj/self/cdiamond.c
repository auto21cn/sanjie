//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIW "钻石碎粒" NOR, ({ "chipped diamond" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "一粒精光闪闪的如米粒般大小"
                    "的钻石碎粒。\n" NOR);
                set("value", 20000);
		    set("unit", "粒");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "lighting");
                set("magic/power", 50);
	}
        setup();
}
