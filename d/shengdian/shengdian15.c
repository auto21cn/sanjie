inherit "/std/room/shengdian.c";

void create ()
{
reload("�۾��շ���");
set ("short", "�۾��շ���");
set ("long", @LONG

����������������������������������������������������������������������������������������������������
����������������������������������������������������������������������������������������������������
����������������������������������������������������������������������������������������������������
����������������������������������������������������������������������������������������������������
����������������������������������������������������������������������������������������������������
����������������������������������������������������������������������������������������������������
����������������������������
LONG);

  set("exits", ([
 // "down" : __DIR__"jiuguan1",
 // "up" : "/d/quest/club/clubbar",
]));
  set("no_clean_up", 1);
    set("where_name","�۾��շ�");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

