//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","悬崖");
        set ("long", @LONG

这里是华山的最大的悬崖。向下看去，好象有什么东西在下面，你
可以（jump）下去看看。
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "southdown" : __DIR__"shanbian1",
        //        "south" : __DIR__"wuwai",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{       
        if (arg!= "xuanya" && arg!= "ya" )
        return notify_fail("你要跳什么？ \n");

this_player()->move("/d/quest/bld/wuwai");
        message_vision("只见$N纵身一跃，跳下了万丈悬崖。\n",this_player());

        return 1;
}

