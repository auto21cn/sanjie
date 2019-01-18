// Room: /d/quest/yaota/dong
//created by kuku@sjshhlj 2002/12

inherit MAGIC_ROOM;
#include <room.h>
#include <ansi.h>
 
void create ()
{
  set ("short", HIC"别有洞天");
  set ("long", @LONG

一走到这里眼前就豁然开朗，曾经充斥在眼前的妖气
荡然无存，隐隐还能闻到一股淡淡的幽香，只有闯过
妖塔历经磨难的有福之人才能来到这里。

LONG);

  set("objects", ([ 
]));
  set("exits", ([ 
  "east" : __DIR__"tower9",
]));

  create_door("east", "石门", "west", DOOR_CLOSED);
  setup();
}
