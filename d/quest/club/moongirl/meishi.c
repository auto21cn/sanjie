//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "灭世宫");
        set ("long", @LONG

血的腥味折磨着你的神经，让你觉得有一种无法形容的冲动
你手中的武器在不安的颤动。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong5",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/mya" : 1,
        ]));

        set("indoors", "灭世宫");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

