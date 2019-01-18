// 八部龙腕 by Calvin

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

string *names = ({HIM"麒麟腕"NOR,});

string *ids = ({
   "qilin wan" 
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "qilin wan", "wan", "wrists"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "对");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
set("value", 6000);
   set("material", "metal");
                set("armor_prop/armor", 50);
   set("armor_prop/force", 100);
  }
   set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
  setup();
}
