#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("晶瓶美人壁", ({ "meiren bi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "只");
            set("long", "一只晶瓶美人壁\n");
          }

    setup();
}
