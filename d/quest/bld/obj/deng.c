// deng.c

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>

void create()
{
        set_name(HIY"宝莲灯"NOR, ({"baolian deng", "deng"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盏");
                set("long",
HIR"一盏晶莹剔透的灯，当他被点燃的时候会发出万道光芒，使人具有无穷的力量！\n"NOR);
                set("value", 0);
                set("material", "crystal");
                set("no_drop", "这样东西不能随意丢弃！\n");
                set("no_give", "自己留着吧！ \n");
                set("no_get", "你什么东西都捡？捡垃圾的都没你勤快！ \n");
                set("no_put",1);
        }

        setup();
}

