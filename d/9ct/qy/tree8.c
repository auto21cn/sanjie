// 九重天 月影天 by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", HIM"八重·月影天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※依月傍影华之秀  客来随缘敬上茶※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);

        set("exits", ([
  "down": __DIR__"ba",
        ]));

        set("objects", ([
              "/d/9ct/obj/qian.c" : 1,
              ]));

        setup();
}
