// bingshen.c 冰参  
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;  

void create() 
{
        set_name("冰参",({"bing shen"}));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("no_drop",1);
                set("no_put",1);
                set("long", "这是医师制作药材的原料。\n");
        }
        setup();
}

