// 逸仙洛寒叉 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
        set_name(HIC"逸仙叉"NOR, ({ "yixian cha", "yixian fork","fork","cha" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 200000);
                set("no_sell", "这种罕见的神兵可不是随便可以买卖的!\n");
                set("material", "iron");
                set("long", "这是一把来自逸仙天的奇特神兵。\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
        }
 init_fork(200);
        setup();
}

