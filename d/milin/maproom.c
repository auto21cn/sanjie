#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "地图馆");
  set ("long", @LONG

密林隐士最喜欢的就是收集各地的地图了
所以很多密林隐士就募捐开了这个地图馆
这里有很多地区的地图,而且很是畅销.
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
       "south" : "/d/calvin/milin/milin4",    
]));

  setup();
}
