//莲子湖
//by dewbaby
 inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
  set_name(HIY"大"HIC"明"HIG"湖"HIW"迎客碑"NOR,({"board"}));
      set("location","/u/dewbaby/wangxian/minghu1");
      set("board_id","minghu_b");
      set("long",
         HIC"大明湖畔的迎客碑。上面记载着大明湖的典故与故事。\n"NOR);
    setup();
    set("capacity",500);
    replace_program(BULLETIN_BOARD);
}

