//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "乘云阁");
        set ("long", @LONG

当百尺剑芒再次重现江湖，是否又是一次血腥的杀戮，当八
仙大阵再次张开，又有多少无辜的生灵丧生，歇息一下吧

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong3",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/loveuu" : 1,
        ]));

        set("indoors", "乘云阁");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

