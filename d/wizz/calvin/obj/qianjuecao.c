// qianjue cao.c 千绝草

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么稀少的东西，哪能随便给人？\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "千绝草" NOR, ({"qianjue cao","cao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "棵");
    set("long", "一棵青青的小草,只是样子有点怪怪的。\n");
    set("value", 0);
    set("drug_type", "补品");
  }

  setup();
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("你要吃什么？\n");

  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(100);
  me->add_maximum_mana(100);
  message_vision(HIG "$N吃下一棵千绝草，好象没什么味儿！ \n" NOR, me);

  destruct(this_object());
  return 1;
}
