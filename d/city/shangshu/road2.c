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
	  set("short", "小径");
        set("long",@LONG

这里是尚书府的小径。小径继续向北延伸着，透过树丛隐隐约约
地看到那儿似乎有一间小屋。从这儿向东走就是一间客房，据说
客房里住的是一位贵客。不过一般人不允许进。
LONG
        );

        set("exits", ([
		"north":	__DIR__"road1",
                "east" :        __DIR__"kefang",
		"south":	__DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/huyuan":	1,
		__DIR__"npc/huyuan1":	1,
		]) );

	set("outdoors", "city");
	
	create_door ("east", "木门", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if( wizardp(me)) return 1;

        if ( dir!="south" &&  present("trainer", environment(this_player()))
                && !(string)me->query("marks/尚书") )
        return notify_fail("护院伸手拦住了你的去路，喝道：闯什么闯！\n");

        return ::valid_leave(me,dir);
}


