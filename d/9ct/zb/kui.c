// 五域奇盔 by Calvin

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
  set_name(MAG"破仙魔盔"NOR, ({ "poxian mokui", "mokui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","乌亚子最喜欢戴的一顶奇特的帽子,样子并不是很美观。\n");
             set("value", 6000);
    set("material", "cloth");
    set("armor_prop/armor", 40);
    set("armor_prop/personality", 15);
  }
  setup();
}
