// Created By stey

inherit NPC;

#include <ansi.h>
//#include "pfm.h"
mapping hellskill=([
   "sword":100,"blade":100,"hammer":100,"staff":100,"whip":100,
   "axe":100,  "fork":100,"spear":100,"mace":100,"stick":100,"unarmed":100,"dodge":100,
]);
string *w_type=({
     "sword","spear","axe","hammer","stick","blade","staff","whip","mace","fork",
});
string *names1 = ({
  "大","da",
  "小","xiao",
  "双","shuang",
  "单","dan",
  "三","san",
  "五","wu",
  "六","liu",
  "四","si",
});

string *names2 = ({
  "头","tou",
  "尾","wei",
  "脚","jiao",
  "爪","zhua",
  "嘴","zui",
  "牙","ya",
});

string *names3 = ({
  "怪","guai",
  "僵尸","deadman",
  "暗黑使者","hellkiller",
  "血魔","xuemo",
  "毒龙","dragon",
  "屠夫","bakker",
  "毛头","badkid",
  "黑龙","blackdragon",
  "毒巫","duwu"
});

string *names4 = ({
  "吸血","xixue",
  "毒蜘蛛","zhizhu",
  "恶犬","equan",
  "蝙蝠","bianfu",
  "毒蝎子","xiezi",
  "蟾蜍","chanchu",
  "血蜈蚣","wugong",
  "飞蝗","feihuang",
  "蝗虫","huangchong",
  "蜘蛛","zhizhu",
  "巨蟒","jumang",
});

void setname1()
{
    int i,j,k;
    string name, *id;

    i=(random(sizeof(names1)/2))*2;
    j=(random(sizeof(names2)/2))*2;
    k=(random(sizeof(names3)/2))*2;

    name=names1[i]+names2[j]+names3[k];
    id=({names1[i+1]+names2[j+1]+" "+
      names3[k+1], names3[k+1]});

    set_name(name,id);



    set("magic_tpye",0);
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/2))*2;
    j=random(2);

    name=names4[i]+(j?"魔者":"巫术师");
    id=({names4[i+1]+" "+(j?"motou":"magickiller"),
      (j?"killer":"magickiller")});

    set_name(name,id);
    set("magic_type",random(10)+5);
}

void setskill()
{
        string *kk,*type;
     int i;
        type=({"刀剑侠" ,"魔法师" ,"终结者" ,"精灵族","暗黑地狱使者","野蛮人" ,});     
                
                
        kk=keys(hellskill);
        for(i=0;i<sizeof(kk);i++)
        {       
                set("hell_skill/"+kk[i],hellskill[kk[i]] );
        }       
        set("hell_exp",100000);
        set("level",100);
        set("hell_type",type[random(sizeof(type))]);
}

void create(int level,int value)
{


    //void set_skills(int max_value, int level)

    if(random(2)==0)
        setname1();
    else
        setname2();

    if(value==0) value=random(10)+10;
    if(level==0) level=random(10)+10;




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
    set("kee", value*100);
    set("max_kee", value*100);
    set("eff_kee", value*100);
    set("sen", value*100);
    set("max_sen", value*100);
    set("eff_sen", value*100);
    set("force", value*400);
    set("max_force", value*400);
    set("mana", value*400);
    set("max_mana", value*400);
    set("force_factor", value*40);
    set("mana_factor", value*40);
   set("levelup",2+random(4));
    set("level",random(500)+1);
    set("combat_exp",value*300000);
    set("daoxing",value*300000);
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set_skill("changquan", level*20);
    set_skill("yanxing-steps", level*20);
    set_skill("spear", level*20);
    set_skill("bawang-qiang", level*20);
    set_skill("lengquan-force", level*20);
    set_skill("literate", 180);
    set_skill("baguazhou", level*20);
    map_skill("spells", "baguazhou");
    map_skill("force", "lengquan-force");
    map_skill("unarmed", "changquan");
    map_skill("spear", "bawang-qiang");
    map_skill("parry", "bawang-qiang");
    map_skill("dodge", "yanxing-steps");

    set_temp("apply/armor", level*40);
    set_temp("apply/damage", level*10);
    
    set("no_steal",1);
    set("taskguai",1);
    setskill();
    /*
            set("chat_chance", 5);
            set("chat_msg", ({
            //     (: random_move :)
            }) );
    */
    set("inquiry", ([

      ]) );
    setup();
    carry_object("/d/obj/new-weapon/spear")->wield();
    carry_object("/d/obj/armor/tongjia")->wear();
    carry_object("/d/obj/new-weapon/"+w_type[random(sizeof(w_type))]);

      if(random(15)==2)
    carry_object("/d/quest/baoshi/baoshi");
}






void init ()
{   object ww,w;
    object me=this_object();
    object who=this_player();
    int t;
    if(!environment(me)->query("hellfireroom"))
    {call_out("destructing",1);}

    t=query("stay_time");
    if(userp(who))
        kill_ob(who);
    ::init();


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
      && !query_skill("shushan-force",1)

      && query("eff_kee") <  query("max_kee") )
    {

        set("eff_kee",query("max_kee"));
        set("eff_sen",query("max_sen"));

    }
    if (query("kee") < query("eff_kee")-10 )
    {
        command("exert recover");

    }
    if (query("sen") < query("eff_sen")-10)
        command("exert refresh");
    if( is_busy() && random(3)>1)
        start_busy(1);
    if (query("force") < query("max_force")/10)
        command("cast transfer");
    //   if (!owner() || owner()->query("rulaitask/fail") )
    //        destruct(guai);


