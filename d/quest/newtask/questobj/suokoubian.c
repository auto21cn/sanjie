#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIY"金丝锁口鞭"NOR, ({ "jinsi bian" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                       set("material", "gold");
 set("long", "秦中三鸟领袖追风铁翅雕侯天惠使用的一种纵横江湖所向无敌的独门兵刃。\n");
                  }
        init_whip(15);
        setup();
}
