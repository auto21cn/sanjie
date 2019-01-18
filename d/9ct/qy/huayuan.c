// 九重天 御花园 by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", NOR"御花园"NOR);
  set ("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※※※   这里是皇宫的后院 - "御花园",这里四季长青,其中最显眼的就是    ※※※
※※※   花园中间的那棵"千紫藤(qianzi teng)",它高耸入云,一眼看不到    ※※※
※※※   顶.据说曾经有人试着爬过,但是没到一半就返回了,尽管这样也花    ※※※
※※※   了好多天,不过你也可以试试爬上去,据说如果拿到这藤最顶上的一   ※※※
※※※   件宝物并交给皇帝的话可以得到赏赐,你可以使用(climb)试试 ...   ※※※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG);

  set("exits", ([
             "north": "/d/calvin/lanling/entrance",
      ]));

  set("objects", ([
      ]));

  setup();
}

int do_climb(string arg)
{
        object tianshen; 
  object me=this_player();

  if( (!arg) || !((arg == "sky") || (arg == "九重天")))
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
          message_vision("$N轻轻地一腾就上了树藤,一会便消失在无尽的香花之中了。\n", me);
                   me->move("/d/9ct/qy/yi.c");
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
        return notify_fail("天神拦住你说道:九重天的一些禁地请不要前去。\n");
        }   
        return ::valid_leave(me, dir);
}
