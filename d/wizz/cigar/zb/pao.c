// 三界神袍 by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIG"碧洛袍"NOR, ({"biluo shenpao", "cloth","pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件如来赠送给木惠的护身神袍。\n");
    set("material", "cloth");
    set("unit", "件");
set("value", 10000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
                set("armor_prop/armor", 80);
               set("armor_prop/dodge", 20);
    set("armor_prop/spells", 50);
    set ("armor_prop/force",-50);
    set("armor_prop/parry", -50);
  }
  setup();
}
