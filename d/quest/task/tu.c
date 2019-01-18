//By waiwai@mszj 2000/12/02
//yngw 最后优化 2001/02/09
#include <ansi.h>
inherit ITEM;
#define TASK_D    __DIR__"questd"

int do_locate(string arg);
int do_task();

void create()
{
        set_name(HIW"探宝"HIG"图"NOR, ({"tanbao tu","tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "这是一件用于寻找丢失物件的探宝图。\n"+
                        "能用(location)命令找到物品的大概位置！\n");
                set("unit", "张");
                  set("value", 0);
        }
}


void init()
{
  add_action("do_locate","location");
  add_action("do_task","task");
}

int do_task()
{
   string output;
   object me = this_player();

   me->add("sen",-20); 

   output="探宝图里突然映现出一篇蝇头小字：\n\n";
   output += HIR"★ "HIW"黑龙江西域漫游"HIR" ★"HIG" 使命榜\n" NOR; 
   output += ""HIW"─────────────────────────────────────\n"NOR"";   
   output += TASK_D->dyn_quest_list();  
   output += ""HIW"────────────────────────────"HIG"黑龙江西域漫游"HIW" ────\n\n"NOR""; 

   me->start_more(output);
   return 1;
}


//  int query_autoload() { return 1; }

int do_locate(string arg)
{
   if ( ! arg)

   return notify_fail("location <物品id>\n");
   else
   TASK_D->locate_quest(this_player(),arg);
   return 1;
}


