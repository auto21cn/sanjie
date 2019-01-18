// 护心镜 by Calvin

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string *names = ({
  HIY"明镜"NOR,
});

string *ids = ({
  "ming jing",
  "ming jing",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "ming jing", "jing", "ming"}));
  set_weight(5000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
             set("value", 10000);
                
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
   set("material", "metal");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", 30);
  }
    set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
  setup();
}
