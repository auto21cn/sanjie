inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼第一层");
  set ("long", WHT@LONG
  
                第  一  层



这是〖清风细雨楼〗的第一层，来往的帮众络绎不绝，      

好不热闹，时不时传来帮众之间切磋武艺的声音。清   

香溢溢，琴声绵绵，鸟语声声，抬头望去，华丽的天花          

板上面锦绣着细雨清风的缥缈景象... ...

LONG NOR);

  set("exits",([
   "enter" : __DIR__"qingfenglou2",
  "out" : __DIR__"qingfenglou",
//  "enter" : "/d/city/kezhan",
//   "enter" : __DIR__"woshi",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
