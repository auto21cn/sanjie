//by dewbaby
//huxin 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", GRN"锦玉园"NOR); 
         set ("long", @LONG 
        
这里大明湖底的一个小花园。这里的光线
全来自于园中石柱上的几颗耀眼的明珠。
中央有一张青玉砌成的石桌，桌上有几只白玉
雕成的龙腾器皿，一看便知道出自名师之手，
工艺十分精细。
LONG); 
        
         
        set("exits", ([ /* sizeof== 4*/

        "up":__DIR__"hudi4",       
         "down":__DIR__"zoulang",        
         "west":__DIR__"jade2",
         "east":__DIR__"feiyange",
        ])); 

        setup(); 
        }
