//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "宫门");
        set ("long", @LONG

这里就是九霄冷月宫的宫门，两扇黑漆大门上冰冷的镶嵌着
一百零八颗门钉，仔细去看竟然是一百零八颗拳头大的珍珠
所制成，门的四周用黄金包镶着，让人有一种奢靡而高贵的
感觉。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong1",
//       "south" : "/d/club/clubbar",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

