// 情树 by Calvin

inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "情花树");
  set ("long", @LONG

     问世间情为何物,只叫人生死相许。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/calvin/tianpeng/pomiao",
]));
         set ("no_quit",1);
  setup();
}

void init() {
  add_action("do_dig",({"ku"}));
}

int do_dig(string arg) {
  object wan,me=this_player();
  if (!arg && arg!="tree" && arg!="qing tree")
    return notify_fail("你要干什么？\n");

  if (me->is_busy()) return notify_fail("休息一会儿吧。\n");

  me->add("kee",-10);
  message_vision("$N在情花树下黯然的哭了。\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N哭了半天,眼睛都红了。\n",me);
      else {
         message_vision("情花树被$N的哭声感动了,突然掉下了一粒果实。\n",me);
         wan=new("/d/calvin/obj/yangshen");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(2+random(1));
  return 1;
}         
