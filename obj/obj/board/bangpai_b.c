inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name(HIR"帮派留言板"NOR, ({ "board" }) );
        set("location", "/d/calvin/lanling/xingyuejiulou2");
       set("board_id", "bangpai_b");
        set("long",
                "这里是留给天下各大帮派留言的地方，帮派的事在这说吧(post)。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
