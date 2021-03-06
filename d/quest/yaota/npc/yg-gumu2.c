// created by kuku@sjsh
 
inherit NPC; 
#include <ansi.h>

string *list1=({
        "yaxe","yblade","yfork","yhammer","ymace","yspear","ystaff","ysick","ysword","ywhip",
});

string *list2=({
        "axe","blade","fork","hammer","mace","spear","staff","stick","sword","whip",
});

string *list3=({
        "yarmor","yboots","ycloth","yhands","yhead","yneck","yring","yshield","ysurcoat","ywaist","ywrists",
});

string *list4=({
        "armor","boots","cloth","hands","head","neck","ring","shield","surcoat","waist","wrists",
});

void setname() 
{ 
       mapping name;
       name=__DIR__"name"->random_name("yaoguai");
        set_name(name["name"], name["id"]);         
} 
       
void create(int value,int level) 
{ 
        setname(); 
        if(value==0) value=random(40)+10; 
//        if(level==0) level=random(40)+10; 
        level = 15;
        set("age", 100+random(80)); 
        set("gender", random(2)?"男性":"女性"); 
        set("attitude", "aggressive"); 
        set("per", random(20)+1); 
        set("str", 100); 
        set("cor", 40); 
        set("con", 40); 
        set("int", 40); 
        set("spi", 40); 
        set("cps", 40); 
        set("kar", 40); 
        set("max_gin", 1000);
        set("kee", value*200); 
        set("max_kee", value*200); 
        set("eff_kee", value*200); 
        set("sen", value*200); 
        set("max_sen", value*200); 
        set("eff_sen", value*200); 
        set("force", value*300); 
        set("max_force", value*300); 
        set("mana", value*300); 
        set("max_mana", value*300); 
        set("level",random(500)+1);
        set("combat_exp",level*1500000); 
        set("daoxing",level*1500000); 
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        
        set_skill("unarmed", level*20); 
        set_skill("dodge", level*20); 
        set_skill("force", level*20); 
        set_skill("spells", level*20); 
        set_skill("parry", level*20); 
        set_skill("jiuyin-zhua", level*20);
        set_skill("kongming-steps", level*20);
        set_skill("blade", level*20);
        set_skill("zizhi-blade", level*20);
        set_skill("jiuyin-force", level*20);
        set_skill("literate", 180);
        set_skill("youming-spells", level*20);
        map_skill("spells", "youming-spells");
        map_skill("force", "jiuyin-force");
        map_skill("unarmed", "jiuyin-zhua");
        map_skill("blade", "zizhi-blade");
        map_skill("parry", "zizhi-blade");
        map_skill("dodge", "kongming-steps");
        set("force_factor", level*10);
        set("mana_factor", level*10);
        
        set_temp("apply/armor", level*40); 
        set_temp("apply/damage", level*10); 
        set_temp("apply/attack", level*10); 
        set_temp("apply/dodge", level*10); 
        set_temp("apply/spells", level*10); 
        set_temp("apply/armor_vs_force",level*20); 
        set_temp("apply/armor_vs_spells",level*20); 
        create_family("轩辕古墓",2 , "弟子");
        set("no_steal",1); 
        set("taskguai",1); 
        set("chat_chance", 5);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade","lianhuan" :),
                (: perform_action, "blade","daoying" :),
        }) );
        setup(); 
        carry_object("/d/9ct/zb/tianjia")->wear();
        carry_object("/d/9ct/zb/blade")->wield();
} 

void init () 
{       
        object *t; 
        object me=this_object(); 
        object who=this_player(); 
        int t1; 
        
        
        if(!environment(me)->query("magicroom")) 
        {call_out("destructing",1);} 
        t1=query("stay_time"); 
        if(userp(who)) 
        kill_ob(who); 
        
} 

