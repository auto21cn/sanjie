// 密林死城

inherit ROOM;
void create ()
{
        set ("short", "死城");
        set ("long", @LONG
这是一片琅籍的土地,到处是一片死气,似乎没有生命的存在。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "down" : "/d/milin/qy/sc4",    
       "up" : "/d/milin/qy/sc2",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/milin/npc/ss3" : 1,
        ]));

        set("no_clean_up", 0);
        set("no_time", 1);
        set("no_quit", 1);
        set("chat_room", 1);
        set("no_upgrade_age", 1);
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
