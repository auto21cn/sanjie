// sjsboard.c 三界山留言板

inherit BULLETIN_BOARD;

void create()
{
        set_name("三界山留言板", ({ "board" }) );
        set("location", "/d/sanjie/langerdian1.c");
        set("board_id", "sjsboard");
        set("long",     "三界山留言板。过录人客和三界山门人都爱留字于此。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

