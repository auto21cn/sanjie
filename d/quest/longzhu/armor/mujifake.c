// 木屐(替代) by Cigar

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
 set_name(HIY"木屐"NOR, ({ "mu ji","shoes", "xie" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
    set("long", CYN"这是特兰克斯的靴子，听说是用龙珠的神秘力制作的。\n"NOR);
                set("value", 0);
    set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
  set("fake", 1);
    set("material", "boots");
      set("armor_prop/armor", 20);
    set("armor_prop/dodge", 20);
  }
  setup();
}
