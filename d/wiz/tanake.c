//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "妻管严协会");
  set ("long", @LONG

这里是妻管严协会办公的地点，现在是办公的时候，只见办公桌前
坐着一个英俊潇洒的年轻人--斩天。你有什么委屈可以和他诉说
        柔弱娇妻爱逾命  万般委屈也平静

LONG);
  set("exits", ([
        "out"  : __DIR__"system",
          ]));
  set("outdoors","cz");
  setup();
}
