//by dewbaby
//shishi2 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
{ 
         set ("short", YEL"明湖石室"NOR); 
         set ("long", @LONG 
        
这是一间布满灰尘的小石室，看上去已经很久没有人来过。
但是你朝青石地面上一望去，发现了几个模糊不清的脚印
(footprint)。
LONG); 
        
         
        set("exits", ([ /* sizeof() == 1 */ 
                     "west" : __DIR__"hudi3",       
        ])); 
        set("item_desc", ([
            "footprint" : "几个模糊不清的脚印。似乎可以擦干净(clean)。\n",
            "spell" : "一张小奇怪的小纸片，不知道上面写了什么，可以看(look)一下。\n",
        ]));
        set("no_clean_up",0);
        setup(); 
}

void init() 
{ 
            add_action("do_look","look"); 
            add_action("do_clean","clean"); 
} 

int do_clean(string arg)
{  
        object me;
        me=this_player();
        if(!arg || arg!="footprint") return 0;
        message_vision(HIY"$N俯下身，轻轻用身擦了擦地上的脚印。\n\n"HIW"突然你发现里面竟然有一间密室!\n"NOR,me);
        me->move(__DIR__"mishi1");
        tell_object(me,WHT"仿佛被密室中的什么东西吸引，你不由自主地走了进去!\n"NOR);
        return 1;
}


int do_look(string arg)
{      object me; 
       me=this_player();
       if(!arg || arg!="spell") return 0;
       message_vision(HIM"$N凑了过去，发现那是一张写满咒语的小纸片。\n",me,NOR);
       if (me->query("gender")!="女性")
       {
          message_vision(HIR"突然你发现自己被一团紫红妖气罩住...\n\n你渐渐失去了气力...\n\n你的视线越来越模糊...\n",me);
          me->delete_temp("last_damage_from");
          me->delete_temp("last_opponent");
          me->set_temp("death_msg","被一团神秘的紫火烧死了。\n");
          me->die();
       }
       else {
          me->move("/u/dewbaby/wangxian/hudi3");
            }
/*
}
   else {
     this_player()->start_busy(3);
     this_player()->set(sen, (int)me->query(max_sen));
     this_player()->set(eff_sen, (int)me->query(max_sen));
     this_player()->set(gin, (int)me->query(max_gin));
     this_player()->set(eff_gin, (int)me->query(max_gin));
     this_player()->set(eff_kee, (int)me->query(max_kee));
     message_vision(HIR"突然你发现自己被一团紫红妖气罩住...\n\n你渐渐失去了力气...\n\n你的视线越来越模糊...\n",me,NOR);
     me->delete_temp("last_damage_from");
     me->delete_temp("last_opponent");
     me->set_temp("death_msg","被一团神秘的紫火烧死了。);
             me->die();
}
*/
     return 1;
}
        
 

