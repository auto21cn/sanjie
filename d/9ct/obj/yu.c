// 薯芋 by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_put","薯芋化成一滴清水,而后消失了。\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "薯芋" NOR , ({"shu yu", "shu","yu"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "棵");
    set("long", "这是巴蜀天特有的珍稀药材。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="shu yu" && arg!="yu")   return 0;
  
  me->add("eff_kee",(random(2)+9));
  message_vision(HIG "$N轻轻地将一棵薯芋送入嘴中，一时间全身被一道青光笼罩。\n" NOR, me);
  destruct(this_object());
  return 1;
}

