inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIY "无忧馆"NOR);
        set ("long",HIY @LONG


                                  无忧帮           


          无忧，洒脱自在近明清，拓步斜柳间，试问人间还有几度春风抚面 


LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home6",
                "south" : "/d/kaifeng/wuguan/home4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
