// created by kuku@sjsh 2002/12
#include <ansi.h>
inherit ROOM;
int block_cmd(string);

void create ()
{
    set ("short", HIG"酒谷"NOR);
    set ("long", @LONG

这里造出的酒其味醇厚甘甜，香飘十里。天下爱酒之人无不为能得
到酒鬼所做的酒而自豪，不过酒虽好酒，可是却得之不易。这里就
是举世闻名的酒谷。
LONG);

    set("exits", ([ 
        "up"    : "/d/meishan/longwan",
      ]));
    set("objects", ([ 
        __DIR__"npc/jiugui" : 1,
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
        string verb;
        verb = query_verb();
    if (verb == "bian") return 1; 
    if (verb == "cast") return 1; 
    if (verb == "ji") return 1; 
    if (verb == "perform") return 1; 
    return 0;
}
