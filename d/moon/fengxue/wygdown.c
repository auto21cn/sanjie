// Room: /d/moon/fengxue/wygdown
//edit by xuanzi
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", HIC"望月楼"NOR);
  set ("long", @LONG

落月何处寄相思？遥望天边，月影无处觅。
枕边尤有泪痕残。谁为我念？寂寞楼上琴。
        
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"wytdamen",
  "up" : __DIR__"wxt",
  "north" : __DIR__"woshi",
]));
        set("valid_startroom", 1);
  setup();
//call_other("/obj/board/wangyuege_b", "???");
}

