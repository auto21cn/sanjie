//by dewbaby

//shanya   
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", YEL"小山崖"NOR); 
         set ("long", @LONG 
        
走过茂密如迷宫般的柳树林，你终于找到了一条
幽静的小路。这里很少有人来往，偶尔天边有离
群的大雁飞过。路的尽头是个小山崖，虽不很陡，
却依然让你不敢朝下望。
LONG); 
       
        set("outdoors", 2); 
        set("exits", ([ /* sizeof() == 1 */ 
        "southdown" : __DIR__"shulin9",
        ])); 
       
        setup(); 
      }


      void init() 
      { 
          add_action("do_jump", "jump"); 
      } 
   int do_jump(string arg)
      {   object me; 
          me=this_player(); 
       if(! arg || arg !="shanya") 
                 return notify_fail("你要往哪里跳?\n");

       if (me->is_busy() || me->is_fighting())
                 return notify_fail("你正忙着呢,不着急!\n");
       if (arg == "shanya") {
               message("vision", me->name() + "纵身跳入山崖中。\n", environment(me), ({me}));
  }
              if( ((int)me->query("kee") <= 400)&& 
              ((int)me->query("sen") <= 500)&&
              ((int)me->query("int") < 40) ) 
                 return
      message_vision(HIR"你只觉得身上一股力量被吸走了!\n"NOR,me); 
          me->receive_damage("kee",250);
           me->receive_wound("kee", 250);
          me->add("force",-200);
          me->start_busy(3);
          me->save();
   {
           message_vision(HIW"$N对自己充满信心，看都不看就纵身跳下山崖。\n"NOR, me); 
           me->move(__DIR__"jinse"); 
           message_vision("$N从崖上跳了下来。 \n", me); 
           return 1; 
      } 
}

