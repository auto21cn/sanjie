inherit "/std/room/shengdian.c";

void create ()
{
reload("Δ¦Δα΄±·πΜΓ");
set ("short", "Δ¦Δα΄±·πΜΓ");
set ("long", @LONG

‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨¨¨¨‘‘‘‘¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨‘‘‘‘¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨‘‘‘‘¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨¨¨¨¨¨¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨‘‘‘‘¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨‘‘‘‘¨‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘‘
‘‘‘‘‘‘‘‘‘‘‘‘‘‘¨‘‘‘‘¨¨¨¨
LONG);

  set("exits", ([
 // "down" : __DIR__"jiuguan1",
 // "up" : "/d/quest/club/clubbar",
]));
  set("no_clean_up", 1);
    set("where_name","Δ¦Δα΄±·π");
  set("outdoor", 1);
   get_fo_npc();
  setup();
}

int clean_up()
{
      return 0;
}

