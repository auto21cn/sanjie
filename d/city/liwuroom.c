// Room: /d/liwu/lipinroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "节日礼品屋");
        set("long",
"这是一幢红白相间的小房子，你从窗子向里望去，见里面挂满拉花彩灯，\n"
"充满节日气氛。门里面有一棵郁郁葱葱的树，上面挂满了礼物。拿到礼物的人都笑开了颜，\n"
"赶快进去拿一个吧！ \n\n"
HIC"°★ ．·°∴°．°∴°．★☆° ·°．☆°．★· °．°°★．·°\n"NOR
HIC"°★ ．·°∴°．°∴°．★☆° ·°．☆°．★· °．°°★．·°~~~ \n"NOR
HIW"  ~~~~\    ▓            ^*^          "+HIR".☆\n"NOR
HIW"   ./  \~~~▓~   ~~~~\ ◆             "+HIR"$◢◣$\n"NOR
HIW"   / ^^ \ ══════              "+HIR"$◢★◣$"+HIG"        Happy\n"NOR
HIW" ..▎[]  ▎田  田 ▎ |            "+HIR"$◢■■◣$"+HIG"             New\n"NOR
HIW" 　▎    ▎       ▎'|'▎       "+HIR" $◢■■■◣$"+HIG"                Year ！\n"NOR
HIW"　 ■■■■■■■■■■〓▄▃▂▁ "+HIR"︸︸||︸︸\n\n"NOR
);

        set("exits", ([
                
               "north" : "/d/wiz/entrance",
        ]));
        set("no_time",1);
        set("no_fight", 1);
        set("no_spells", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */

       "/u/hanhan/meng/obj/tree" : 1
      ]));


        setup();
                call_other( "/obj/board/sanjie_meiwen", "???" ); 
//        replace_program(ROOM);
}

void init()
{
    add_action("do_drop", "drop");
    add_action("do_drop", "get");
}

int do_drop()
{
    tell_object(this_player(),"鬼鬼祟祟的想干什么！\n");
    return 1;
}
