//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>

#include <task.h>
void create()
{
        set_name(HIW"乌凤锏"NOR, ({"wufeng jian", "jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "玉面公主最喜欢用首饰。\n");
                set("unit", "个");
               set("owner_name","玉面公主");
               set("owner_id","yumian gongzhu");
        }
}

