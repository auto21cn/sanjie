// blade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
#include "/std/weapon/newwwd.c"; 

void create()
{
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
                set("value", 100000);
		set("material", "iron");
                set("long", "这是宝宝闯地府用的鬼刀，充满一身鬼气，阴森森刀光逼人。\n");
                set("wield_msg", "$N抽出一把阴森森的$n握在手中，鬼笑一声，嘿！。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
}
        init_blade(105);
       updatename("blade"); 
        setup();
}
