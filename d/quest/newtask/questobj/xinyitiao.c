#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("心一跳", ({ "xin yitiao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "瓶");
            set("long", "一瓶心一跳\n");
          }

    setup();
}
