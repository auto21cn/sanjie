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
        set("short", "客房");
        set("long",@LONG

你走进了尚书府的客房。客房不大，但布置得比较整洁。靠窗的
小桌上摞放着几本书。另一侧的墙上则挂了把宝剑，似乎告诉来
人此地主人竞是文武双全。

LONG
        );

        set("exits", ([
		"west":		__DIR__"road2"
                ]));

	create_door ("west", "木门", "east", DOOR_CLOSED);

        setup();
}

