// 千紫回天斧 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(MAG"千紫回天斧"NOR, ({"qianzi axe", "fu", "axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                      "这把来自千紫天的大斧头虽不说神兵盖世,可一算得一方法宝。n");
     set("value", 15000);
                set("material", "iron");
                set("wield_msg",
                           "$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

   init_axe(110);
        setup();
}

