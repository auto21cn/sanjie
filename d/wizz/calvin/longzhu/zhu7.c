// 龙珠 by Calvin
// 2001.6

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "龙珠" NOR, ({ "long zhu","zhu" }));
        set_weight(2000);
        set("long", "这是一个漂亮的小石头球,上面刻着|☆☆☆☆☆☆☆|,据说当把收集到的七颗龙珠放在一起时会出现 ...\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "stone");
                set("value", 200);
                set("no_sell", 1);
                set("amount",30);
        }
        setup();
}
