inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","塞亚异族___首领密室");
  set ("long", HIR@LONG




                   。      ★       。             
                   .     ☆       ·        。    
                   ★   · .        ☆         ·          *
      在这里。塞亚异族曾经做出过拯救地球的计划！


LONG NOR);

  set("exits",([
  "out" :__DIR__"center",
// "down" :__DIR__"9",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
        set("sleep_room",1);
        set("if_bed",1);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
                "/d/obj/flower/rose999" : 1,
                "/u/cigar/npc/xiaoya" : 1,
                "/d/obj/flower/hua" : 1, 
                "/u/ffff/npc2/girl": 1,
               // "/u/cigar/obj/pingpan" : 1,
        ]));
  setup();
}

