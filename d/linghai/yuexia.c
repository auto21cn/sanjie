//by dewbaby
//yuexia 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short",BLINK+HIB"月下亭"NOR); 
         set ("long", @LONG 

                **
                **
              ******
            ***********
         *****************
       *********************
     **************************
************---月下亭---***********
ぁぁぁ·············ぁぁぁぁ
---   明月当空照  此情此意何时了?  ---  
   *        **********          *
   Y        *        *          Y
   Y        **********          Y
   Y        *        *          Y
   Y        **********          Y
   Y        *        *          Y
   Y        *        *          Y
   Y       d       q *          Y
   Y      d          d          Y
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
 ---------------------------------
<<-------------------------------->>
   -----------------------------
LONG); 
        
         
              set("exits", ([ /* sizeof() == 3 */  
        "west":__DIR__"shulin1",        
          "east":__DIR__"cave1",
         "north":__DIR__"kezhan",
        ])); 

        setup(); 
        }



