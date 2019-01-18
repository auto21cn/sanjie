//结婚喜糖
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIR"结婚喜糖"NOR , ({"xi tang","tang"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", HIG"这是一颗浓浓的水果香味的喜糖，是"HIW"静静的等待你"+HIC"和"+HIW"小娃娃"+HIG"的结婚喜糖。\n"NOR);
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out ("becoming_old",1800);
}
void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object dan = new (__DIR__"tang");

  dan->move(where);
  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xi tang" && arg!="tang") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*20+random(100));
  me->set("water", (int)me->max_water_capacity()*25+random(100));
  message_system(HIG "\n
祝愿"+HIW"静静的等待你"+HIG"和"+HIW"小娃娃"+HIG"百年好和，白头偕老，早生贵子
"+HIR"祝愿"+HIW"静静的等待你"+HIR"和"+HIW"小娃娃"+HIR"的新婚快乐！
"+HIM"让我用真心祝福你们：爱之深，情之切，曾经海誓山盟，曾经天荒地老，
"+HIR"静静的等待你"+HIM"和"+HIR"小娃娃"+HIM"祝福你们\n"NOR, me);
  destruct(this_object());
  return 1;
}

