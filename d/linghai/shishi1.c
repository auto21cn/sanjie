//by dewbaby
//shishi1 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", YEL"明湖石室"NOR); 
         set ("long", @LONG 
        
这是一间方形的小石室。墙壁上斑斑驳驳的，还有
丝丝模糊不清的血迹。你在这里看了一会，就不想
再多呆。这小小的石室里似乎隐藏着什么秘密...
LONG); 
        
         
        set("exits", ([ /* sizeof() == 1 */

        "east":__DIR__"hudi2",        
        ])); 

        setup(); 
        }

