#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIB"密道"NOR);
  set ("long", @LONG

一间斗室，两盏长明青灯，忽明忽暗的闪烁。一种说不出的诡异
正面墙上有三个圆盘(pan)，似乎可以旋转

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"moon5",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "pan" : "
三个圆盘上各有一些稀奇古怪的字，你看了半天楞是没看明白
",
]));

  setup();
}
void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要转动什么？\n");
  if(arg=="pan")
    return notify_fail("请输入帮主设定的密码进入秘室\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="lovesksjsh")
    {
      message_vision(HIR "糟糕！$N触动了机关！只见四周墙壁小孔中喷射出火焰。\n" NOR, me);
 if (mykee>0) 
        {
          me->set_temp("death_msg", "私闯冷月宫禁地，触动机关，被活活烧死了。\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 5000);
      me->receive_wound("kee", 5000);
      message_vision(RED "$N心中一惊，急忙躲避，但还是被火焰燎到！\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N按照宫主设定的密码打开了暗门，身形一闪消失在门后。\n", me);
      me->move(__DIR__"mishi");
      return 1;
    }
}

