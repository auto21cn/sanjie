//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "商人协会");
        set ("long", @LONG

商人协会坐落在商业气息浓厚的天竺国，这里每天都门庭若市，
想来希望成为一个有钱人是很多人的愿望吧。
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "east" : "/d/qujing/tianzhu/dalu5",
        ]));
        set("objects", ([  
                __DIR__"npc/huizhang" : 1,
        ])); 
        setup();
}
