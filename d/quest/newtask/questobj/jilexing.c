#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("极乐之星", ({ "jile xing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "颗");
            set("long", "一颗极乐之星\n");
          }

    setup();
}
