inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIG"玩家NPC公告"NOR, ({ "board" }) );
        set("location", "/d/calvin/lanling/npcroom");
       set("board_id", "lanling_b2");
        set("long",
                "这是一个用来描述玩家NPC所处详细位置的公告版。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
