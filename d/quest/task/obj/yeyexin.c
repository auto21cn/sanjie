//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIC"定海神针铁"NOR, ({"aoguang ring","ring"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个定江海浅深的一个定子。\n");
                set("unit", "个");
               set("owner_name","敖广");
               set("owner_id","ao guang");
        }
}

