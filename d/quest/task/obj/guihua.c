//By waiwai@mszj 2000/12/02

#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIC"规划图"NOR, ({"guihua tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一张桃花村的规划图。\n");
                set("unit", "张");
                set("owner_name","吴文");
                set("owner_id","wu wen");
        }
}

