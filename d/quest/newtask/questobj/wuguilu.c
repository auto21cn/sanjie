#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【舞鬼录】", ({ "wuguilu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武籍。由九人合研而成，主要人物有三：波斯传教士马斯、扶桑（日本）长门大开，中国的大旗和尚。\n");
          }

    setup();
}
