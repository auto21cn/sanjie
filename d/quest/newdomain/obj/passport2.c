#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"二级通行证"NOR, ({ "passport II","passport" }) );
        set_weight(100);
                set("unit", "张");
                set("material", "paper");
                set("pass_level",2);
                set("long", "这是一张进入魔幻世界的通行证。\n");
        setup();
}
