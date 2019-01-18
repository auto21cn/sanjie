//edit by xuanzi 2000/9/12

#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "望月阁");
  set ("long", @LONG

┌───────────────────────────────────╮ 
│        .      .  千 但 此 月 人 何 照 转 何 起 高 唯 我 今 不 把 明  │ 
│ .          .     里 愿 事 有 有 事 无 朱 似 舞 处 恐 欲 夕 知 酒 月  │ 
│   .  ●        . 共 人 古 阴 悲 长 眠 阁 在 弄 不 琼 乘 是 天 问 几  │ 
│          .       婵 长 难 晴 欢 向 。 ， 人 清 胜 楼 风 何 上 青 时  │ 
│    .             娟 久 全 圆 离 别 不 低 间 影 寒 玉 归 年 宫 天 有  │ 
│             .    。 ， ！ 缺 合 时 应 绮 ？ ， 。 宇 去 ？ 阙 。 ？  │ 
│ .      .                  ， ， 圆 有 户          ， ，    ，        │ 
│     .           .         .     ？ 恨 ，                             │ 
└───────────────────────────────────╯ 

 这里空荡荡的，只有四面洞开的窗户，可以看见窗外的月色。西边的窗户下有一张
 小几，上面摆着一具瑶琴。

LONG);

  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
//  "/d/moon/obj/qin" : 1,
]));
  set("no_time", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wygdown",
]));

  setup();
}

void init()
{
   add_action("do_play","play");
}

int do_play(string arg)
{
  object me=this_player();
  if (me->is_busy())
  {
    return notify_fail("你正忙着呢，呆会再弹把，别累坏了。：）\n");
  }
  if (me->query("sen")<100)
  {
    return notify_fail(HIY "你太过疲倦，还是休息一下吧。\n" NOR);
  }
  if (!arg) return notify_fail("你要弹什么？\n");
  if (arg!="qin") return notify_fail("你要弹什么？\n");
  message_vision("$N轻轻地坐了下来，手抚琴弦…………\n",me);
  remove_call_out("playing");
  call_out("playing",5);
  me->start_busy(15);
 return 1;
}

void playing()
{
  message_vision("琴声铮铮漴漴，如高山，如流水，连绵不绝...\n",this_player());
  remove_call_out("playing1");
  call_out("playing1",5);
}

void playing1()
{
  message_vision("$N奏到情深之处，丝丝琴声铺天而来，笼罩了整个望月阁。\n",this_player());
  remove_call_out("end");
  call_out("end",5);
}

void end()
{
 object me=this_player();
 int pot;

 message_vision(HIC "\n一曲已尽，天地无声。\n" NOR+"过了良久，才见$N深深的吸一口气，站了起来。\n",this_player());
 me->start_busy(1);
// pot = (random(me->query_kar()) + me->query_skill("zou-qin",1)) * 2;
// me->improve_skill("zou-qin",pot);
// me->receive_damage("sen",pot/5);
}

