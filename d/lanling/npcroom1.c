// 兰陵 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "藏文阁");
        set ("long", @LONG

两边的牌匾上密密麻麻的写满了从古至今的无数大智者豪杰,
还有他们曾经留下的千古传奇般的神秘故事,那正堂上方却有一特
                     ※※※※※※※※※※※※※
大的牌匾,上面写着:   ※※  心  静  意  达  ※※ 四个大字。
                     ※※※※※※※※※※※※※

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "west" : "/d/calvin/lanling/npcroom" ,
          "east" : "/d/calvin/lanling/npcroom2" ,
        ]));

        set("objects", 
        ([ //sizeof() == 1
//        "/d/calvin/obj/score.c" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
