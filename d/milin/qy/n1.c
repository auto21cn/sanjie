// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "小路");
        set ("long", @LONG
这是一条阴深恐怖的小路,及少有人会来这里,一路上只听见鬼哭声不断.

LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/calvin/lanling/jie1",   
       "north" : "/d/milin/qy/men.c",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
