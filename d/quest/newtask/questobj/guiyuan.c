#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【归元秘籍】", ({ "guiyuan miji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "一部令宋元年间武林中人舍命相寻、浴血相搏的武学奇书，为天机真人和三音神尼所著。\n");
          }

    setup();
}
