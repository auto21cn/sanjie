// 五域奇盔 by Calvin

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
  set_name(MAG"紫冰盔"NOR, ({ "zibing kui", "tou kui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","乌亚子最喜欢戴的一顶奇特的帽子,样子并不是很美观。\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
set("value", 6000);
                set("no_sell", "这种罕见的神兵可不是随便可以买卖的!\n");
    set("material", "cloth");
                set("armor_prop/armor", 60);
    set("armor_prop/personality", 5);
  }
  setup();
}
