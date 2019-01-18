#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short",HIR "杀手乐园" NOR);
  set ("long",@LONG

           杀  人  无  罪         Ｐ  Ｋ  有  理

LONG);
  set("exits",([
  "north" : __DIR__"room1",
  "west" : __DIR__"room2",
  "east" : __DIR__"room3",
  "south" : __DIR__"room4",
  "northwest" : __DIR__"room5",
  "northeast" : __DIR__"room6",
  "southwest" : __DIR__"room7",
  "southeast" : __DIR__"room8",
  "northup" : __DIR__"room9",
  "southup" : __DIR__"room10",
  "westup" : __DIR__"room11",
  "eastup" : __DIR__"room12",
  "northdown" : __DIR__"room13",
  "southdown" : __DIR__"room14",
  "westdown" : __DIR__"room15",
  "eastdown" : __DIR__"room16",
  "up" : __DIR__"room17",
  "down" : __DIR__"room18",
  ]));
  set("no_pkdao", 1);
  set("outdoors", 1);
  setup();
  "/obj/board/pkboard"->foo();
}

void init()
{
       call_out("greeting", 1, this_player());
       add_action("do_cast", "cast");
       add_action("do_fight", "fight");
       add_action("do_kill", "kill");
       add_action("do_perform", "perform");
}
int do_cast(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"天上传来一声怒嚎：“这里岂容$N乱用法术，要打斗就到战斗舞台上去！”\n"NOR,who);
       return 1;
}
int do_fight(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"天上传来一声怒嚎：“这里不是打斗的地方，$N到战斗舞台上去再打！”\n"NOR,who);
       return 1;
}
int do_kill(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"天上传来一声怒嚎：“还没有上舞台就想杀人？$N小心我ＳＭＡＳＨ你！”\n"NOR,who);
       return 1;
}
int do_perform(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"天上传来一声怒嚎：“$N可不能在这里乱用绝招哦！”\n"NOR,who);
       return 1;
}
void greeting(object who) {
if( who->query("combat_exp") < 5000000)
{
message_vision(HIR"天上传来一声怒嚎：“$N武学不够50万了，请回去把！”\n"NOR,who);
who->move("/d/city/kezhan");
}
}
