#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(CYN"水晶项链"NOR, ({"shuijing xianglian","necklace","xianglian" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("no_zm",1);
                set("no_give",1);
                set("material", "pearl");
set("value", 10000);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_put",1);
                set("armor_prop/armor", 50);
        }
        setup();
}

