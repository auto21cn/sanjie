//Cracked by Roath
// Room: /d/moon/xiaoyuan.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create ()
{
  set ("short", "噙芳阁");
  set ("long", @LONG

此处空气骤冷，却异香扑鼻。一株花木也无，只见许多异草：或有牵藤的
，或有引蔓的，或垂山巅，或穿石隙，甚至垂檐绕柱，萦砌盘阶。那些奇
草仙藤，愈冷愈苍翠，都结了实，似珊瑚豆子一般，累垂可爱。屋内如雪
洞一般，一色的玩器全无。案上只有一个土定瓶，瓶中供著数枝菊。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/flower/juhua.c" : 1,
   "/d/quest/bld/npc/taxue" : 1,
// 暂时cut taxue.c 这个npc杀不死，搞一堆bug,先收起来。
//以后有时间改好了再开放by seng@2005-1-24
]));
 set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road3",
//  "east" :"/d/wailijie/room/moonmaster.c",
]));

  setup();
}
