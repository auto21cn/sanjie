
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("寒梅小筑留情日记本", ({ "board" }) );
           set("location", "/u/leoy/workroom");
             set("board_id", "fplum_b");
          set("long",     "这是寒和梅的相恋日记本。\n" );
	setup();
          set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
