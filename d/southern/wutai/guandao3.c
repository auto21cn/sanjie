//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "官道");
set("long", @LONG
    

　　一条宽阔的大道，贯穿南北，直同边关。
    东面有个废弃了的海港。

LONG );


set("exits", ([
  "north"   : __DIR__"guandao2",
  "west"   : "/d/kaifeng/tieta",
  "east"   : "/d/dongying/haigang",
  "south"   : "/d/longzhu/qy/lu",
 
]));


set("objects", ([
]));


set("outdoors", 1);

setup();
}
