//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "厨房");
        set ("long", @LONG
这是天蓬元帅府的御膳伙食房,你一进门就被这里的美味熏倒了。 
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/leox/tianpeng/zoulang3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
