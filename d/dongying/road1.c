
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这便是〖神谷道场〗的小路。
LONG );
	set("exits", ([

		"north" : __DIR__"house",
		"south" : __DIR__"road2",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
