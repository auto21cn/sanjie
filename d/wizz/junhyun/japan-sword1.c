//菊一文字·则宗
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "菊一文字·则宗" NOR, ({ "juyiwenzi zezong", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "太刀，刃长78.48CM。后鸟羽院时期备前国刀工则宗所
作，一文字派的代表作品。传说后来为新撰组剑士冲田总司所有。\n");
                set("wield_msg","$N从腰间抽出一柄剑，划出一个弧形，一股剑气扑面袭来\n");
                set("unwield_msg", "$N将$n收回腰间，长长的出了口气。\n");
                                set("no_sell",1);
                                set("no_get","好孩子是不会随便拿别人的东西的哦。\n");
                }
        init_sword(200);
        setup();
}

