/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "内宅");
        set("long",@LONG

你轻轻地走进尚书府的内宅，男客一般是不让来此的。内宅的布
置很素雅，一切的摆设都显得很自然，有「天然去雕饰，清水出
芙蓉」的意味。西边就是你来时经过的花园。
LONG
        );

        set("exits", ([
		"west":		__DIR__"huayuan",
                ]));

	set("objects", ([
		__DIR__"npc/qing_chen":		1,
		]) );

	create_door("west", "帘子", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

