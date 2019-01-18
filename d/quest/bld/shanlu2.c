//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","山路");
        set ("long", @LONG

一条曲曲折折的小路，向上只通到山上，不过道路陡峭，不太好
走。两边是点点野花，青青小草。
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"shanlu3",
                "southdown" : __DIR__"shanlu1",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

