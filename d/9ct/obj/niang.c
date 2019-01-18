// 栖霞仙酿 by Calvin

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_put","栖霞仙酿化成一丝青烟,而后消失了。\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIR "栖霞仙酿" NOR , ({"xixia xianniang", "xian niang","xianniang","niang"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "壶");
    set("long", "这是栖霞天特有的珍稀药酒。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xixia xianniang" && arg!="niang")   return 0;
  
  me->add("eff_sen",(random(2)+9));
  message_vision(HIG "$N轻轻地将一壶栖霞仙酿喝个精光，一时间全身被一道红色光笼罩。\n" NOR, me);
  destruct(this_object());
  return 1;
}

