#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【棋谱】", ({ "qi pu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武籍。武林盟主的信物之一，同黑白旗一起代代相传。\n");
          }

    setup();
}
