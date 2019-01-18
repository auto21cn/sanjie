// 兰陵续 by Calvin

#include <room.h>
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "天下楼");
  set ("long", @LONG

这里是江湖上最有名气的天下楼,你可以在这里开设自己的帮派，带着自己的兄弟
在江湖上好好的闯荡一番。不过要开设自己的帮派可不是很容易的,除了你自身的
修养好和修行高以外，你最需要花上十万两黄金才能顺利的开设出来。

LONG);

     set("exits", ([ /* sizeof() == 2 */
    "down" : "/d/calvin/lanling/xingyuejiulou",
    "east" : "/d/calvin/lanling/clubroom",
]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/calvin/npc/cluber" : 1,
        ]));

  setup();
        call_other("/obj/board/bangpai_b", "???"); 
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}
int valid_leave(object me, string dir)
{
        object mbox,*inv;
        inv = all_inventory(me);
        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("帮派使者满脸堆笑地挡住了你：对不起，后面是帮派申请室，不是申请帮派的人，不便打扰。\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, " \n");
                destruct(mbox);
        }
        return ::valid_leave(me, dir);
}

