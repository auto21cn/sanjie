
inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
        set_name(HIY"梦回唐朝"NOR, ({ "board" }) );
        set("location", "/d/wizz/passion/datang1");
        set("board_id", "datang_b");
       set("long", HIM"\n多少次魂牵梦萦..........\n"
"多少次思念故友..........\n"
"多少次梦回唐朝...........\n"
"醒来才发现...............\n"
"轮回三界原来只不过是...............\n"
"一场游戏一场梦........\n"
"就在这里熟睡........\n"
"就在这里开始........\n"
"下一个完美的......梦......\n"
NOR
);
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
