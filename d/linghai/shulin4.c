//by dewbaby//shulin4
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
         "west" : __DIR__"shulin7",
          "east" : __DIR__"shulin2",
          "north":__DIR__"shulin6",
     ]));
 
     setup();
}


