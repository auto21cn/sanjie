inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"九重天入口"NOR);
        set("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※※※  这就是入口了，没有一定的修为，最好还是不要乱闯哦。※※※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG);
        set("exits", ([
                "north" : __DIR__"kingziminggong",
                "south" : "/d/9ct/qy/huayuan",
        ]));
        set("objects", ([
                __DIR__"npc/guard1" : 2,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object a;
   if (dir == "south" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("九重天守卫拦住你说道：九重天极其危险，死了不要怪人，还是不要进去为好。\n");
        }   
        return ::valid_leave(me, dir);
}
