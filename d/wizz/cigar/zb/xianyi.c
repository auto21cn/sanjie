#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"飞舞神衣"NOR, ({ "shenyi", "cloth" }) );
        set("long","一件飞舞在大闹天宫所穿的神衣。");
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2000);
                set("material", "cloth");
                set("armor_prop/spells", 60);
                set("armor_prop/dodge", 60);
                set("armor_prop/armor", 90);
        }
        setup();
}

