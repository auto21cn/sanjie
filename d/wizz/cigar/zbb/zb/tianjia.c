
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(CYN"黑木甲"NOR, ({"heimu armor","hei jia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "木提子的一件宝甲,此甲通体乌黑。\n");
                set("material", "steel");
             set("value", 0);
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", -30);
                set("armor_prop/force", 40);
        }
        setup();
}
