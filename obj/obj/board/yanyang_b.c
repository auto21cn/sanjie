// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"伤心寄语"NOR, ({ "board" }) );
        set("location", "/u/yanyang/workroom");
        set("board_id", "yanyang_b");
	set("long",
                "这是火舞の艳阳一个留言记事的留言本。\n" );
	setup();
	set("capacity", 200);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
