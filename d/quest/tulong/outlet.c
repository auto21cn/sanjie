inherit ROOM;
#include <ansi.h> 

void create ()
{
  set ("short", "青木林出口");
  set ("long", HIG @LONG
突然无数棵参天大树中出现了一条小径，似乎是出口！�
LONG);

  set("exits", ([
      ]));

  setup();
}

int valid_leave (object me, string dir)
{
  me->set("startroom","/d/city/center");
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}


