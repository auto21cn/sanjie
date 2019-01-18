//edit by xuanzi


inherit ROOM;
#include <ansi.h>

void create()
{
  set("short","卧室");
  set("long" , @LONG

这里是主人的卧室。屋子中间的桌子上焚着一炉不知道是什么的香，整个
卧室里有一种清新的感觉。北边放着一张月牙软榻，榻前有一座玉色的屏
风。屏上有诗云：

             虚阁望月寒，绿窗印残梦
             流水似无情，冷月搅相思

LONG);
   set("no_fight",1);
   set("no_magic",1);
   set("exits",([
     "south":__DIR__"wygdown",
     ]));
   setup();
}

void init()
{
  add_action("do_sleep","bed");
  add_action("do_sleep","gosleep");
  add_action("do_sleep","gobed");
}

int do_sleep()
{ 
    object me = this_player();
    message_vision(HIY "$N掀开纱帐，准备上床了。\n" NOR, me);
    me->move(__DIR__"wygbed");
    message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
    return 1;
}

