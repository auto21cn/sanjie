// 九重天 巴蜀天 by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", HIG"二重·巴蜀天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※巴蜀天地豪情在  只约仙朋共品缘※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);

        set("exits", ([
  "down": __DIR__"er",
        ]));

        set("objects", ([
             "/d/9ct/obj/yu.c" : 1,
              ]));

        setup();
}
