// Room: /d/moon/fengxue/lake.c
// edit by xuanzi

inherit ROOM;

void create()
{
        set("short", "湖畔");
        set("long", @LONG

    从风雪中一路行来，突然一片碧波荡漾，浩瀚壮阔的
水面出现在眼前，让人胸怀一舒。湖水清可见底，极目望
去，在烟雨朦朦之中，似乎有一个小岛。

LONG);
        set("no_clean_up", 0);
    set("outdoors","fengxue");
  set("exits",([
    "north" : __DIR__"fxtd",
    "west" : __DIR__"lake-side",
]));

        setup();
}
void init()
{
  add_action("do_swim","swim");
}

int do_swim()
{
  object me;
  me = this_player();
  message_vision("$N看到湖面风雪滔天，不由得有点犹豫。\n",me);
 if (!me->query_temp("fengxue/aska"))
  {
    return notify_fail("这么高的风浪，当心被冲跑了！\n");
  } 
  message_vision("$N想到听雨轩就在前面，咬牙向湖里一跳，手脚并用，往前游去。\n",me);
  me->move(__DIR__"island");
  message_vision("终于游上来了，$N一软，倒在沙滩上。\n",me);
  return 1;
}

