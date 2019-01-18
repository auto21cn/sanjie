// 阴阳戒指 by Calvin

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(RED"阴"+BLU"阳"+CYN"戒指"NOR, ({ "yinyang jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
set("value", 10000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
                set("material", "gold");
   set("armor_prop/armor", 40);
                set("armor_prop/spells", 100);
        }
        setup();
}       
