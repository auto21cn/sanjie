#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIC"青玉冰轮"NOR, ({ "qingyu binglun" }) );
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                       set("material", "iron");
 set("long", "昔年木道人用万年玉雕琢而成的奇门兵器。\n");
                       }
        setup();
}
