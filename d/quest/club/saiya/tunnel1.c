inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","时光隧道");
  set ("long", HIR@LONG
  
    这是一个时光隧道，前面不知道会通向何方。
    地上散落着一些生锈了的奇怪的兵器，大概是塞亚人早期使用过的东西。
在圆形穹隆上面，刻画着一些大头的小人，做着不同的姿势，想必是些练功
的招式吧。已经有人在跟着练习了。

LONG NOR);

  set("exits",([
  "north" : __DIR__"tunnel2",
  "south" : __DIR__"tunnel",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
