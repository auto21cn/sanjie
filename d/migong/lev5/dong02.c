
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
                set("short", BLU"山洞"NOR);
        set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG NOR);
        set("exits", ([
                "east" : __DIR__"dong"+(random(19)+2),
                "south" : __DIR__"dong"+(random(14)+2),
                "west" : __DIR__"dong"+(random(9)+2),
                "north" : __DIR__"dong"+(random(4)+2),
        ]));
         set("objects", ([
              "/d/migong/box/gbox" : random(2),
         ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

