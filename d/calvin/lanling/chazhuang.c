// 兰陵续 by Calvin

inherit ROOM;

void create ()
{
        set ("short", "路口茶庄");
        set ("long", @LONG

这是一家相对而言比较简单的茶庄,只有简单的几张陈旧了的
桌子凳子,其外就只有那个伙计和老板了。

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xiaolu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
"/obj/boss/lanling_lukou" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
