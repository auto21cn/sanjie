inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIR"盘丝洞留言板"NOR, ({ "board" }) );
           set("location", "/d/dntg/hgs/entrance");
             set("board_id", "pansi_ss");
          set("long",     "这个留言板是我们共同开心留言的地方，放开你的胸怀，说上几句吧。\n" );
        setup();
          set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
