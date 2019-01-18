//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "曲径通幽");
        set ("long", @LONG

这里是冷月宫的后宫,到处都是珍奇的花草树木，山石林立，
溪水潺潺，鸟语花香，好一个人间仙境


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"moon5", 
       "south" : __DIR__"moon4",  
       "west" : __DIR__"youming",  
       "east" : __DIR__"meishi", 
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("outdoors", "曲径通幽");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

