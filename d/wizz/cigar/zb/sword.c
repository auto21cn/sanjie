// 古冥神剑 by Calvin

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIR"古冥"+HIW"神剑"NOR, ({ "guming sword", "guming", "sword","shenjian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 200000);
                set("no_sell", "这种罕见的神兵可不是随便可以买卖的!\n");
                set("material", "steel");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("long", "这是一把来自九重天界的神兵,其身乌黑,锋利无比。\n");
                set("wield_msg", "一道白光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
 init_sword(200);
        setup();
}
