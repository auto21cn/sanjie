#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("黑白旗", ({ "heibaiqi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "面");
            set("material", "paper");
            set("long", "武林中用来发号施令的令旗。\n");
          }

    setup();
}
