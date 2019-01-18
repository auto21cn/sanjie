// /obj/misc/ling.c
// Written by Mudring@SanJie

#include <ansi.h>

inherit ITEM;
inherit PARTY;

string query_autoload() { return "1"; }

void create()
{
    set_name(HIR "帮会令牌" NOR, ({ "party ling", "ling" }));
    set_weight(10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
这是一只帮派令牌，它代表着帮派的权利和荣誉。
LONG );
        set("unit", "把");
        set("no_pawn", 1);
        set("no_sell", 1);
        set("no_copy", 1);
        set("item_make", 1);
        set("value", 1);
    }
}