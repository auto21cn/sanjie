//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小路");
        set ("long", @LONG
这是一条通往府邸花园的小路,路的两边草木幽人,很是美丽.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/leox/tianpeng/zoulang4",
           "west" :"/d/tianpeng/xiaolu1",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
