//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "武器库");
        set ("long", @LONG
这里是天蓬元帅府兵器库,这里摆放的兵器无所不有,奇形怪状。 
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "west" :"/d/leox/tianpeng/zoulang3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/leox/npc/jiajiang" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
