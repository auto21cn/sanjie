//By waiwai@mszj 2000/12/02

#include <ansi.h>
inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIW"冰袋"NOR, ({"bing dai" ,"dai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "一个用来装冰块的袋子。\n");
                set("unit", "件");
                              set("owner_name","大鹏明王");
                            set("owner_id","dapeng mingwang");
        }
}


