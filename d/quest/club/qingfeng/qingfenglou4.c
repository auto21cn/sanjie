inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼第四层——樱花阁");
  set ("long", BLU@LONG




                         花      仙




               幽姿淑态弄春晴，梅借风流柳借轻

               种处静宜临野水，开时长是近清明

               几经夜雨香犹在，染尽胭脂画不成

               诗老无心为题拂，至今惆怅似含情



               一曲清歌一束绫，美人犹是意嫌轻

               不知织女寒窗下，几度抛梭织锦成







LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou5",
  "down" : __DIR__"qingfenglou3",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
 set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
