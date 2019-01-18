inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","聚义堂");
  set ("long", @LONG
  
                念              堂

这里是〖梦回大唐阁〗的总坛大堂，堂中格调高雅，桌椅齐净，香炉
焚出缕缕清香，不禁让人精神一震。平时，绝情谷众都喜欢在这里聚
首一堂，闲话家常。许多时候，许多重大会议也在这里举行。

LONG);

  set("exits",([
  "southdown" : __DIR__"dayuan",
  "west" : __DIR__"liangong",
//  "east" : __DIR__"leitai",
  "enter" : __DIR__"woshi",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
