
inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
                "east" : "/d/gao/daotian2",
                "southwest" : __DIR__"shulin2",
        ]));
        set("outdoors", 1);

        setup();
}

