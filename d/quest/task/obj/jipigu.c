//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
        set_name(HIR"鸡屁股"NOR, ({"jipi gu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个鸡屁股。\n");
                set("unit", "个");
                 set("owner_name","瘦子");
                set("owner_id","shou zi");
        }
}

