inherit "/std/room/shengdian.c";

void create ()
{
reload("日月珠光佛堂");
       set ("short", "日月珠光佛堂");
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
   "west" : __DIR__"dian1",
]));
  set("no_clean_up", 1);
    set("where_name","日月珠光佛");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

