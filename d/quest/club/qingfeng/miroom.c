inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼——帮主密室");
  set ("long", CYN@LONG




                   。      ★       。             
                   .     ☆       ·        。    
                   ★   · .        ☆         ·          *


                在每一个冷风的夜晚，在每一条寂寞的路口，你是否会等待我，
                一个风尘仆仆的身影？如果你愿意，如果你愿意成为我的朋友，
                那么从今天起，让我们迎接我们多姿多彩的每一天… …


                在都市的喧哗中，我厌倦了尔虞我诈的生涯，我逃避，我解脱，
                我梦想“纵情山水间，挥洒天地行”。隐藏在内心的豪情，让
                我远离尘世，穿行在梦想的世界里。我渴望成为豪气干云的游
                侠，我渴望成为浪迹天涯的浪子，我渴望自由自在的翱翔在蓝
                天中，咨意的追寻自我。


                于是，我在夜黑风高的时刻，行驶在每一条我梦想的网路上，寻
                找知已、朋友和真情，如果你愿意，就做我的朋友吧。


                  *       ★     *   ☆.        ★ *     .    *        *     *☆
★ *     .     *          ☆★ *     .     * ★            ★ *     . 




LONG NOR);

  set("exits",([
  "out" : "d/club/qingfeng/huiyi",
// "down" : "d/club/qingfeng/qingfenglou1",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
        set("sleep_room",1);
        set("if_bed",1);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
                "/d/obj/flower/rose999" : 1,
                "/u/cigar/npc/xiaoya" : 1,
                "/d/obj/flower/hua" : 1,
        ]));
  setup();
}
