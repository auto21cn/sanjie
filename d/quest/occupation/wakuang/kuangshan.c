// 职业任务 （挖矿）
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "矿山");
        set("long", @LONG
这儿是一座荒无人烟的矿山！山间和地面上能看到好多好多的矿脉，
矿藏极为丰富！据说这儿可以挖出几乎天下间所有制造装备用的好矿石。
我想你应该来试试！
LONG
        );

        set("exits", ([   
                "west" : "/d/changan/eside5",
        ]));
        set("objects", ([   
                __DIR__"kuangmai" : 5,
                __DIR__"npc/xunbu" : 2,
        ])); 
        set("no_fight",1);
        set("no_magic",1);
        set("no_steal",1);
        setup();
}

