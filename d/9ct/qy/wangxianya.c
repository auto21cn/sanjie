// 九重天 望仙崖 by Calvin

#include <ansi.h>
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "望仙崖");
  set ("long", @LONG

相传这里的山崖是上天所设,是为心诚者提供的成仙便径,
只要诚心得道的人跳下崖去就会升仙,遨游极乐世界....
你可以试试跳下去(jump down)。
          ★★★★★★★★★★★★★★★★★
          ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
          □■遥看世间情物，无限逍遥自在■□
          ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
          ★★★★★★★★★★★★★★★★★

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up": __DIR__"lingge",
]));
  set("objects", ([
"/d/9ct/npc/piaomiao" : 1,
      ]));

  setup();
}
void init() {
    add_action("do_jump","jump");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"huayuan.c";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("往哪儿跳？\n");

  msg="$N";
  if (ridee) msg=msg+"骑着"+ridee->query("name");
  msg+="纵身往崖底跃下。\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-200) damage=me->query("eff_kee")-200;
  if (damage<=0) damage=0;
  me->receive_wound("kee",damage);
  me->move(dest);
  if (ridee) ridee->move(dest);
  if (!damage) message_vision("$N从悬崖上跳了下来，轻轻巧巧地落在地上，毫发未损。\n",me);
  else {
  message_vision("$N从悬崖上跳了下来，跌了个大跟斗。\n",me);
  COMBAT_D->report_status(me); 
  }
  if (ridee) {
      message_vision("\n$N骑着的"+ridee->query("name")+"摔成了一团肉饼。",me);
      ridee->die();
  }
  me->start_busy(1+random(2));
  return 1;
}
