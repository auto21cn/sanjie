#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("乌金血剑", ({ "wujin jian" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                       set("material", "iron");
 set("long", "武林后起之秀风亦飞所持神剑，精于冶炼之术的兵甲派历代相传。\n");
                       }
        init_sword(15);
        setup();
}
