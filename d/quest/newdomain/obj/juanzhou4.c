#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("探险卷轴", ({ "juan zhou 4","zhou" }) );
        set_weight(10);
                set("unit", "只");
                set("material", "paper");
                set("jz_mark",4);
                set("long", "这件物品和别的物品合在一起可以得到进入另一个世界的通行证。\n");
        setup();
}
