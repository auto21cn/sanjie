//神杖·幻空（junhyun专用）
//by junhyun@SK
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIW"神杖·幻空"NOR, ({ "shen zhang","zhang","staff" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 200000);
                set("no_sell", "这种罕见的神兵可不是随便可以买卖的!\n");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "wood");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("long", HIC"魔导八杰集之一：神杖·幻空\n"NOR);
                set("wield_msg", HIY"$N单手一挥，手中以多了一柄神光四射的神杖！\n");
        //      set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
   init_blade(200);
        setup();
}

