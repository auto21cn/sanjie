//by dewbaby

//hudi1   
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIG"大明湖底"NOR); 
         set ("long", @LONG 
        
四周一片幽静，深绿的湖水如温柔的手臂将你往深处轻轻
推去。你被湖底的安详之景深深触动。竟忘了安详后的无
限危机!
LONG); 
        
        set("exits", ([ /* sizeof() == 1 */ 
        "up" : __DIR__"minghu4",       
          "down" : __DIR__"hudi2",       
        ])); 

        setup(); 
        }
    


