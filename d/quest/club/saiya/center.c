inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","飞碟控制室");
  set ("long", HIR@LONG
                    ☆☆☆☆☆☆飞碟控制室☆☆☆☆☆☆☆
     这里是飞碟控制室，已经陈旧了的仪表仍然运行着。
   散落世间的那些塞亚异族的首领们每100年在这里聚会一次。
LONG NOR);

  set("exits",([
  "right" : __DIR__"ufo",
  "enter" : __DIR__"miroom",
  ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
         ]));
  setup();
}
