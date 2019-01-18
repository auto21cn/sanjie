// 九重天 一重 傲野天 by Calvin

#include <ansi.h>
inherit ROOM;
// inherit "/d/9ct/climbtree.c"; 
#include <banned.h>
string *list=({
        "9ctguai1","9ctguai2",
});

void create ()
{
        int num = random(3)+1;
  set ("short", HIW"一重·傲野天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※莫过天涯胜此处  依雪逍遥域仙羡※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);
        set("exits", ([   
                "up" : __DIR__"tree1",
                "west" : __DIR__"baoku1",
        ]));
        set("objects", ([   
                __DIR__"npc/9ctguai1" : 1,
                __DIR__"npc/9ctguai2" : 2,
        ]));
        set("npc_num",num);
        set("alternative_die",1);
        set("9ctroom",1);  
        set_heart_beat(240);

        setup();
}

void heart_beat()
{      
        reset();
}

void reset() 
{
        object guai;
        int i;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;i<this_object()->query("npc_num");i++) { 
                                guai = new("/d/9ct/npc/"+list[random(sizeof(list))]);
                                guai->move(this_object());
                        }
                }
        }       
        ::reset();
}

void init() 
{  
        object me=this_player();
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        add_action("do_climb","climb");
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
       
        if( !wizardp(me) && userp(me) ) {        
                remove_call_out("kick_ob");
                call_out("kick_ob",60);
        }
}  

void kick_ob()
{
        object room,*obj;
        int i;

        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("sky_enter_time"))>1800){
                        message_vision(CYN"一阵清风吹来,清烟消散,$N也随着清烟散去！\n"NOR,obj[i]);
                        if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj[i]->dismiss_team(); 
                        message("vision",CYN"一个人影随着一阵清烟从魔幻世界飘了出来!\n"NOR,room,({obj[i]}));
                        call_out("kick_ob",60);
                        return;
                }
        }
        call_out("kick_ob",60);
}

int do_quit(string arg) 
{  
        write("进来了就老老实实的吧，你只有一条路可走。\n");  
        if (wizardp(this_player())) write("禁止使用此命令。\n");  
                return 1;  
}   

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("你不能在这里用这条命令。\n");    
        command("cast transfer");
        return 1;
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}

int do_climb(string arg)
{
        object tianshen; 
        object me=this_player();

        if( (!arg) || !((arg == "sky") || (arg == "九重天")))
                return notify_fail("登什么？\n");
        if (me->is_busy()) 
                return notify_fail("你现在正忙着呢。");
        if( me->query("kee") < (int)(me->query("max_kee")/3)){
                me->receive_damage("kee",(int)me->query("max_kee")*20/100);
                return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
        }
        else{
                if ((int)me->query_skill("dodge", 1)<60 && (int)me->query_skill("moondance", 1) < 200){
                        message_vision("$N小心翼翼的往上攀登了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
                        me->improve_skill("dodge", 60-me->query("str"));
                        tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
                }
                else{
                        message_vision("$N轻轻地一腾就上了树藤,一会便消失在无尽的香花之中了。\n", me);
                        me->move(__DIR__"er");
                }
        }
        me->receive_damage("kee", (int)me->query("max_kee")*10/100);
        return 1;
}

void alternative_die(object who)  
{  
        object killer,corpse;  
                
        killer = who->query_temp("last_damage_from");          
           
        if (userp(who)) {  
                message_vision("$N死了。\n",who);  
                who->set("kee",10); who->set("sen",10);  
                if(who->query("eff_kee")<10) who->set("eff_kee",10);  
                if(who->query("eff_sen")<10) who->set("eff_sen",10);           
                if(!killer) killer=who; 
//        if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
//                corpse->move(this_object());  
                all_inventory(this_object())->remove_killer(who);               
                who->remove_ride();  
                who->dismiss_team();  
                who->delete_temp("last_fainted_from");  
                who->move("/d/city/kezhan");  
        }  
        else {  
                if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
                        corpse->move(this_object());  
                message_vision("$N死了。\n",who);  
                who->reward();       
                destruct(who);  
        }          
}

int valid_leave(object me, string dir)
{
        object a;        
                
        if (dir == "up" ) {
                if(objectp(a=present("tianshen", environment(me))) && living(a) )
                        return notify_fail("妖怪拦住你说道:有我在你哪也别想去！\n");
        }   

        return ::valid_leave(me, dir);
}
