#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"玫瑰花"NOR, ({ "meigui hua" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "只");
            set("long", "一只玫瑰花\n");
          }

    setup();
}
