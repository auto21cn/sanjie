
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIR"三界神话"HIC"泥潭美文集版"NOR, ({ "board" }) );
           set("location", "/d/city/liwuroom");
             set("board_id", "sanjie_meiwen");
          set("long",     "这个留言板是三界神话发表自己文章的地方，放开你的胸怀，写上几篇吧。\n" );
        setup();
          set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}
