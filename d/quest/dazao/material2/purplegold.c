//purplegold.c 打造武器材料--紫金
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name(MAG"紫金"NOR,({"purple gold", "metal"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                set("long", "这是一块紫金。\n");
        }
        setup();
}
