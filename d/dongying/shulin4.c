
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
LONG );
	set("objects", ([ ]));
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shulin3",
		"north" : __DIR__"shulin5",
		"east"  : __DIR__"shulin4",
		"west"  : __DIR__"shulin3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
