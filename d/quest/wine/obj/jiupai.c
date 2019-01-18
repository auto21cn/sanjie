//  by kuku@sjsh 2002.12
//  /d/quest/wine/obj/jiupai.c  

#include <ansi.h> 
inherit ITEM; 

void create() 
{ 
        set_name(HIM "酒牌" NOR, ({ "jiu pai","pai" }));  
        set_weight(10); 
        set("long", "这是一枚闪着金属光泽的铜牌，不知道有什么用处。\n" ); 
        if( clonep() ) 
                set_default_object(__FILE__); 
                else { 
                    set("no_sell",1); 
                    set("value",0); 
                    set("no_give",1);  
                    set("no_put",1);  
                    set("no_get",1);
                    set("no_steal",1);
                    set("unit","枚");  
                  } 
               setup(); 
           call_out("destruct_me",3600);
}

void destruct_me()
{ 
       destruct (this_object());
} 
     
void init()
{
         object me = this_object();
        object who = this_player();
        object where = environment(); 
        if (! me->query("my_owner") && interactive (who))
                me->set("my_owner",who->query("id"));
        if (userp(where)){
                if (me->query("owned")){
                        if (me->query("owned")!=where->query("id")){
                                call_out("destruct_me",1);
                        }
                } 
                else{
                        me->set("owned",where->query("id"));
                }
        }        
}
