// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_weight(4000);
        set_name(HIW"八卦"+HIR"轮回"+HIB"刀"NOR, ({"lunhui dao", "dao","blade"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
             set("value", 0);

                set("material", "steel");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("wield_msg", "$N抽出一柄天地动摇的$n握在手中。\n");
              set("no_put",1);
                set("long", WHT"上古十二神兵之一：轮回八卦刀n"NOR);
	}
        init_blade(110);
	setup();
}
