//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "铁匠铺");
        set ("long", @LONG

要打造出好兵器就得找到手艺高强的工匠，这里就是
远近闻名的兵器打造铺子，这里的老板可以帮你加工
出打造兵器所需的特殊材料。
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "west" : "/d/qujing/zhuzi/zhuzi3",
        ]));
        set("objects", ([  
                __DIR__"npc/boss" : 1,
        ])); 
        setup();
}
