//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "藏精阁");
        set ("long", @LONG

两边的牌匾上密密麻麻的写满了从古至今的无数大智者豪杰,
还有他们曾经留下的千古传奇般的神秘故事,那正堂上方却有一特
                     ※※※※※※※※※※※※※
大的牌匾,上面写着:   ※※  傲  游  九  天  ※※ 四个大字。
                     ※※※※※※※※※※※※※


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : "/d/club/moongirl/huayuan2", 
       "west" : "/d/calvin/lanling/npcroom1"   
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("indoors", "藏精阁");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


