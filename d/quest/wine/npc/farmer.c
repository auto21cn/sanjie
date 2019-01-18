inherit NPC;
int ask_jiu (); 

void create()
{
        set_name("农夫", ({ "farmer" }) );
        set("gender", "男性" );
        set("age", 25+random(20));
        set("long", "你看到一位面色黝黑的农夫。\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "农夫叫道：杀人哪！杀人哪！\n",
                "农夫叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );
        set("inquiry", ([ 
            "高粱酒" : (: ask_jiu :), 
           ]) ); 

        setup();
        add_money("coin", 20);
}

int ask_jiu () 
{ 
         int tt; 
         object obj;
         object me=this_object();
         object who=this_player();
         tt=who->query("wine/gaoliang");
         if( tt) 
         { if(tt<=time() && time()<tt+1200) 
        { message_vision("\n"+me->query("name")+"说道：你刚要过酒，等等再来吧。\n",who); 
            return 1; } 
        }
         if (who->query("level")<20){
               command("say "+RANK_D->query_respect(who)+"还的继续努力呀，等你等级高了再来吧。 \n"); 
           return 1;}
         if ( !who->query("wine/start") || !present("jiu pai",who)) { 
               command("say 我这没有这种酒。 \n"); 
               return 1;} 
         if ( !who->query_temp("killshu")){
           command("sigh"); 
           command("say 唉....这年头老鼠成灾，田里的庄稼都被吃光了，如果你能帮我杀了祸害庄稼的老鼠精，我就用高粱酒款待你。 \n"); 
             return 1;}
          obj=new("/d/quest/wine/obj/gaoliangjiu");
          obj->move(who);
          who->set("wine/gaoliang",time());
          who->delete_temp("killshu");
          message_vision("$N给了$n一瓶"+obj->query("name")+"。\n", me,who);
            return 1; 
} 
