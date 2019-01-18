
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里就是〖神谷道场〗的大厅，只见一张板桌上供着一副对联(duilian)。
似乎对联后面有个秘道。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
	"south" : __DIR__"road1",
	]));
	set("item_desc", ([
"duilian":
HIC "\n\n飞天御剑  不断今朝绕指柔情\n" NOR +
HIG "\n人斩拔刀  未绝昨日棰心痛恨\n" NOR,
	]));
	set("objects", ([
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，发现西面石壁上有一道裂缝，似乎可以钻(zuan)出去。\n"
             );
             this_player()->set_temp("marks/钻", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/钻") ) {
            message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n",
                    environment(me), ({me}) );
            me->move(__DIR__"cave");
            message("vision", me->name() + "从石缝里钻了出来。\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/钻", 0);

            return 1;
        }
        else {
            write("你想往哪儿钻?!\n");
            return 1;
        }
}
