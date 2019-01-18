#include <ansi.h>                                                                           
//五一劳动纪念章，给老玩家鼓励 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","你手里一松，纪念章从指间滑落！\n");                                       
    set("no_give","这么珍贵的纪念章，哪能随便给人？\n");                                        
    set("no_drop","这么宝贵的纪念章，扔了多可惜呀！\n");                                        
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIY "五一劳动纪念章" NOR , ({"jinian zhang", "zhang"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "枚");                                                                      
    set("long", "祝你五一劳动节幸福快乐。\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "补品");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="zhang" && arg!="jinian zhang")   return 0;                                         
                                                                                            
  me->set("eff_sen", (int)me->query("max_sen"));                                            
  me->set("sen", (int)me->query("max_sen"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_kee", (int)me->query("max_kee"));                                            
  me->set("kee", (int)me->query("max_kee"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("force", (int)me->query("max_force"));                                            
  me->add("potential",500);                                            
  me->add("office_number",1); 
  me->add("combat_exp",2000);
  me->add("daoxing",5000);
  me->add("balance",100000);   message_vision(HIR "$N一口把纪念章吞了下去，虽然硬了一点儿，但是还是满可口的�
$N增加了道行五年，武学2000点，潜能500点，官职1点，储蓄10gold！�                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           



