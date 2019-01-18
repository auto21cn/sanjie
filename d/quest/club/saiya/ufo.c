inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","塞亚飞碟");
  set ("long", HIR@LONG
                           ……    塞  亚  飞  碟    ……

    这里是塞亚异族遗弃在地球上的一个飞碟。飞碟内堆满了破旧的仪器，靠墙有一个水晶球
依然发出几丝蓝光，似乎仍旧可以和某个神秘的空间进行联络。�
    朝左边是一扇防火门，右边是一道幽暗的通道。    

LONG NOR);

  set("exits",([ 
  "left" : __DIR__"center", 
  "right" : __DIR__"tunnel",
]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}

