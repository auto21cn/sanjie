// 龟仙神斧 by Cigar

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIW"龟仙神斧"NOR, ({"guixian axe", "fu", "axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                      "此斧是龟仙岛主人专用,是把神斧。n");
                set("value", 30000);
                 set("material", "gold");
                set("wield_msg",
                           "$N拿出一把$n握在手中，眼前闪过一道寒光，日月为之暗色。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

   init_axe(120);
        setup();
}

