#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【毒经】", ({ "du jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "武林奇人毒君金一鹏所著，被当时奇侠辛捷得到后，又悟出许多施毒妙方附在后面，使《毒经》更加丰富。\n");
          }

    setup();
}
