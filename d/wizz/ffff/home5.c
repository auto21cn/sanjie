inherit ROOM;
#include <ansi.h>
void create ()
{
          set ("short", HIC"雪屋大门"NOR);
  set ("long", HIM@LONG

    大门口站着一个守卫,屋里住着一个美丽的姑娘.

  将军寝宫的东面是一个花园，盛开着说不出名字的鲜花。

  向南走越来越深。
LONG);
  set("exits", 
  ([ //sizeof() == 8 
     "west" : "/u/ffff/home4",
         "enter" :"/u/ffff/xueroom",
]));
   set("objects",
 ([ //sizeof() == 1
    "u/ffff/npc2/guard1" : 1,
     "u/ffff/gold" : 1,
]));
     set("no_clean_up", 0);
     setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "enter" ) {
if (objectp(present("guard", environment(me)))) 
        return notify_fail("雪的女儿守卫拦住你说道：私人重地，死了不要怪人，还是不要进去为好。\n");
        }   
        return ::valid_leave(me, dir);
}
