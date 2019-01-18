//sea.c player装备
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit ARMOR;


void create()
{
        set_name(HIW"神之光"NOR, ({ "godarmor", "armor" }) );
        set("long", "散发着神之光辉的铠甲。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

