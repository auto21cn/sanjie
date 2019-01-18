//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "宫前广场");
        set ("long", @LONG

这里是一片开阔的广场，冷月宫的人经常在这里聚会北面就
是巍峨的乾月宫，东面是冷月宫弟子们练武的武场，西面是
每年举行冷月宫比武大会的比武场。整个广场上旗麾飞舞，
刀明戟亮，一派威严的景象。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"moon1",
       "east" : __DIR__"wuchang",
       "west" : __DIR__"kantai", 
       "south" : __DIR__"door",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

