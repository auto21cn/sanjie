//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "密室");
        set ("long", @LONG

一个不大的房间，里面却是物品齐全，这里是冷月宫众人避
难的场所


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "out" : __DIR__"in", 
        ]));

        set("objects", 
        ([ //sizeof() == 1

"/d/calvin/obj/he.c" : 2,
"/d/wizz/junhyun/obj/qingming-jian" : 1,
"/d/gumu/obj/zixue-blade" : 1,
"/d/pansi/obj/guo" : 3,
"/d/wizz/junhyun/obj/taiji-cloth" : 1,
"/d/gumu/obj/yuyi" : 1,
"/d/9ct/zb/wan" : 1,
"/d/9ct/zb/xue" : 1,
        ]));

        set("indoors", "密室");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

