// meet_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("玩家意见板", ({ "board" }) );
        set("location", "/d/wiz/meeting");
        set("board_id", "meet_b");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
        set("capacity", 400);
	replace_program(BULLETIN_BOARD);
}
