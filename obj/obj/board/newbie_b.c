// wizard_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIR"三界神话游戏经验告示"NOR, ({ "board" }) );
        set("location", "/d/wiz/entrance3");
       set("board_id", "newbie_b");
	set("long",
		"这是一个专门公告系统资讯的板子，只有巫师能 post。\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}
