//tong-kuang.c铜矿石
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;  
void create() 
{
        set_name(YEL"铜矿石"NOR,({"tong kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                set("no_put",1);
                set("long", "这是一块沉重的铜矿石。\n");
        }
        setup();
}

