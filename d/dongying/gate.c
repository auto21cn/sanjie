
inherit ROOM;

void create()
{
	set("short", "道场大门");
	set("long", @LONG
这便是〖神谷道场〗的正门。
LONG );
	set("exits", ([

		"north" : __DIR__"road2",
		"south" : __DIR__"xiaodao3",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
