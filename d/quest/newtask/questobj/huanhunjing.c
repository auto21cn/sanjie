#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【地狱换魂经】", ({ "huanhun jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "地狱门的一种邪术经书，其中有“换魂”一节。\n");
          }

    setup();
}
