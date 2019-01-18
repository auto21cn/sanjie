//in wangxian DIR
//cave1

#include <ansi.h>
inherit ROOM;
void create()
{
          set("short","竹楼岛");
          set("long",@LONG
月下亭西面，这里是一片荒废的竹楼。竹楼均架于碧波
之上。其中的一间竹楼边有一口干枯的老井，苦井边的
石墙上有一个大洞(dong)，里面黑漆漆的，不知道有什
么东西。�
LONG); 
         
           set("exits",([ /* sizeof() == 1 */
           "west" : __DIR__"yuexia",
           ]));
           set("item_desc",([
             "dong":"这洞里黑漆漆的一片，什么都看不到。\n",
           ]));        
          
           setup();
}

void init()
{
          add_action("do_enter","zuan");
          add_action("do_enter","enter");
}
          
int do_enter(string arg)
{
       object me = this_player();
       if(! arg || arg !="dong") return 0;
       if (me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着哪！\n");
       if (arg == "dong") {
               message("vision", me->name() + "一个溜身，钻进了黑洞。\n", environment(me), ({me}));
               write("你急匆匆地往洞中钻，却忽略了洞顶的石块，你疼得直想掉眼泪。\n");
                me->move(__DIR__"cave2");
               message("vision", me->name() + "钻了进来，头部撞到了山石上。\n", environment(me), ({me}));
               return 1;
       }
       return notify_fail("你往哪里钻啊？\n");       
}


