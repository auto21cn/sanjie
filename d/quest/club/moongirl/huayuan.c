// 九重天 御花园 by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", "御花园"NOR);
  set ("long", @LONG

这里绝对可以说是一个人间仙境，到处是其花异草，散发着
醉人的芬芳，很多见所未见的小鸟在欢快的歌唱，不远处一
条小溪潺潺流过，各种果树上结满了丰硕的果实。真是让人
流连忘返啊……


LONG);

  set("exits", ([
             "south": __DIR__"moon5",
      ]));

         set("objects", 
        ([ //sizeof() == 1
        "d/moon/obj/xuelian" : 2,
        "/d/obj/flower/flower" : 2, 
"d/wizz/junhyun/obj/bei" : 1, 

        ]));

  setup();
}

int do_climb(string arg)
{
        object tianshen; 
  object me=this_player();

  if( (!arg) || !((arg == "sky") || (arg == "天外天")))
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
          message_vision("$N轻轻地一跃好似踩着无形的阶梯,一会便消失在云海之中。\n", me);
                   me->move(__DIR__"tian");
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

