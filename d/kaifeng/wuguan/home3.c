inherit ROOM;
#include <ansi.h>
#include "leave.h"
void create ()
{
        set ("short",HIB "绝情馆"NOR);
        set ("long",HIB @LONG


                            绝情谷           


          绝情，多愁善感暮雨中，情深不觉，遗憾无知欲生寒 


LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home4",
                "south" : "/d/kaifeng/wuguan/home2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
