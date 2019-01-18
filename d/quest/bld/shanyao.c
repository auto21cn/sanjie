//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","山腰");
        set ("long", @LONG

虽然只到华山山腰，不过这里也相当高了。小溪从这里留过，小鸟
在这里歌唱，真让人感觉到大自然的美丽，另你忍不住停下来看看！
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu4",
                "eastup" : __DIR__"shanlu5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


