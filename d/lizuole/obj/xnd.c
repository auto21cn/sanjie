// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// xiannidan.c 陷泥丹

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的陷泥丹，哪能乱扔! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "陷泥丹" NOR, ({"xianni dan","dan","ni","xnd"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "颗");
     set("long", "污漆漆的一个泥丹丸。上面刻有：“泥潭神仙”四个字。\n");
     //set("value", 5000);
     set("drug_type", "补品");
        }
  set("is_monitored",1); //监控精灵
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg)) 
    {
      return notify_fail("你要吃什么？\n");
    }
   else
     {
      if ( me->query("xndc")=="吃过了" )
        {
          command("say 你已经吃过了，不要那么贪心吗！留几个给新人吧！");
          destruct(this_object());
          return 1;
        }
       else
         {
           me->set("food", (int)me->max_food_capacity());
           //me->set("xndc", "吃过了");
           me->add("max_mana",200);
           me->add("max_force",200);
           me->add("combat_exp",10000); 
           me->add("potential",30000);
           me->set("xndc", "吃过了");    
           message_vision(HIC "$N吃下一颗陷泥丹，只觉体内冉冉升起一道道激流，使你 不得不大喊道：世界，我来了。！ 立刻天空传出一声大喊：你的内力法力都加了200点，潜能增加30000。道行加10年。  这个世界是你的了！ \n" NOR, me);
           destruct(this_object());  //毁灭这个物品
           //me->set("xndc","吃过了");
           return 1;
         }
     }
}
