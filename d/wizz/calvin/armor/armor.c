// 皇甲.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("皇甲", ({"king armor","kingjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "无数宝石织就的宝甲\n");
                set("material", "steel");
                set("value", 20000);
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", -50);
        }
        setup();
}
