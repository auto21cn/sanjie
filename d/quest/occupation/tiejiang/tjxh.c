//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "铁匠协会");
        set ("long", @LONG

铁匠协会坐落在风景迤俪的泾水之滨，想要找个好工作吗？
可以来这里试试。
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "west" : "/d/jz/xw-2",
        ]));
        set("objects", ([  
                __DIR__"npc/tou" : 1,
        ])); 
        setup();
}
