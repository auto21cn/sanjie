//in wangxian DIR
//jinse.c

#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",YEL"山崖下");
          set("long",@LONG
这里是山崖下的一条小路，听说这一带常有食人怪
出现，你左右看看了看，颇为害怕。
LONG); 
         
           set("exits",([ /* sizeof() == 1 */
           "back" : __DIR__"minghu1",
           ]));
        set("objects", ([ /* sizeof() == 1 */  
        "/d/wizz/dewbaby/npc/jinse" : 1,
        ]));
     set("no_fight",1);
     set("no_sleep",1);
     set("no_eat",1);
     set("no_magic",1);
          
           setup();
}


