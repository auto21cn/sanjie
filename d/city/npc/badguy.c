/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Created by waiwai@2000/11/13

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("地主老豺", ({ "dizhu laochai", "dizhu", "laochai" }) );
        set("long",CYN
"一个满脸伤疤加横肉的家伙,专门干榨取长工血汗的勾当，暗地里还杀人越货无所不做。\n"NOR);
        set("attitude", "aggressive");
        set("per", 1);
        set("str", 40);
        set("combat_exp", 100000+random(4000000));
        set("bellicosity", 10000);
        set("chat_chance", 30);
        set("chat_msg", ({HIB
                "地主老豺喝道：今天老子要钱又要命！！\n"NOR,
                HIB"地主老豺笑道：小样，去死吧！\n"NOR,
		(: random_move :),
        }) );

	set("kee", 3000);
	set("sen", 3000);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("force", 1500);
	set("max_force", 1500);
	set("food", 1500);
	set("water", 1500);

        set_skill("unarmed", 100+random(200));
        set_skill("blade", 100+random(200));
        set_skill("parry", 100+random(200));
        set_skill("dodge", 100+random(200));
        set_skill("move", 100+random(200));
        set_skill("stealing", 600);

        set_temp("apply/attack", 170);
        set_temp("apply/defense", 170);
        set_temp("apply/armor", 170);
        set_temp("apply/damage", 130+random(400));
        set_temp("apply/dodge", 100);
	set("zombie",1);
	set("no_blade", 1);//不怕冰刀
	set("no_poison", 1);//不怕用毒

        setup();

        carry_object("/obj/cloth/yexing")->wear();
        carry_object("/obj/weapon/guiblade")->wield();
}

// 不接受比划
int accept_fight (object ob) { return 0; } 

void kill_ob (object ob) 
{ 
	set_temp("my_killer",ob); 
	::kill_ob(ob); 
} 

void die()
{
	int k;
	object ob;
	ob = query_temp("last_damage_from");

     ob->add("daoxing",800);
     ob->add("combat_exp",800);
     ob->add("potential",500);
     ob->add_temp("killbad",1);
     message("system",YEL"『謠言惑众』顺风耳：据说 "WHT+log_id(ob)+NOR YEL" 杀死地主老豺为民除害，得到了官府奖励！！！\n"NOR,users());    
     tell_object (ob,WHT"\n你赢得了 800 点武学，200 天道行，500 点潜能！\n"NOR);

	k = ob->query_temp("killbad");
	if( k >= 5) {
		ob->add("potential",k*800);
		ob->delete_temp("killbad");
	message("system",YEL"『謠言惑众』顺风耳：由于 "WHT+log_id(ob)+NOR YEL" 连续杀死地主老豺为民除害，得到额外奖励"HIR+k*800+NOR YEL"点潜能！\n"NOR,users());    
	tell_object (ob,HIG"\n由于你连续杀死地主老豺为民除害得到了额外奖励"+(k*800)+"点潜能！\n"NOR);
	}

      ::die();
}

void unconcious() { die(); }
