#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", "花园"NOR);
  set ("long", @LONG

藏精阁后的一个花园，长着一棵千年老树，据说爬上这棵树
就可以到达神居住的地方……


LONG);

  set("exits", ([
             "south": "/d/calvin/lanling/npcroom2.c",
      ]));

         set("objects", 
        ([ //sizeof() == 1
        ]));

  setup();
}

int do_climb(string arg)
{
        object tianshen; 
  object me=this_player();

  if( (!arg) || !((arg == "tree") || (arg == "千年树")))
    return notify_fail("登什么？\n");
  if (me->is_busy()) return notify_fail("你现在正忙着呢。");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
}
  else
    {
      if ((int)me->query_skill("dodge", 1)<60 && (int)me->query_skill("moondance", 1) < 200)
        {
          message_vision("$N小心翼翼的往上攀登了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
          me->improve_skill("dodge", 60-me->query("str"));
          tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
        }
      else
        {
          message_vision("$N抓住树藤，慢慢的向上爬去……\n", me);
                   me->move(__DIR__"door");
        }
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

int valid_leave(object me, string dir)
{
        object a;
   if (dir == "up" ) {
                if(objectp(a=present("tianshen", environment(me))) &&
living(a) )
        return notify_fail("天神拦住你说道:天外神天的一些禁地请不要前去。\n");
        }   
        return ::valid_leave(me, dir);
}


