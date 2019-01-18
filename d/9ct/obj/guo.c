// 菩提果 by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_put","菩提果化成一滴清水,而后消失了。\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "菩提果" NOR , ({"puti guo", "putiguo","guo"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "这是普渡天特有的珍稀药材。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="puti guo" && arg!="guo")   return 0;
  
  message_vision(HIG "$N轻轻地将一颗菩提果送入嘴中，一时间全身被一道土黄色光笼罩。\n" NOR, me);
  me->add("daoxing",(random(1000)+2000));
  destruct(this_object());
  return 1;
}

