// 结婚喜糖 by Cigar

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
    set("long", HIR"这是一颗浓浓的奶油香味的巧克力喜糖，是"HIY"飞扬"+HIR"和"+HIY"依依"+HIR"的结婚喜糖。\n"NOR);
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
  message_system(HIG "           \n祝愿"+HIR"飞扬和依依"+HIG"百年好和，白头偕老，早生贵子．．．．．． "+HIR"




                          囍            囍                        
                          囍            囍 
                     囍囍囍囍囍囍囍囍囍囍囍囍囍囍
                          囍            囍 
                          囍            囍 
                        囍囍囍        囍囍囍

                       囍囍囍囍      囍囍囍囍
                       囍    囍      囍    囍 
                       囍囍囍囍      囍囍囍囍
 
                       囍    囍      囍    囍
                         囍囍          囍囍
                    囍囍囍囍囍囍囍囍囍囍囍囍囍囍囍
    
                        囍囍囍        囍囍囍
                        囍  囍        囍  囍 
                        囍囍囍        囍囍囍



                      "+HIY"祝愿"+HIR"飞扬"+HIY"和"+HIR"依依"+HIY"的新婚快乐！\n"   NOR, me);

  tell_object(me, HIM"\n真情的祝福我们吧：爱之深，情之切，曾经海誓山盟，曾经天荒地老，我的心只为你而跳跃... ...    "+HIR"飞扬"+HIM"和"+HIR"依依"+HIM"祝愿你早日找到你的心动\n");
  destruct(this_object());
  return 1;
}
