 // Room: /d/wiz/quests.c

inherit ROOM;
#include <ansi.h>

void create()
{
    set ("short","嘉峪关需求调研室");
	set("long", @LONG

 这里是唐僧专门给嘉峪关的兄弟开设的房间，
旨在给大家提供一个广开言路的场所，提出自
己最关心的需求。

在可行的情况下，我会做一些力所能及的满足。



LONG
	);
set("item_desc" , ([ /* sizeof() == 1 */
"east": "房子里云雾缭绕，什么也看不清楚。\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : WIZARD_ROOM,
   "down" : "/d/wiz/entrance",
]));
  set("objects", ([ /* sizeof() == 1 */
]));
        set("no_time",1);
	set("no_clean_up", 0);
	set("post_limit", 1);

	setup();
       call_other("/obj/board/seng_b", "???");
}
void init()
{
       add_action("do_exert", "exert");
       add_action("do_exert", "perform");
       add_action("do_exert", "kill");
       add_action("do_exert", "fight");
       add_action("do_exert", "ji");
}
int do_exert(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("天上传来一声怒嚎：“$N想运功？没门！要练功出客栈去！”\n",who);
        return 1;
}


int valid_leave(object me, string dir)
{
//		if(me->query("id")=="beavis") return ::valid_leave(me, dir);
		  //temp access for future wiz.

		if( dir=="east" && !wizardp(me) )
			return notify_fail("那里只有巫师才能进去。\n");
		return ::valid_leave(me, dir);
}


