// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第三宫：黄道酉宫");
        set ("long", @LONG
 鸡其实是最准时的，古时候人们就靠鸡鸣知道天亮了该起床了，所以属鸡的人约会都很准时！
 
LONG);


        set("exits", ([
        "southup"    :       __DIR__"sz2jx1",
        "westdown"  :       __DIR__"jn2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("xiaoji jun") && dir == "southup" )
        return notify_fail("肖鸡星戍冷笑:先过我这关再说！\n");
        return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
