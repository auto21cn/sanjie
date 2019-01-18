
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
 //   set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "金宝宝的虎骨丹" NOR , ({"shengri dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗金黄色的金宝宝的虎骨丹丹丸，略微能闻到些许香气。\n");
    set("value",20000);

    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
if ( (int)me->query("shengao" )>3) return notify_fail ( "拿了就再别贪心了!\n");

  if (arg!="dan") return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", 2*(int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", 2*(int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", 2*(int)me->query("max_kee"));
  me->set("mana", 2*(int)me->query("max_mana"));
  me->set("force", 2*(int)me->query("max_force"));
  me->set("food", 2*(int)me->max_food_capacity());
  me->set("water", 2*(int)me->max_water_capacity());
//  me->add("daoxing",20000);
me->set("shengao",4);

  me->add("potential",25000);

me->add("combat_exp",50000);
  message_vision(HIG "$N轻轻掰开一颗金宝宝的虎骨丹送入嘴中，一时间香气四溢。
只见$N脸上慢慢泛出红晕，看起来有精神多了！\n" NOR, me);
  destruct(this_object());
  return 1;
}

