
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW"望仙崖底"NOR);
  set ("long", @LONG

这里是望仙崖崖底。寒雾缭绕，薄冰轻覆。一阵冷风吹过
，你不禁打了个寒颤。抬头望去，天空中不时有鸟群飞过。
你看了看天色，想道：似乎离我要去的地方，还有一段不短的路途。
LONG);

  set("outdoors", 3);
  set("exits", ([ /* sizeof() == 3 */


  "northwest":__DIR__"minghu1",
]));

  setup();
}






