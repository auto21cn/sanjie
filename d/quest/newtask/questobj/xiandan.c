#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("无极仙丹", ({ "wuji xiandan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "枚");
            set("long", "一枚无极仙丹\n");
          }

    setup();
}
