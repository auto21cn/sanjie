// by calvin 2001.5
inherit ROOM;

void create()
{
  set ("short", "面馆");
  set ("long", @LONG

这是密林深处的一家面馆,因为人烟稀少所以生意平平淡淡。但尽管这样
店里仍销售各式各样精美面点，面条，烧饼馍馍。等等....

LONG);
  set("exits", ([ 
       "south" : "/d/calvin/milin/milin5",    
  ]));
  set("objects", ([
   "/d/qujing/zhuzi/npc/people" : 2,
  ]));
  setup();
}
