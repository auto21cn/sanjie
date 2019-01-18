inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short","清渊净水潭");
  set ("long", @LONG

这里便是清渊净水潭了,你可以看到正冒着白气的潭水是那么的洁净,
不过更神气的是这里的水所具有的特殊复舒功能的功效了。

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "east": "/d/calvin/lanling/tan",
    "southwest": "/d/calvin/lanling/tan2",
]));

  set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
    "/d/calvin/npc/boss1" : 1,
  ]));

  set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("valid_startroom", 1);
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

    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;

}

int valid_leave(object me, string dir)
{
        object mbox,*inv;
        inv = all_inventory(me);
        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("税官满脸堆笑地挡住了你：对不起，那边是净水潭，不是这里的客人，不便打扰。\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回给邮差。\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}
