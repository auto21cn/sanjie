//by dewbaby
//hudi2 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIG"大"GRN"明"HIG"湖"GRN"底"NOR); 
         set ("long", @LONG 
        
四周一片幽静，有隐隐的蓝色火光从水草中涌出，你想去
看个究竟，却又十分不确定.....

你慢慢游了过来，不时注意着身边是否有可疑现象。
听说着附近常有凶猛的水怪出现，不少人被啃得尸骨不全！
LONG); 
        
         
        set("exits", ([ /* sizeof() == 3 */ 
        "up" : __DIR__"hudi1",
         "down": __DIR__"hudi3",
         "west":__DIR__"shishi1",       
        ])); 

        setup(); 
        }
  

