//Cracked by Roath
// this by calvin at 2001.5

inherit ROOM;

void create ()
{
  set ("short", "兽城");
  set ("long", @LONG

兽城是这里的老百姓自己兴建的,这里有一些仙道的怪兽
它们是这里的主人,人们有时也来这领些出去,但一般是
用来拖运货物的,时间久了也没有什么事,一直很安乐

LONG);

  set("exits", ([
      "south" : "/d/kaifeng/chen2",
      ]));
  set("objects", ([
        "/d/kaifeng/npc/guaiwu" : 6,
     "/d/kaifeng/npc/shouguan.c" : 1
      ]));

  set("outdoors", __DIR__);

  setup();
}

void init()
{
add_action("do_stop", "whisper");
}

int do_stop(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision("这里不准用这个命令。\n",who);
       return 1;
}
