inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼第二层——荷花坞");
  set ("long", CYN@LONG




                  荷   花   吟



        凌波仙子静中芳，也带花红学醉妆。

        有意十分开晓露，无情一饷醉斜阳。

        泥根玉雪元无染，风叶清葱亦自香。

        想得石湖花正好，接天云锦画船凉。





LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou3",
  "down" : __DIR__"qingfenglou1",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
