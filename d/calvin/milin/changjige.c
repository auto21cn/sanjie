#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "藏经阁");
  set ("long", @LONG

这里原来是白龙寺藏经书的地方,现在虽然有些破旧
但是里面的经书却依然还很整齐的摆放着... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
                "north" : "/d/calvin/milin/bailong",
]));

  setup();
}
