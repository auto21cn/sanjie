//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "炼枪场");
        set("long",
                "这里是玄兵古洞的造枪的地方。四周道也不是十分荒凉，相反还可说有\n"
                "几分景致。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，似乎什么都能被它\n"
                "融化似的。\n"  
        );
        set("exits", ([
                "east" : "/d/qujing/kusong/kusongjian",
        ]));

        set("objects",([__DIR__"npc/shiqiang" :1,]));

        setup();
        replace_program(ROOM);
}

