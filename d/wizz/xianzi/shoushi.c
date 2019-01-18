#include <ansi.h>
inherit F_AUTOLOAD;  
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIG "翡翠珠花" NOR , ({ "zhu hua", "hua", "fei cui" }) );

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", HIG"一支翡翠精雕而成的珠花，碧绿得仿佛是盛夏的原野。\n"NOR);

                set("material", "steel");
                set("value", 400);
                set("no_sell", 1);
                set("no_drop", 1);
                set("monitord", 1);
       if(!wizardp(this_player())) set("no_give", 1);

                set("no_get", 1);

                set("armor_prop/armor", 20);
//                set("armor_prop/intelligence", 10);
                set("armor_prop/intelligence", 15);
                set("armor_prop/personality", 25);

        }
        setup();
}

int query_autoload() { return 1; }
