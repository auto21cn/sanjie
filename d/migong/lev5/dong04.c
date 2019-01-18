
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
                "east" : __DIR__"dong"+(random(17)+4),
                "south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
        ]));
         set("objects", ([
              "/d/migong/box/gbox" : random(2),
         ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