/*
    if (is_fighting() )
    {
        if ( random(7)==1) call_out("check2",0);
    }
*/


    ::heart_beat();
}

void kill_ob (object ob)
{
    object me = this_object();

    ::kill_ob(ob);
}


void check2()
{
    object ob,me;
    me=this_object()->query_temp("last_damage_from");
    if(!me) return;
    if(! userp(me) && ! living(me) && is_fighting(me) && me=ob ) return ;
    if(! present(me,environment()) )
    {
        remove_call_out("check2");
        return;
    }
    if(me->query("combat_exp") <1000000 ) return ;

    if(me->query("kee")<10 && me->query("sen")<10 ) return ;


    switch(random(6))
    {
    case 0:
        {
            message_vision(YEL"$N念出一句妖咒，“魔界血箭”，一道血光向$n射来！\n",ob,me);


            if(random(6)==0)
            {

                message_vision(HIM"$N被血箭刺中心脏,受到严重伤害！\n"NOR,me);
                me->receive_wound("kee",query("max_sen")/55);
                me->receive_damage("sen",query("max_kee")/55);
                me->receive_wound("sen",query("max_sen")/55);
            }
            else
                message_vision(YEL"$N急忙往后一跳，及时躲过这道血箭！\n"NOR,me);
        }
        break;


    case 1:
        {

            message_vision(YEL"$N念起招魂咒，顿时万只魔界鬼魂张开大口向$n冲来！\n",ob,me);

            if(random(4)==0)

            {
                message_vision(HIR"$N的手手脚脚被魔界鬼魂吞噬了，受到极其恐怖的伤害！\n"NOR,me);
                me->receive_damage("kee",2*query("max_kee")/55);
                me->receive_wound("kee",2*query("max_sen")/55);
                me->receive_damage("sen",2*query("max_kee")/55);
                me->receive_wound("sen",2*query("max_sen")/55);
            }
            else
                message_vision(YEL"$N念起法力向前一挥，及时躲过这个劫难！\n"NOR,me);
        }
        break;

    case 2:
        {

            message_vision(HIR"$N手中突然发出一个血红色的火球，火球立即向$n飞过去。\n",ob,me);

            //
            if(random(40)>35)

            {
                message_vision(HIR"$N难以及时躲避，被扑面而来的火球打个正着！\n"NOR,me);
                me->receive_damage("kee",2*query("max_kee")/55);
                me->receive_wound("kee",2*query("max_sen")/55);
                me->receive_damage("sen",2*query("max_kee")/55);
                me->receive_wound("sen",2*query("max_sen")/55);

            }
            else
                message_vision(HIR"$N及时手指一拨，用法力把$n的火球拨开了！\n"NOR,me,ob);
        }
        break;

    }
    if( random(10) == 5 && ob->query("eff_kee")<ob->query("max_kee"))
    {
        set("eff_kee", query("max_kee"));
        set("eff_sen", query("max_sen"));
        set("kee", query("max_kee"));
        set("sen", query("max_sen"));
        set("force", query("max_force"));
        set("mana", query("max_mana"));
    }

    remove_call_out("check2");


}


varargs int receive_wound(string type, int damage, object who) 
{ 
        object ob=this_object();
      
     
      if(!who) return ::receive_damage(type, damage, who);  
        if(userp(who)) { 
      
           // can't use other's NPC to help kill. 
         if(damage>0) { 
            switch(type) { 
                case "kee":
                 ob->add("damage_rekee/"+who->query("id"),damage*2);
                 ob->add("total_rekee",damage*2);
                 break; 
                case "sen": 
                 ob->add("damage_rekee/"+who->query("id"),damage*2);
                 ob->add("total_rekee",damage*2);
                  break; 
                        } 
                      } 
                       } 
    
    return ::receive_wound(type, damage, who); 
} 
 
varargs int receive_damage(string type, int damage, object who) 
{ 
     object ob=this_object();
     
        if(userp(who)) { 
           // can't use other's NPC to help kill. 
        if(damage>0) { 
            switch(type) { 
                case "kee": 
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break; 
                case "sen": 
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break; 
                      } 
                      } 
                      } 
     
    return ::receive_damage(type, damage, who); 
} 


void reward()
{ 
        
        object killer,ob;
        int reward,exp;
    ob=this_object();
    killer = this_object()->query_temp("last_damage_from");
        reward=0;
    if (userp(killer))
    {  
   if(killer->query("hell_pot")>500000) return;
        if(ob->query("damage_rekee/"+killer->query("id"))>0)
        {
        reward=ob->query("damage_rekee/"+killer->query("id"));
        
        reward =(reward*100)/(ob->query("total_rekee"));
        
        if(reward>70)
        {
                exp=((ob->query("level"))*reward)/500;
                exp=random(exp)+1;
                
        killer->add("magic_pointed",random(2)+1);
        killer->add("hell_exp",exp);
        killer->add("hell_pot",exp/5);
        tell_object(killer,HIR"你等到若干点魔法点和"+exp+"点地狱火经验和"+exp/10+"点技能升级点。\n"NOR);
       
        }
        }

    }

}