void destructing() 
{ 
        destruct(this_object()); 
} 
void heart_beat() 
{         
        object guai = this_object(); 
        
        if ( !is_fighting() 
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1) 
        && !query_skill("zixia-shengong",1) 
        && query("eff_kee") <  query("max_kee") ) 
        { 
            set("eff_kee",query("max_kee")); 
            set("eff_sen",query("max_sen")); 
        } 
        if (query("kee") < query("eff_kee")-10 ) 
            command("exert recover"); 
        if (query("sen") < query("eff_sen")-10) 
            command("exert refresh"); 
        if (query("force") < query("max_force")/10) 
            command("cast transfer"); 
      
        ::heart_beat(); 
} 
   
void kill_ob (object ob) 
{ 
        object me = this_object(); 
        ::kill_ob(ob); 
}


void reward()  
{ 
        object killer,newob; 
        int exp_reward,pot_reward,dx_reward,gold_reward,i,j;
        
        killer = this_object()->query_temp("last_damage_from"); 
        exp_reward = random(7000)+9000;
        dx_reward = random(7000)+9000;
        pot_reward = exp_reward/5;
        gold_reward = random(2000000)+3000000;
        j = sizeof(killer->query_team());

        if(random(100)>90){
                if(random(2)){  
                        for(i=0;i<random(4);i++){             
                                newob = new("/d/quest/zhuangbei/weapon/"+list2[random(sizeof(list2))]);                                                        
                                newob->move(environment(killer));       
                        }         
                }             
                else {
                        for(i=0;i<random(4);i++){   
                                newob = new("/d/quest/zhuangbei/armor/"+list4[random(sizeof(list4))]);             
                                newob->move(environment(killer));    
                        }                                           
                }  
        }
        else if(random(100)>85){
                if(random(2)){  
                        for(i=0;i<random(4);i++){             
                                newob = new("/d/quest/zhuangbei/weapon/yweapon/"+list1[random(sizeof(list1))]);                                                        
                                newob->move(environment(killer));       
                        }         
                }             
                else {
                        for(i=0;i<random(4);i++){   
                                newob = new("/d/quest/zhuangbei/armor/yarmor/"+list3[random(sizeof(list3))]);             
                                newob->move(environment(killer));    
                        }                                           
                }  
        }      
        if(random(100)>20){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("combat_exp",exp_reward/2);
                                killer->add("potential",pot_reward/2);
                                killer->add("daoxing",dx_reward/2);
                                tell_object(killer,HIY"你得到了"+COMBAT_D->chinese_daoxing(dx_reward/2)+"道行和"+exp_reward/2+"点武学经验以及"+pot_reward/2+"点潜能的奖励。\n" NOR); 
                        }
                        else {
                                killer->add("combat_exp",exp_reward/2*(j-1));
                                killer->add("potential",pot_reward/2*(j-1));
                                killer->add("daoxing",dx_reward/2*(j-1));
                                tell_object(killer,HIY"你得到了"+COMBAT_D->chinese_daoxing(dx_reward/2*(j-1))+"道行和"+exp_reward/2*(j-1)+"点武学经验以及"+pot_reward/2*(j-1)+"点潜能的奖励。\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("combat_exp",exp_reward);
                        killer->add("potential",pot_reward);
                        killer->add("daoxing",dx_reward);
                        tell_object(killer,HIY"你得到了"+COMBAT_D->chinese_daoxing(dx_reward)+"道行和"+exp_reward+"点武学经验以及"+pot_reward+"点潜能的奖励。\n" NOR); 
                }
        } 
        if(random(100)>95){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("balance",gold_reward/2);
                                tell_object(killer,HIY"你得到了"+MONEY_D->money_str(gold_reward/2)+"的奖励。\n" NOR); 
                        }
                        else {
                                killer->add("balance",gold_reward/2*(j-1));
                                tell_object(killer,HIY"你得到了"+MONEY_D->money_str(gold_reward/2*(j-1))+"的奖励。\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("balance",gold_reward);
                        tell_object(killer,HIY"除了战斗所得，你还得到了"+MONEY_D->money_str(gold_reward)+"的奖励。\n" NOR); 
                }
        }               
}  
