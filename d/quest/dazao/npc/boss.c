// Created by kuku@sjsh  2003.2
// 加工打造兵器原料npc

#include <ansi.h>
inherit NPC;
int ask_jiagong();

string *metal1=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze"});
string *metal2=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper"});
string *metal3=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel"});
string *metal4=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel"});
string *metal5=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel","/d/quest/dazao/material2/whitesilver","/d/quest/dazao/material2/whitegold"});
string *metal6=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel","/d/quest/dazao/material2/whitesilver","/d/quest/dazao/material2/whitegold","/d/quest/dazao/material2/yellowgold","/d/quest/dazao/material2/purplegold"});

void create()
{
        set_name("老板", ({"lao ban", "boss"}));
        set("age", 52);
        set("title","铁匠铺");
        set("gender", "男性");
        set("int", 35);
        set("long","江湖人士想要打造出好兵器先要找他加工出原料。\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("daoxing", 100000);
        set("max_force", 400);
        set("force", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
        set("inquiry", ([  
                "加工" : (: ask_jiagong :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        tell_object(who,"这位"+RANK_D->query_respect(who)+"，你是来加工(ask boss about 加工)矿石的吗？\n");  
}

int ask_jiagong()
{       
        int i;
        object *inv; 
        object me = this_player();
        object ob = this_object();
                
        if( !me || environment(me) != environment() ) return 0;
        
        if( me->is_busy() || me->is_fighting() ){
                command("say 你先忙完再说吧。\n");
                return 1;
        }
     
        if( ob->is_busy() || ob->is_fighting() ){
                command("say 先等等，我正忙着呢。\n");
                return 1;
        }

        if( me->query("balance") < 1000000){ 
                command("say 你的存款不够付定金啊，等攒够钱再来吧。\n");  
                return 1; 
        }
       
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query_temp("wakuang/owned")){
                        me->add("balance",-(200000+random(300000)));
                        message_vision("$N给了$n一"+inv[i]->query("unit")+inv[i]->query("name")+"！\n", me,this_object());
                        message_vision(CYN"$N皱了皱眉头，最后不得已还是给了$n一些钱。\n"NOR,me,ob); 
                        command("say 稍等片刻，一会给你加工出来的东西。\n");
                        ob->start_busy(11);
                        call_out("finish_jiagong",10,me);
                        ob->stop_busy();     
                        return 1;                   
                }
                else{
                        command("say 你身上没有矿石怎么加工？\n");
                        return 1;
                }
        }               
        
        return 1;
}
int finish_jiagong(object me)
{
        object ob = this_object();
        object newob;
        int i;
        object *inv; 
        
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                switch(inv[i]->query_temp("wakuang/owned")){
                        case 7:                         
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal6[random(13)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 6:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal5[random(11)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 5:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal4[random(9)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 4:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal3[random(7)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 3:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal2[random(5)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 2:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new(metal1[random(3)]);
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 1:
                                command("say 你要的东西加工好了。\n");
                                destruct(inv[i]);
                                newob=new("/d/quest/dazao/material2/yellowcopper");
                                message_vision("$N给了$n一"+newob->query("unit")+newob->query("name")+"。\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                        default: break;
                }
        }
        return 1;
}
