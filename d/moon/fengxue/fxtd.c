// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//fxtd.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "枫雪天地");
  set ("long", "
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n"
HIR"   枫，是红的，\n"
BLU"                        天，是蓝的，\n"
HIY"                                          地，是黄的，\n"
HIC"             那洁白无瑕的雪，在窗外飞舞……\n"
NOR"＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊

    这里就是传说中的枫雪天地了，没想到藏在这个山谷中，外边
还是阳光明媚，这里却弥漫着漫天的风雪，你心里不禁有种凄凉的
感觉。向北望去可以看到风雪宫的大门，南边雾蒙蒙的，什么都看
不清楚，回头看刚才跳下来的地方，却是一座悬崖，不知道可不可
以爬上去。

");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fdoor",
  "south" : __DIR__"lake",
]));
  set("outdoors", 1);

  setup();
}

void init()
{ 
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object who=this_player();

  if (arg != "east") 
     return 0;

message_vision("$N手脚并用，往东边的悬崖上爬过去。\n",who);
who->move("/d/moon/yunu3.c");
message_vision("终于爬上来了，$N长长地舒了一口气。\n",who);
return 1;
}



