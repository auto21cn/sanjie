//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "小路");
        set ("long", @LONG

这是一条长满小草的小道,路人不算很多 ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "northwest" : "/d/calvin/lanling/xiaolu5",
                "southwest" : "/d/calvin/lanling/xiaolu7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//             "/d/calvin/esman.c" : 1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
