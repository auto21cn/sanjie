//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵东郊");
        set ("long", @LONG

这里是兰陵城的东郊,宽阔的马路两边树木林立,美不胜数.

LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/calvin/lanling/lanlingdong1",
                "east" : "/d/calvin/lanling/lanlingdong3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
