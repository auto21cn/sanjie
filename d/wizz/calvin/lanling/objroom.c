// 兰陵续 by Calvin

inherit ROOM;

void create ()
{
        set ("short", "稀物小店");
        set ("long", @LONG

这是一家不算大的店铺,店铺里经营的是兰陵城周围的千奇百怪的各种物品。
你可以在这里买到几乎所有你罕见的的东西,不过这里的价格也是别有一格。

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
            "/d/wizz/cigar/npc/cuier" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
