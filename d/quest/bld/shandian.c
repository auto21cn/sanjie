//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","华山之巅");
        set ("long", @LONG

这里是华山最高之处，望下看去，苍松翠柏，河流山峦尽收眼底，
真是美不胜哉！不过这里有快石头比较特殊----又高又大，下面
还好象有个洞口。听说下面压着三圣母娘娘，必须找到神斧才能
劈（pi）开石头救出她来！
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu7",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_pi", "pi");
}

int do_pi(string arg)
{       
        object me=this_player();
        object axe;

        if(!(axe=present("shen fu", me)))
        return notify_fail("你没"+HIR"神斧"NOR+"怎么劈山？ \n");

        if (me->query("bld/done") ==1)
        return notify_fail("干吗？老劈山？山都给你辟坏了！ \n");
     
        if (me->query("bld/erlang") !=1 || me->query("bld/dog") !=1)
        return notify_fail("没地方玩了？旁边玩去！ \n");
        
        if (arg!= "stone")
        return notify_fail("你要劈什么？ \n");

        message_vision(HIR"神斧"NOR+"带着一道红光朝巨石劈去！ \n",me);
        message_vision("只听见“轰”的一声，"+HIR"神斧"NOR+"没入石头，石头也分开了，露出了一个洞，你钻了进去！ \n",me);
        message_vision("你刚进去，又是“轰”的一声，石头又复原了！ \n",me);
        me->set("bld/pi",1);
        destruct(present("shen fu", me));
me->move("/d/quest/bld/shandong");
        return 1;
}

