//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "慈安庙");
        set ("long", @LONG

这是兰陵城里有名的庙宇,这里的香火很是鼎盛
来兰陵的游客也常常来这进香,不过这里最有名
的还是这的庙祝了,据说她的算法很是灵通 ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "west" : "/d/calvin/lanling/jie7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
      "/d/city/npc/keeper" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
