//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIG"砸玻璃石头", ({"shi tou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块棒棒冰专门用来砸玻璃的石头。\n");
                set("unit", "块");
               set("owner_name","小流氓");
                set("owner_id","xiao liumang");
        }
}

