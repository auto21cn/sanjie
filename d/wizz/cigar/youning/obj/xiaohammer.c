// xiaohammer.c 

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("小流星锤", ({ "xiao liuxing hammer", "xiaohammer" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一个小流星锤，是从大锤中化出之物。\n");
                set("material", "iron");
                set("wield_msg", "$N将小流星锤拿起来握在手中，还真顺手。\n");
                set("unwield_msg", "$N将手中的$n背在背上。\n");
        }
        init_hammer(100);
        setup();
}
