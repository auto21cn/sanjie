#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【怜花宝鉴】", ({ "lianhua baojian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武林高手王怜花所著武功心法，还包括下毒术、易容术、苗人放蛊术、波斯慑心术等，内容广泛。\n");
          }

    setup();
}
