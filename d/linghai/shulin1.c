//by dewbaby//shulin1

#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", GRN"柳树林"NOR);
     set("long", @LONG
你走入了一片茂密的柳树林，柳枝飘摆，纤叶盈盈。你被这片秀丽
迷惑住了，甚至难以辨出来时之路。
LONG);

     set("outdoors","大明湖");

     set("exits", ([
         "southwest" : __DIR__"minghu5",
         "east" : __DIR__"yuexia",
          "north":__DIR__"shulin3",
     ]));    
 
     setup();
}


