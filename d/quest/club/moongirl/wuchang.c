//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "练武场");
        set ("long", @LONG

这里就是冷月宫的练武场，场中有十八般兵器，别看冷月宫
众人都是女子，练起武来丝毫不比男人差


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "west" : __DIR__"gong1", 
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("outdoors", "练武场");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

