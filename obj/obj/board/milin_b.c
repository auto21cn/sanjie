// 密林宝库 留言版 by Calvin
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIG"密林商讨版"NOR, ({ "board" }) );
        set("location", "/d/milin/qy/7");
       set("board_id", "milin_b");
        set("long",
                "你可以在此留言<post>或谈谈自己的心得,以供他人观摩。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
