//by dewbaby
//shishi3
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIW"世外"NOR); 
         set ("long", @LONG 
        
这里静悄悄的，无声，无人。你好奇地看了看
四周，发现右手边有一扇小石门。
LONG); 
        
         
        set("exits", ([ /* sizeof==1  */
        "east":__DIR__"house1",        
        ])); 

        setup(); 
       }
