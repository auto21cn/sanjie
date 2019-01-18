//Cracked by Roath 
inherit ITEM; 
#include <ansi.h> 
        
int do_locate(string arg);  
int do_task();         
void create() 
{ 
               set_name(HIW"探宝"HIG"图"NOR, ({"tanbao tu","tu"})); 
               set_weight(80); 
               if( clonep() ) 
                       set_default_object(__FILE__); 
               else { 
                       set("long", "这是一件用于寻找丢失物件的探宝图，它具有非凡的魔力。\n"+ 
                                   "能用(locate)命令找到物品的大概位置！\n"); 
                       set("unit", "件"); 
                       set("value", 150); 
               } 
} 
        
void init() 
{ 
          object ob = this_player(); 
          add_action("do_locate","locate"); 
         add_action("do_task","task"); 
} 
        
int do_task() 
{ 
          string output; 
          output=HIR"探宝图里突然映现出一篇蝇头小字：\n\n"NOR; 
               output += "———————————————————————————\n"; 
               output += TASK_D->dyn_quest_list(); 
               output += "———————————————————————————\n\n"; 
               output += YEL"  ☆"HIW"表示未完成使命     "HIR"★"WHT"表示已经完成的使命\n"NOR; 
          this_player()->start_more(output); 
          return 1; 
} 
        
int query_autoload() { return 1; } 
        
int do_locate(string arg) 
{ 
          if ( ! arg) 
        
          return notify_fail("locate <物品>\n"); 
          else 
          if (this_player()->query("sen") < 15) 
          return notify_fail("你的法力不够了。\n"); 
          else 
          "/adm/daemons/questd"->locate_quest(this_player(),arg); 
          this_player()->add("sen",-5); 
          return 1; 
} 
