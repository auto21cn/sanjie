//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIC"鸡骨头"NOR, ({"ji gutou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "啃得精光的鸡骨头。\n");
                set("unit", "块");
                set("owner_name","瘦老头");
                set("owner_id","lao tou");
        }
}

