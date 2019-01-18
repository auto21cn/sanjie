
inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到路
的尽头。两旁百花争艳。令人留连忘返。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiaodao2",
		"west" : __DIR__"nandajie2",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
// 	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="east" && (!me->query("family") || me->query("combat_exp") < 1000000))
                return notify_fail("路中间竖着一个“小牌”，上面写到：闲杂人等，请勿进入。\n");
        return ::valid_leave(me,dir);
}
