#include <ansi.h>                                                                           
//建站贡献纪念奖励，给老玩家鼓励 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","你做梦去吧！\n");                                       
    set("no_give","这么珍贵的东西，哪能随便给人？\n");                                        
    set("no_drop","扔了多可惜呀,笨蛋！\n");                                        
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIM "肯德基儿童套餐" NOR , ({"kendeji taocan", "kdj"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "套");                                                                      
    set("long", "感谢你对于蛇口站的贡献！\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "补品");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="kdj" && arg!="kendeji taocan")   return 0;                                         
                                                                                            
  me->set("eff_sen", (int)me->query("max_sen"));                                            
  me->set("sen", (int)me->query("max_sen"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_kee", (int)me->query("max_kee"));                                            
  me->set("kee", (int)me->query("max_kee"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("force", (int)me->query("max_force"));                                            
  me->add("potential",1000);                                            
  me->add("office_number",1); 
  me->add("combat_exp",2000);
  me->add("daoxing",15000);
  me->add("balance",1000000);   message_vision(HIR "$N偷偷地端出彗星大叔奖励给$P的肯德基儿童套餐，开始慢慢地品尝起来。�
$N增加了道行十五年，武学2000点，潜能1000点，官职1点，储蓄100gold！�                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           

