// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "密林宝库");
        set ("long", @LONG
    这里是密林的最秘密的地方---密林宝库,据说这里的宝贝
都是女涡娘娘曾经使做的,但是后来一直没怎么用过,日久天长
也便忘了这些宝贝的存在。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "out" : "/d/milin/qy/mishi1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/npc/obj/sword" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
