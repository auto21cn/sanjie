// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第二宫：黄道戍宫");
         set ("long", @LONG
  狗是人类最亲密最喜爱的动物，更是人类最忠实的朋友，上天给它任务是对人忠实摇尾巴，
  狗绝不会嫌主人穷而易主，这是它忠贞不二恒久不变的天性，所以常常听说灵犬救主的故事，
  所以凡遭众犬围攻的人，一定是坏人，一定要关起来，故此“狱”字左右以犬夹击而组成。

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("xiaogou jun") && dir == "westup" )
        return notify_fail("肖犬星戍笑道:先过我这关再说！\n");
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
