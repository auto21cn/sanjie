//by dewbaby
//xiaolu1

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

奇花异草在小路两边随风飘摇，绚烂盛开的模样让你
心神陶醉。春冬秋夏，此处花开永不落。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaolu1",
   "west" : __DIR__"xiaolu3",
]));
   set("objects",([
      "/d/obj/flower/meigui.c":1,
       "/d/obj/flower/guihua.c":2,
  ]));

  setup();
}


