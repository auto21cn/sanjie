//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "无影阁");
        set ("long", @LONG

远离城市的喧嚣，在这里平静一下在杀戮的战场上受伤的心灵。
擦拭一下那占满血迹的银枪金锏。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "east" : __DIR__"gong3",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/hjeff" : 1,
        ]));

        set("indoors", "无影阁");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

