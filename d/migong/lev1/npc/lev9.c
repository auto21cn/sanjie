// migong lev1

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小贼", ({ "xiao zei", "zei" }));
        set("race", "人类");
        set("gender", "男性" );
        set("long",
"一个手脚灵快，专干偷鸡摸狗勾当的小混混。\n");
        set("attitude", "aggressive");      
        set("vendetta/authority",1); 
        set("force_factor",50+random(50));
        set("mana_factor",50+random(50));
        set("max_kee",4500+random(1500));
        set("max_force",1000+random(700)); 
        set("max_sen",3500+random(1500));
        set("max_mana",1000+random(700));
        set("mana",2000+random(700));
        set("force",2000+random(700));
        set("per", 1);
        set("int", 60);
        set("cor", 40);
        set("age", 22);
        set("combat_exp", 800000);  
        set("daoxing", 800000);  
        set("chat_chance", 40);    
        set("chat_msg", ({         
            "小贼喝道：竟然追到这里来了！！\n",              
        }) );
      
        set_skill("unarmed", 200);
        set_skill("blade", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);     
        set_skill("force", 200);       
        set_temp("apply/attack", 70);      
        set_temp("ap5ly/defense", 70);     
        set_temp("apply/armor", 70);      
        set_temp("apply/damage", 70);       
        setup();       
        carry_object("/d/obj/armor/yinjia")->wear();    
        carry_object("/d/obj/weapon/blade/gudingdao")->wield();
        add_money("gold", random(2));

}

void init( )
{
        object ob;      
        remove_call_out("hunting");
        if( interactive(ob = this_player())  ) 
        {
                call_out("hunting",1);
        }
        if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) 
        {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) 
                continue;
                if(ob[i]->query("vendetta/authority")) 
                continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

