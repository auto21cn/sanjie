//by dewbaby//shulin2

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
         "east" : __DIR__"minghu5",
          "west" : __DIR__"shulin4",
          "north":__DIR__"shulin5",
     ]));    
 
     setup();
}


