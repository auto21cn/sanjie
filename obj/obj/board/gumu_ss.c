inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIY"古墓秘籍"NOR, ({ "mi ji" }) );
           set("location", "/d/gumu/zhongting");
             set("board_id", "gumu_ss");
          set("long",     "深深的甬道中放着一本秘籍，你忍不住想翻看几下。\n" );
        setup();
          set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
