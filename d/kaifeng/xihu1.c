//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "西湖路");
  set ("long", @LONG

一条小路沿着湖边蜿蜒盘绕，西边的湖水浑浊一点，风吹过湖水荡漾
杨柳微拂，在湖水上晃动着长长的倒影。不时有莺歌鸟鸣声声传来，
令人心旷神怡。

LONG);

  set("exits", ([
        "east" : __DIR__"xihu2",
        "southwest" : __DIR__"xihu3",
      ]));

  set("outdoors", __DIR__);

  setup();
}


/*
void init()
{
    add_action("do_dive", "dive");
}
int do_dive()
{   object me,ridee;
        me=this_player();
     ridee=me->ride();
            if( (!present("bishui zhou", me)) &&
            (!((string)me->query("family/family_name")=="东海龙宫")) )
                return
notify_fail("你一个猛子扎到水里．．．\n\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

   if (ridee && ridee->query("under_water")) {
     message_vision("$N一拍$n的头，连人带马跃入水中。\n",me,ridee);
     ridee->move("/d/quest/m_weapon/tan/tan1");
   }
    else
                message_vision("$N一个猛子扎到水中，然后不见了．\n", me);
                me->move("/d/quest/m_weapon/tan/tan1");
                message_vision("$N游了过来。\n", me);
                return 1;
}

*/
