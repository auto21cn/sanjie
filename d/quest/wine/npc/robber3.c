// robber for dart

#include <ansi.h>
inherit NPC;
void copy_status(object me, int level); 
void set_skills(int max_value, int level); 
void set_hp_status(object me, int level); 
#include "robber.h"

void create()
{ 
        set_name(HIW"�ٷ�"NOR,({"robber"}));
        set("long","����һλ��˿����ͽ��\n");
        set("title","��·����");
        set("gender", "����" );
        set("age", random(30)+14);
        set("vendetta/authority", 1);
        create_family("��˿��", 2, "����");
         
        setup();
        carry_object("/d/pansi/obj/yinsuo")->wield();
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
               while(i--) { // �ҳ����skill���ֵ 
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
                set_skill("whip", guai_value+random(16)); 
                set_skill("dodge", guai_value+random(16)); 
                set_skill("parry", guai_value+random(16)); 
                set_skill("force", guai_value+random(16)); 
                set_skill("spells", guai_value+20+random(16)); 
                set_skill("literate", guai_value+20+random(16)); 
                set_skill("pansi-dafa", guai_value+20+random(16)); 
        set_skill("lanhua-shou", guai_value+20+random(16)); 
                set_skill("jiuyin-xinjing", guai_value+20+random(16)); 
                set_skill("yinsuo-jinling", guai_value+20+random(16)); 
                set_skill("yueying-wubu", guai_value+20+random(16)); 
                map_skill("spells", "pansi-dafa"); 
        map_skill("unarmed", "lanhua-shou"); 
                map_skill("force", "jiuyin-xinjing"); 
                map_skill("whip", "yinsuo-jinling"); 
                map_skill("parry", "yinsuo-jinling"); 
                map_skill("dodge", "yueying-wubu"); 
                set("chat_chance_combat", 50); 
                set("chat_msg_combat", ({ 
            (: perform_action, "whip","wang" :),
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
