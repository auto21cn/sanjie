//Cracked by Roath
//shulin 密林

inherit ROOM;

void create ()
{
        set ("short", "密林深处");
        set ("long", @LONG

这里一片朦胧,一切都是那么的飘渺...虚幻...
只有一些小路,领着偶尔到访的少些人迷恋此处.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : "/d/calvin/milin/milin1",
                "west" : "/d/calvin/milin/milin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
           "/d/calvin/milin/npc/yinshi.c" : 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
