// player装备
//

#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create()
{
        set_name(HIM"依依"NOR, ({ "qiao", "yaodai" }) );
        set("long", "娃娃的好朋友。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

