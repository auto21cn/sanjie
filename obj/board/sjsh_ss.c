
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIB"三界神话杂言琐词留言板"NOR, ({ "board" }) );
           set("location", "/d/city/xqt");
             set("board_id", "sjsh_ss");
          set("long",     "这个留言板是我们共同开心留言的地方，放开你的胸怀，说上几句吧。\n" );
        setup();
          set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}
