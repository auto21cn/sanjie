//by cigar 2001.12

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG "绿色小叶" NOR, ({"xiao ye", "ye"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "片");
    set("long", HIG "一片发着绿色微光的小叶子。\n"NOR);
    set("value", 800);
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

  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xiao ye" && arg!="ye") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*3+random(120));
  me->set("water", (int)me->max_water_capacity()*3+random(120));
  message_vision(HIG "$N捏起一片绿色小叶放入口中，小叶入口即化，$N顿感精神大振。\n" NOR, me);
  tell_object(me,HIG "浑身舒坦多了！\n"NOR);
  destruct(this_object());
  return 1;
}
