//Cracked by Roath
// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "南海之滨");
  set ("long", @LONG

南海之滨。往北是一条宽阔笔直的官道，足可容得下十马并驰。
往南则是一片汪洋大海，不知通向何方。西南海面上隐隐可见
一小岛。浅海近岸处还有几个游泳的人。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway5",
"west" : "/d/jz/egate",
  "east" : __DIR__"seashore1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object  me, horse;
	me = this_player();
/*        
	if(me->query_temp("ridee")){
		horse=me->query_temp("ridee");
		me->command_function("dismount "+horse->query("id"));
	}
*/


//               if(me->query("force") < 60)  
//               return notify_fail("你没有内力，会真气外泻的！\n");  
              if(me->query("kee") < 60)  
                      return notify_fail("你的气血不够，无法去对岸了！\n");  
              if(me->query("sen") < 60)  
                      return notify_fail("你的精神不够，无法游到对岸！\n");  
message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了海中小岛上。\n" NOR, me);
        me->move("/d/nanhai/island");
        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 35);
        me->receive_damage("sen", 30);
        return 1;
}




