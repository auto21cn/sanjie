//cave3

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIM"绯月洞"NOR);
        set("long", @LONG
爬了半天，你发现自己似乎到了月下亭下面。这里无人无物，
只有那如诉如泣的琴声在空气中来回飘荡。
LONG);
 
        
        setup();
 
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_jump", "jump");
}
int do_climb(string arg)
{
       object me = this_player();

       if (arg != "up" ) return 0;
           if (!living(me)) return 0; 
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
     return notify_fail("你身上的东西太多，恐怕爬不上去吧？！\n");
       if((int)me->query_skill("dodge",1) < 80 )  
       return notify_fail("以你目前的轻功修为，很难爬上去。\n"); 
       message_vision("$N扒住岩石，小心的爬了上去。\n", me);
        me->move(__DIR__"shishi3");
       tell_room(environment(me), me->name() + "从绯月洞里爬了上来。\n", ({ me }));
       return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
        if (arg != "river" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;
       message_vision("$N纵身跳入一条小河。哎呀，不要自杀呀！\n", me);
         me->move(__DIR__"xiaohe1");
       tell_room(environment(me), me->name() + "从绯月洞里跳了进来。\n", ({ me }));
       return 1;
}

