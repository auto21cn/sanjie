inherit "/std/room/shengdian.c";

void create ()
{
reload("功德华佛堂");
set ("short", "功德华佛堂");
set ("long", @LONG

　　　　　　　████　　█　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　　　　█　　█　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　　　　█　　█　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　███████　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　█　　█　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　█　　█　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　█　　████
LONG);

  set("exits", ([
 // "down" : __DIR__"jiuguan1",
 // "up" : "/d/quest/club/clubbar",
]));
  set("no_clean_up", 1);
    set("where_name","功德华佛");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

