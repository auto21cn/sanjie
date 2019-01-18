//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "回眸一笑" NOR, ({ "sword", "jian"}) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
                set("material", "iron");
                set("long", "这是一把剑身细长的宝剑，隐隐的放射出寒冷的光芒。\n");
                set("wield_msg","随着一声清啸，回眸一笑已跃入$N的手中。\n");
                set("unwield_msg", "隐隐寒光渐渐散去，回眸一笑轻灵的跃回剑鞘。\n");
                                set("no_sell","你真厉害，敢买梅的宝剑？嘿嘿……你完蛋了。\n");
                                set("no_drop","你要是把梅的宝剑扔了，你的小命也就没了。\n");
                                set("no_give","不是吧？着你也敢送人？你真是不要命了。\n");
                }
        init_sword(120);
        setup();
}

