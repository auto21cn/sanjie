//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

inherit ROOM;
void create ()
{
        set ("short", "小路");
        set ("long", @LONG
这是一条人烟稀少的荒郊野路,平时路上很少见几个路人.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : "/d/leox/tianpeng/lu2",    
       "east" : "/d/calvin/lanling/lanlingbei4",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
