//村正
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "妖刀·村正" NOR, ({ "cunzheng", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "刀，刃长73.32CM。室町末期刀工势州村正所作，斩切能力出\n类拔萃，被德川家视为“不吉”的象征，斥之为“妖刀村正”，因\n而在幕末时的长州倒幕派中人气极高。刀铭：村正\n");
                set("wield_msg","$N从腰间抽出一柄剑，划出一个弧形，一股剑气扑面袭来\n");
                set("unwield_msg", "$N将$n收回腰间，长长的出了口气。\n");
                                set("no_sell",1);
                                set("no_get","好孩子是不会随便拿别人的东西的哦。\n");
                }
        init_sword(200);
        setup();
}

