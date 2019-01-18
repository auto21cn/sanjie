
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "冰淇淋" NOR , ({"ice cream", "ice"}));

  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");

    set("long", "一个刚从美国冰淇淋专卖店买回来的冰淇淋，上面有六色雪球。\n");

    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="ice" && arg!="ice cream") return 0;

  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", 2*(int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", 2*(int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", 3*(int)me->query("max_kee"));
  me->set("mana", 2*(int)me->query("max_mana"));
  me->set("force", 2*(int)me->query("max_force"));
  me->set("food", 2*(int)me->max_food_capacity());
  me->set("water", 2*(int)me->max_water_capacity());
//  me->add("daoxing",20000)
//  me->add("potential",2000);

  message_vision(HIC "$N一口一口舔着冰淇淋，露出天真的笑容酩着嘴唇。

只见$N脸上慢慢泛出青光，看起来有爽多了！\n" NOR, me);

  destruct(this_object());
  return 1;
}

