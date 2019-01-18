// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "密林");
        set ("long", @LONG
这是一条阴深恐怖的小路,及少有人会来这里,一路上只听见鬼哭声不断.
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/3",   
       "north" : "/d/milin/qy/4",   
       "west" : "/d/milin/qy/3",   
       "east" : "/d/milin/qy/3",   
       "northeast" : "/d/milin/qy/2",   
       "southwest" : "/d/milin/qy/3",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
