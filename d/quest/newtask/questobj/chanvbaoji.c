#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【姹女神功宝籍】", ({ "chanv baoji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武功秘籍。江湖女侠翻江龙女展鸾英一身功夫极为复杂，包括武林正邪两道不少秘功神技。她数十年苦练研修成一种神妙招式，仿华山正宗《三光神功宝籍》著成此书。\n");
          }

    setup();
}
