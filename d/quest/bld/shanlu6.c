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

    set("item_desc", ([ /* sizeof() == 1 */
  "northup" : "望上隐约看到山颠。\n",
]));

        set("exits", 
        ([ //sizeof() == 2
                "northup" : __DIR__"shanlu7",
                "westdown" : __DIR__"shanlu5",
        ]));

        set("objects", 
        ([ //sizeof() == 2
               __DIR__"npc/guard" : 2,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   if (dir == "northup" ) {
        if (objectp(present("shan shen", environment(me))))
   return notify_fail(HIW"山神"NOR+"客气地说：“上面乃禁地，还是请回吧！”\n");

        }   
        return ::valid_leave(me, dir);
}

