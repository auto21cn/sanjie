//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIR "稀世玛瑙" NOR, ({ "flawless agate" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "一块光彩照人的大玛瑙，美仑"
                            "美奂，世所罕有。\n" NOR);
                set("value", 100000);
		set("unit", "块");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "fire");
                set("magic/power", 125);
                set("armor_prop/per", 7);
	}
        setup();
}

