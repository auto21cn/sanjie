#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"千日醉兰"NOR, ({ "qianri zuilan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "只");
            set("long", "一只千日醉兰\n");
          }

    setup();
}
