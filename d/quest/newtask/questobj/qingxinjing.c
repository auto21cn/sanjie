#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"清心镜"NOR, ({ "qingxin jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "面");
            set("long", "一面清心镜\n");
          }

    setup();
}
