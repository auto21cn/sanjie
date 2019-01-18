// axe.c

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>

void create()
{
        set_name(HIR"神斧"NOR, ({"shen fu", "fu", "axe"}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
WHT"一把黑漆漆的斧子，据说可以开天辟地，不过没有人知道具体该如何用它！\n"NOR);
                set("value", 0);
                set("material", "iron");
                set("no_drop", "这样东西不能随意丢弃！\n");
                set("no_give", HIR"神斧"NOR+"能随意给人？ \n");
                set("no_get", "你什么东西都捡？捡垃圾的都没你勤快！ \n");
                set("no_put",1);
        }

        setup();
}

