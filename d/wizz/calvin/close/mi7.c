//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "流沙河底");
        set ("long", @LONG
这是"金身罗汉沙悟净"的修身之处,也是通往流沙河的一条迷道。
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "up" :"/d/tianpeng/mi6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        set("water", 1);
        setup();
}
