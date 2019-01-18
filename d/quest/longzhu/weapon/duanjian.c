// 段剑 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name(HIB"断剑"NOR, ({ "duan sword", "jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("is_monitored", 1);
                set("unit", "把");
                set("no_give", 1);
                set("no_drop", 1);
        set("replace_file", "/d/quest/longzhu/weapon/duanjianfake.c");
  set("unique", 1);
                set("name_recognized", "断剑");
                set("no_put", 1);
                set("value", 10000);
               set("no_sell", "卖?别逗了,这种罕见的东西可以买卖吗!\n");
                set("material", "steel");
                set("long", "这是一把只有一半剑身的断剑。\n");
                set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(200);
        setup();
}

