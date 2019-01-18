
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
set("no_get","不是你的，你也想要？\n");
set("no_give","自己用吧，别老是给人？\n");
set("no_drop","不想要了，你也太浪费了，还是留着吧！\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
set_name( GRN "灵丹" NOR , ({"ling dan", "dan"}));
  set_weight(90);
set("value", 20000); 
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
set("long", "由人参和牛黄练制的丹药。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan" && arg!="ling dan") return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
message_vision(HIG "$N服下一棵灵丹，觉得轻飘飘的，一切又恢复了
只见$N散出七彩神晕，看起来舒服极了！\n" NOR, me);
destruct(this_object()); 
  return 1;
}

