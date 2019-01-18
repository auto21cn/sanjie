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
                set("value", 200000);
                set("no_sell", "这种罕见的神兵可不是随便可以买卖的!\n");
              set("no_put",1);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
              set("no_zm",1);
              set("no_give",1);

		set("material", "iron");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("wield_msg", "$N抽出一柄天地动摇的$n握在手中。\n");
                set("long", WHT"上古十二神兵之一：轮回八卦刀n"NOR);
	}
        init_blade(210);
	setup();
}
