// 开心果 by Cigar

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIY"琥珀"+HIW"开心果"NOR , ({"kaixin guo","guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", HIR"瞳瞳最喜欢的零食，大大的果仁，外面包着一层浓厚的琥珀糖，上面还点缀颗颗小芝麻。\n"NOR);
    set("value", 0);
set("no_sell",1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out ("becoming_old",1800);
}
void becoming_old ()
{
  object me = this_object();

  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="kaixin guo" && arg!="guo") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*10+random(100));
  me->set("water", (int)me->max_water_capacity()*10+random(100));
  message_vision(HIG "$N美美的吃下一块"+HIY"琥珀"+HIW"开心果"+HIG"，开心的不得了，甜蜜蜜，  笑得多甜蜜！就像歌曲里唱的：“是你，是你，我梦见的就是你，啊，在梦里，梦里，梦里见过你”。 \n"   NOR, me);
  tell_object(me, HIM"甜蜜蜜，你吃得多甜蜜，好象花儿开在春风里，开在春风里... ... 瞳瞳请你吃的开心果好吃吗？亲亲瞳瞳吧... ...\n");
  destruct(this_object());
  return 1;
}
