#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ǧ����", ({ "qiandu gui" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("long", "һֻǧ����\n");
          }

    setup();
}
