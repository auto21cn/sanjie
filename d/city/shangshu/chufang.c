//Created by waiwai@2001/05/12

inherit ROOM;

void create()
{
	set("short", "厨房");
        set("long",@LONG

你来到了尚书府的厨房。厨房里各种烹饪用品与设备应有尽有，而且
用品的做工也都很精细，一眼便知是官家的用品。厨房里的炉火烧得
旺旺的，一个烧火丫鬟正忙着即将出锅的「西湖醋鱼」。
LONG
        );

        set("exits", ([
		"west": __DIR__"road3",
                ]));

	set("objects", ([
		__DIR__"npc/maid": 	1,
		]) );

        setup();
        replace_program(ROOM);
}

