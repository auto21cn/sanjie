#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("金蚕蛊毒", ({ "jincan gudu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "些");
            set("long", "一些金蚕蛊毒\n");
          }

    setup();
}
