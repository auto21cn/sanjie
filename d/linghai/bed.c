//by dewbaby
#include <ansi.h>
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", HIY"橡木软榻上"NOR);
        set("long", @LONG

一张干净柔软的橡木软榻。看上去极为舒适，
轻轻抚摸上去，你只觉得睡意绵绵。
LONG
        );
        
        set("exits", ([
                "out": "/u/dewbaby/wangxian/jade2",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}
void init() {
  add_action("do_sleep","sleep");
  ::init();
}
int do_sleep() {
  if (this_player()->query("gender")!="女性")
  write("你突然觉得自己一个大男人，实在不该擅自闯入此地。\n");
  this_player()->start_busy(random(3));
  this_player()->add("sen",-150);
  return 1;
}

