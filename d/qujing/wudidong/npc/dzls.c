// Created by kuku@sjsh  2003.2
// 无底洞负责给书的npc 

inherit NPC;
int ask_book();
int ask_blade();
string book="/d/obj/book/kugu-";

void create()
{
        set_name("打杂老鼠", ({"daza laoshu", "laoshu"}));
        set("age", 22);
        set("title","无底洞");
        set("gender", "男性");
        set("int", 35);
        set("long","它是无底洞专门负责发书和刀的老鼠，如果你是无底洞弟子要看书学习最好找它。\n");
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
                "book": (: ask_book :),
                "blade": (: ask_blade :),
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
        if( who->query("family/family_name")!= "陷空山无底洞" ) return;
        tell_object(who,"打杂老鼠悄悄告诉你：想要无底洞的宝物吗？这里有空白帐本(ask laoshu about book)和枯骨刀(ask laoshu about blade)。\n");  
}

int ask_book()
{       
        object shu1,shu2,shu3;
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("family") || me->query("family/family_name")!= "陷空山无底洞" ){
                write("要想要这个先加入无底洞吧。\n");
                return 1;
        }
        
        if ( present("zhang ben", me) || present("xue shu", me) ){
                write("你不是已经有了嘛，还要？\n");
                return 1;
        }
        
        if((book+"1")->in_mud() == 0){
                shu1=new(book+"1");
                shu1->move(me);
        }
        else if((book+"2")->in_mud() == 0){
                shu2=new(book+"2");
                shu2->move(me);
        }
        else if((book+"3")->in_mud() == 0){
                shu3=new(book+"3");
                shu3->move(me);
        }
 
        else{
                command("say 现在三个帐本有人拿，你过些时候再来要吧。\n");  
                return 1;
        }
                
        message_vision("$N给了$n一本空白帐本。\n", ob,me);
        command("pat " +me->query("id"));  
        command("say 好好学习吧，无底洞的光大就靠你们啦。\n");  
        return 1;
}

int ask_blade()
{       
        object dao;
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("family") || me->query("family/family_name")!= "陷空山无底洞" ){
                write("要想要这个先加入无底洞吧。\n");
                return 1;
        }
                
        if ( present("kugu dao", me) ){
                write("你不是已经有了嘛，还要？\n");
                return 1;
        }
        
        if( "/d/obj/weapon/blade/kugudao"->in_mud() == 0 ) {
                dao= new("/d/obj/weapon/blade/kugudao");
                dao->move(me);
        }
        else{
                command("say 有人已经拿了枯骨刀，你过些时候再来要吧。\n");  
                return 1;
        }
        message_vision("$N给了$n一把枯骨刀。\n", ob,me);
        command("pat " +me->query("id"));  
        command("say 好好练功喔，无底洞的光大就靠你们啦。\n");  
        return 1;
}
