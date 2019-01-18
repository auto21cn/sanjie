//
#include <ansi.h> 
 
inherit ITEM; 
 
int do_eat(string); 
void init(); 
 
void init() 
{ 
  if (!wizardp(this_player())) { 
    set("no_get", 1); 
    set("no_give", 1); 
    set("no_drop", 1); 
    set("no_sell", 1); 
  } 
    if(this_player()==environment()) 
  add_action("do_eat", "eat"); 
} 
 
void create() 
{ 
  set_name( HIY "地狱火丹" NOR , ({"hellfire pearl", "pearl"})); 
 
  set_weight(90); 
  if (clonep()) 
    set_default_object(__FILE__); 
  else { 
    set("unit", "个"); 
 
    set("long", "这是三界神话炼火地狱丹，此丹乃尽力十八层地狱火炮炼而成。\n"); 
 
    set("value", 10000); 
    set("drug_type", "补品"); 
  } 
  set("is_monitored",1); 
  setup(); 
} 
 
int do_eat(string arg) 
{ 
  object me = this_player(); 
  if (arg!="pearl" && arg!="hellfire pearl") return 0; 
 if(me->query("lucky/lianhuo")=="got")
  {tell_object(me,"别再贪了，嘿嘿！\n");return 1;}
  if(me->query("age")<20)
  {tell_object(me,"年龄太小了，addoil!\n");return 1;}
   
  me->set("eff_sen", (int)me->query("max_sen")); 
  me->set("sen", 2*(int)me->query("max_sen")); 
  me->set("eff_gin", (int)me->query("max_gin")); 
  me->set("gin", 2*(int)me->query("max_gin")); 
  me->set("eff_kee", (int)me->query("max_kee")); 
  me->set("kee", 3*(int)me->query("max_kee")); 
  me->set("mana", 2*(int)me->query("max_mana")); 
  me->set("force", 2*(int)me->query("max_force")); 
  me->set("food", 2*(int)me->max_food_capacity()); 
  me->set("water", 2*(int)me->max_water_capacity()); 
  
  me->set("lucky/lianhuo","got");
  me->add("level",10);
  me->add("magic_pointed",100);
  me->add("magiclevel",10);
  me->add("balance",2800000);
  tell_object(me,BBLU HIC"你的等级和魔法等级提高了10级，魔法点提高了100!\n你的存款增加了二百八十两黄金!\n");
  message_vision(HIC "$N吃下一颗地狱火丹，体内顿时感到炽热，充满火之灵力。\n" NOR, me); 
 
  destruct(this_object()); 
  return 1; 
} 
 

