// 职业任务 （医师）
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "深山老林");
        set("long", @LONG
这儿是一个荒无人烟的山林！悬崖峭壁上可以看到长着许多不知名的小
草，别看这些草看上去很普通，可是据说世间的医师们都视这些
小草为宝物，原来它们是制作能去病强身的药品的原料。
LONG
        );

        set("exits", ([  
                "southwest" : __DIR__"shenshan",
                "south" : __DIR__"shenshan3",
        ]));
        set("objects", ([  
        ])); 
        setup();
}
