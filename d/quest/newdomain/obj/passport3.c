#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"三级通行证"NOR, ({ "passport III","passport" }) );
        set_weight(100);
                set("unit", "张");
                set("material", "paper");
                set("pass_level",3);
                set("long", "这是一张进入奇幻世界探密的通行证。\n");
        setup();
}
