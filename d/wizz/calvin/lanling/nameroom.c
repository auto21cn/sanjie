// 兰陵续 by Calvin

inherit ROOM;

void create ()
{
        set ("short", "笔缘书宛");
        set ("long", @LONG

这是一家专门替人删改姓名和修改头衔的店铺,店铺内的生意长年的好,
据说老板原来是京城的一位教书先生,以前这家店铺的招牌就是他的名
气给打响的。

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
          "d/city/npc/qing" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
