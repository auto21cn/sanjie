// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"绣"HIM"花"HIW"小肚兜"NOR, ({"du dou", "dou", "cloth" }) );
        set("long", HIW"一件很别致的小肚兜，上面还绣着一朵"HIR"盛开的牡丹。\n"NOR);
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);

	}
	setup();
}

