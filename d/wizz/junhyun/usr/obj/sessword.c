//神之权杖
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "神之权杖" NOR, ({ "sessword", "jian"}) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
                set("material", "iron");
                set("long", "天神的权杖，掌管万物的一切。\n");
                set("wield_msg","$N手中详光乍现，神之权杖隐隐出现。\n");
                set("unwield_msg", "祥光渐渐散去，$n消失的无影无踪。\n");
                                set("no_sell","你真厉害，敢买数码宝贝的权杖？嘿嘿……你完蛋了。\n");
                                set("no_drop","你要是把数码宝贝的权杖扔了，你的小命也就没了。\n");
                                set("no_give","不是吧？着你也敢送人？你真是不要命了。\n");
                }
        init_sword(120);
        setup();
}

