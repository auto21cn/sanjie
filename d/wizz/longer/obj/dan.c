// dan.c   Creat By Longer@ALL_XYJ 
#include <ansi.h>

inherit ITEM;

int do_kiss(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的丹，哪能随便给人？\n");
    set("no_drop","这么心爱的东西，扔了多可惜呀！\n");
    set("no_sell","无情之人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_kiss", "kiss");
}

void create()
{
  set_name(HIR "丹" NOR, ({"dan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "为了庆祝我们的蛇口站人数超过210而产生的纪念丹。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_kiss(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要亲吻什么？\n");
  
  me->add("combat_exp",90);
  me->add("daoxing",190);
  me->add("potential",90);
  message_vision(HIR "$N亲了一下相思红豆，相思红豆发出耀眼光芒！\n想起长时间以来,朋友们在蛇口站度过的年月,$N不禁怅然泣下……\n" NOR, me);
  
  destruct(this_object());
  return 1;
}

