inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIR "武林馆"NOR);
        set ("long",HIW @LONG



          潇潇武林，谁与争锋，问世间苍茫，谁与并论



LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home2",
                "south" : "/d/kaifeng/east1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

