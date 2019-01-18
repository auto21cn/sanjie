//Cracked by Roath
#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "兰陵当铺");
  set ("long", @LONG

这是兰陵城里最大的一家当铺了。素来以买卖公平着称。门口挂了一
块牌子 (paizi)。张老板是个很精明的生意人，见你走了进来，很客
气地和你寒暄，但眼睛里却没有什么笑意，很审慎地打量着你。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : "/d/lanling/jie8",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里：
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %  典当(pawn)              %
    %  卖断(sell)              %
    %  估价(value)             %
    %  赎回(retrieve stamp)    %
    %  购买(buy) 用list查看 ? %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
各种货物，铜钱、银两、黄金、银票、钻石一概通用。

"]));
  set("objects", ([ /* sizeof() == 1 */

]));
  set("no_clean_up", 1);
  set("noget_room",1);

  setup();
}
int clean_up()
{
      return 0;
}

