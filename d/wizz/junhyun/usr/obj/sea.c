//sea.c player装备
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit FINGER;


void create()
{
        set_name(HIW"流云"NOR, ({ "sea", "ring" }) );
        set("long", "这是梅的相公送给她的定情信物，是梅最最心爱的随身物品。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

