// Room: /d/moon/fengxue/wytdamen
//edit by xuanzi

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIG"望月楼门"NOR);
  set ("long", @LONG

这是一座幽静的楼阁，窗户上都糊着绿色的窗纱。周围种着许多桂花树，散
发着淡淡的清香。阁门虚掩着，但是门前立着一面小小的纱屏，上书：

                        非请莫入

LONG);

  set("outdoors", __DIR__);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"xiaolu",
  "enter" : __DIR__"wygdown",
  "north":__DIR__"huayuan",
]));

  setup();
}

int valid_leave(object me, string dir)
{
   string myid=this_player()->query("id");
   if (!(myid=="xqls"))
  {
     if (!me->query_temp("wxt_invited") && dir=="enter")
     {
       return notify_fail("这个地方好象需要主人的邀请才能进去耶！．．．．(@_@)\n");
     }
  }
  return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_invit","invit");
}

int do_invit(string arg)
{
  object me=this_player(), obj;

  if (me->query("id")!="xqls")
    return notify_fail("什么？\n");

  if (!arg)
    return notify_fail("你要邀请谁啊？\n");

  if(!objectp(obj = present(arg, environment(me))))
     return notify_fail("这里没有这个人。\n");

  if( !obj->is_character() || obj->is_corpse() )
     return notify_fail("看清楚一点，那并不是活物。\n");

   message_vision("$N对$n说道：欢迎"+RANK_D->query_respect(obj)
        +"来望月阁玩！ \n", me, obj);
  
  obj->set_temp("wxt_invited",1);

  return 1;
}

