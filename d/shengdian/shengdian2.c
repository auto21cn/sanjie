inherit "/std/room/shengdian.c";

void create ()
{
reload("ฝ๐บฃนโท๐ฬร");
set ("short", "ฝ๐บฃนโท๐ฬร");
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
   "west" : __DIR__"dian",
]));
  set("no_clean_up", 1);
    set("where_name","ฝ๐บฃนโท๐");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

