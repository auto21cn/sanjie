// seng_b.c
//created by seng@2005/1/15
//收集信息

#include <ansi.h> 
inherit BULLETIN_BOARD;

void create()
{
       set_name(HIY "嘉峪关需求调查表"NOR, ({ "board" }) );
        set("location", "/d/wiz/quests");
        set("board_id", "seng_b");
        set("long",     "自2005年1月15日起，开始统计这里的玩家需求，我所有的动作将依此做依据。by seng\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
