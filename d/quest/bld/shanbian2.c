//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","山边");
        set ("long", @LONG

这里是华山的东面，不过很少有人来，因为这里没什么东西，
听说晚上还会有鬼出没。
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"shanjiao",
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

