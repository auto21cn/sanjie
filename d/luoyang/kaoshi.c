inherit ROOM;

void create()
{
        set("short", "科举试场");
        set("long", @LONG
洛阳的科举试场是天下最热闹的一所考场，每月初一，全国各地的士
子都来此处赶考。院门两边由士兵看守，要想夹带可不行，围墙上有张新
贴的告示。
LONG);
        set("objects", ([
                "/d/luoyang/npc/shusheng1" : 2,
                "/d/luoyang/npc/shusheng2" : 2,
        ]));
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"nroad3",
        ]));

        setup();
        replace_program(ROOM);
}

