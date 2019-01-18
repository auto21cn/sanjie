// 七绝披风 by Calvin

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIC"七绝披风"NOR, ({"qijue pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "相传这件亮色的披风是精华台出的第一件宝物。\n");
    set("material", "leather");
    set("unit", "件");
             set("value", 12000);
    set("armor_prop/armor", 50);
    set("armor_prop/spells", 20);
    set ("armor_prop/force", 20);
    set("armor_prop/parry", 50);
  }
  setup();
}
