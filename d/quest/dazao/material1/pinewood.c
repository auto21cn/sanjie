//pinewood.c 打造武器材料--松木
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name(HIG"松木"NOR,({"pine wood", "wood"}));
        set_weight(20000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                set("long", "这是一根松木。\n");
        }
        setup();
}

