// 神龙仙袍 by Calvin

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIB"神龙仙袍"NOR, ({"xian pao", "cloth","pao"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", HIB"天界的神龙专用仙袍。\n"NOR);
    set("material", "cloth");
    set("unit", "件");
    set("value", 100000);
                set("no_give", 1);
                set("no_drop", 1);
  set("fake", 1);
  set("unique", 1);
                set("no_put", 1);
                set("name_recognized", "神龙仙袍");
                set("is_monitored", 1);
    set("armor_prop/armor", 20);
    set("armor_prop/rake", 50);
    set("armor_prop/stick", 50);
    set("armor_prop/literate", -200);
    set("armor_prop/fork", 50);
    set("armor_prop/unarmed", -100);
    set("armor_prop/sword", 50);
    set("armor_prop/spear", 50);
    set("armor_prop/whip", 50);
    set("armor_prop/throwing", 50);
    set("armor_prop/dodge", -100);
    set("armor_prop/blade", 50);
    set("armor_prop/spells", -100);
    set ("armor_prop/force", -100);
    set("armor_prop/parry", 20);
  }
  setup();
}
