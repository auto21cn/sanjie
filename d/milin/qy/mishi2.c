// 密林宝库 by Calvin

inherit ROOM;

void create()
{
  set ("short", "密林宝库");
  set ("long", @LONG
这里是密林的最秘密的地方---密林宝库,据说这里的宝贝都是女涡娘娘曾经使做的,
但是后来一直没怎么用过,日久天长也便忘了这些宝贝的存在。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/d2",   
       "north" : "/d/milin/qy/d3",   
       "up" : "/d/milin/qy/d4",   
       "northeast" : "/d/milin/qy/d5",   
       "east" : "/d/milin/qy/d6",   
       "west" : "/d/milin/qy/d7",   
       "down" : "/d/milin/qy/d8",   
       "southeast" : "/d/milin/qy/d9",   
       "enter" : "/d/milin/qy/d10",   
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/long2" : 2, 
        ]));

  set("no_clean_up", 1);

  setup();
}
