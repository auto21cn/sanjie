
inherit F_VENDOR_SALE;
int ask_heal();
string ask_job();

void create()
{
        reload("city_yanglangzhong");
        set_name("杨郎中", ({"yang langzhong", "yang", "boss"}));
        set("title", "药铺掌柜");
        set("gender", "男性");
        set("age", 37);
        set("long",
"杨郎中是长安城里祖传的名医。虽然年轻，却早已名声在外。\n");
        set("kee", 900); 
        set("max_kee", 900);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
//      set("env/wimpy", 50);

        set("inquiry", ([
        "疗伤": (: ask_heal :),
        "治疗": (: ask_heal :),
        "heal": (: ask_heal :),
        "job" : (: ask_job :),
        "工作": (: ask_job :),
        ]) );

        set("vendor_goods", ([
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
                "yanlei": "/d/obj/drug/yanlei",
                "tao" : "/d/obj/drug/mihoutao",
                "wan" : "/d/wizz/junhyun/obj/wan",
        ]) );

        set_skill("literate", 120);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        (: command("say 这段时间总感觉自己老了，干活力不从心。看来要找人帮我磨药才行！\n") :),
        (: command("say 请来的小伙子干活还挺卖力的，真是长江后浪推前浪,不认老都不行了！\n") :),
         }) );
    
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 30);
}

int ask_heal()
{
        object ob;
        ob=this_player();
        if ((int)ob->query("mud_age")>800000 )
        {
        command("say 你应该自己去把医术学精点好自己给自己弄了！\n");
        return 1;
        }
        
       
        if ((int)ob->query("eff_kee") == (int)ob->query("max_kee")
                && (int)ob->query("eff_sen") == (int)ob->query("max_sen"))
        {
                command("?"+ob->query("id"));     
                  command("say 你根本没受伤，跑我这里添乱！\n");
                command("knock"+ob->query("id"));
                return 1;
        }
        else
        {
                message_vision("杨掌柜拿出一根银针轻轻捻入$N受伤的部位附近的穴道，$N感觉舒服多了。\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
        }
        
int recover(object ob)
{
        if (!objectp(ob)) return 0; // mudring Dec/10/2002
        ob->set("eff_kee", (int)ob->query("max_kee"));
        ob->set("eff_sen", (int)ob->query("max_sen"));  
        message_vision("一柱香的工夫过去了，你觉得伤势已经基本痊愈了。\n",ob);
        command("say 江湖险恶,不小心的话，下次你就没这么幸运了。\n");
        command("pat"+ob->query("id"));
        return 1;
}

void init()
{
        object ob;

       ::init();
        add_action("do_vendor_list", "list");

}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}


string ask_job()
{
        object ob;
        ob=this_player();
        if (ob->query("combat_exp")<100000)
                return "我的工作你现在还做不了吧！";
        if (ob->query("combat_exp")>180000)
                return "以你的本事已经不用在我这工作了！";
        if (ob->query("job_moyao") >0)
                return "我交给你的事情你还没做呢！";
        ob->set("job_moyao",1);
                return "好吧，你就帮我磨药(moyao)吧！";
}

