//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIM "稀世水晶" NOR, ({ "flawless crystal" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "一块光彩照人的大水晶，美仑"
                            "美奂，世所罕有。\n" NOR);
                set("value", 100000);
		    set("unit", "块");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "magic");
                set("magic/power", 125);
	}
        setup();
}

