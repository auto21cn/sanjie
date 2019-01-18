//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIB"甬道"NOR);
        set("long", @LONG

青石铺地，墙壁如大理石般光滑，不远处的地下
有个小石门，在这种阴森的地方，你一步也不想
多停留
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"gumu.c",
  "down" : __DIR__"passroom.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

