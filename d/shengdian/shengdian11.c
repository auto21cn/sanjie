inherit "/std/room/shengdian.c";

void create ()
{
reload("ฯอษฦสืท๐ฬร");
set ("short", "ฯอษฦสืท๐ฬร");
set ("long", @LONG

กกกกกกกกกกกกกกจจจจกกกกจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกกกกกกกจกกกกจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกกกกกกกจกกกกจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกจจจจจจจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกจกกกกจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกจกกกกจกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกกก
กกกกกกกกกกกกกกจกกกกจจจจ
LONG);

  set("exits", ([
 // "down" : __DIR__"jiuguan1",
 // "up" : "/d/quest/club/clubbar",
]));
  set("no_clean_up", 1);
    set("where_name","ฯอษฦสืท๐");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

