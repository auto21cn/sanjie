//魔导机甲
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW"魔导机甲"NOR, ({"magic armor","armor", "jia"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件接受过光明女神缇雅祈祷的机械战甲。\n");
                set("material", "steel");
set("value", 20000);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
                set("armor_prop/armor", 90);
               set("armor_prop/dodge", -20);
               set("armor_prop/spells", 70);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("armor_prop/force", 100);
        }
        setup();
}

