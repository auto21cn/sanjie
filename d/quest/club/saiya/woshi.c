inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","卧室");
  set ("long", HIR@LONG
  
神仙也要睡觉，更何况你也不是神仙，还是在这里偷懒一下休息休息
为妙。在卧室下面是他们的一个特制的大号浴缸。

LONG NOR);

  set("exits",([ "out" : __DIR__"tunnel9", 
  "down" : __DIR__"bath", 
]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("sleep_room",1);
  set("if_bed",1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
