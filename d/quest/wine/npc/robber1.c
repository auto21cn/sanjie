// robber for dart

#include <ansi.h>
inherit NPC;
void copy_status(object me, int level); 
void set_skills(int max_value, int level); 
void set_hp_status(object me, int level); 
#include "robber.h"

void create()
{ 
        set_name(HIW"劫匪"NOR,({"robber"}));
        set("long","这是一位五庄观弃徒。\n");
        set("title","拦路抢劫");
        set("gender", "男性" );
        set("age", random(30)+14);
        set("vendetta/authority", 1);
        create_family("五庄观", 2, "弟子");
         
        setup();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

void copy_status(object me, int level) 
{ 
        mapping me_skill; 
        int *skill_value, max_value, i; 

        me_skill = me->query_skills(); 
        i=sizeof(me_skill); 
           if(i>0) { 
               skill_value=values(me_skill); 
               max_value=skill_value[0]; 
               while(i--) { // 找出玩家skill最大值 
               if(skill_value[i]>max_value) 
                max_value=skill_value[i]; 
                        } 
                  } else max_value=1; 
                set_skills(max_value, level); 
                set_hp_status(me,level); 
}          
      
void set_skills(int max_value, int level) 
{ 
        object guai=this_object();        
        int guai_value; 
         level = random(10); 
             if (level<5) level=1; 
             else if (level<8) level=2; 
             else level=3; 
        if (level==1) guai_value = max_value+max_value/8; 
                else if (level==2) guai_value = max_value+max_value/6; 
                else guai_value = max_value+max_value/4; 
                set_skill("unarmed", guai_value+random(16)); 
                set_skill("sword", guai_value+random(16)); 
                set_skill("dodge", guai_value+random(16)); 
                set_skill("parry", guai_value+random(16)); 
                set_skill("force", guai_value+random(16)); 
                set_skill("spells", guai_value+20+random(16)); 
                set_skill("literate", guai_value+20+random(16)); 
                set_skill("taiyi", guai_value+20+random(16)); 
                set_skill("hunyuan-zhang", guai_value+20+random(16)); 
                set_skill("zhenyuan-force", guai_value+20+random(16)); 
                set_skill("sanqing-jian", guai_value+20+random(16)); 
                set_skill("baguazhen", guai_value+20+random(16)); 
                map_skill("spells", "taiyi"); 
                map_skill("unarmed", "jienan-zhi"); 
                map_skill("force", "zhenyuan-force"); 
                map_skill("sword", "sanqing-jian"); 
                map_skill("parry", "sanqing-jian"); 
                map_skill("dodge", "baguazhen"); 
                set("chat_chance_combat", 50); 
                set("chat_msg_combat", ({ 
            (: cast_spell, "zhenhuo" :), 
            (: perform_action, "sword","jianzhang" :),
                  }) ); 
}        

void set_hp_status(object me, int level) 
{       
        int max_kee,max_sen,skill_force,maximum_mana,exp,daoxing; 
        max_kee = me->query("max_kee"); 
        max_sen = me->query("max_sen"); 
        skill_force = query_skill("force"); 
        maximum_mana = me->query("max_mana"); 
        exp = me->query("combat_exp"); 
        daoxing = me->query("daoxing"); 

        set("max_force", skill_force*10); 
        set("force", skill_force*20); 
        set("force_factor", skill_force/10); 
        set("mana_factor", query_skill("spells")/10); 
 
        if (exp < 8000000) 
         { 
              set("max_kee", max_kee*2); 
              set("eff_kee", max_kee*2); 
              set("max_sen", max_sen*2); 
              set("eff_sen", max_sen*2); 
              set("kee", max_kee*2); 
              set("sen", max_sen*2); 
              set("max_mana", maximum_mana); 
              set("mana",maximum_mana); 
              set("combat_exp", exp+exp*1/16+random(exp*1/16)); 
              set("daoxing", daoxing+daoxing*1/13+random(daoxing*1/16)); 
                 set_temp("apply/armor", 400); 
                 set_temp("apply/damage", 100); 
         } 
               else  
                 { 
                    set("max_kee", max_kee*2); 
                    set("eff_kee", max_kee*2); 
                    set("max_sen", max_sen*2); 
                    set("eff_sen", max_sen*2); 
                    set("kee", max_kee*3/2); 
                    set("sen", max_sen*3/2); 
                    set("max_mana", maximum_mana); 
                    set("mana",maximum_mana); 
                    set("combat_exp", exp+exp*1/12+random(exp*1/12)); 
                    set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12)); 
                    set_temp("apply/armor",300); 
                    set_temp("apply/damage", 150); 
                }    
} 
