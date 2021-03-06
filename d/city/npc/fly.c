/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Created by waiwai@2000/07/10
// Update by waiwai@2001/04/17

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(CYN"苍蝇"NOR, ({ "fly" }));
	set("race", "野兽");
        set("gender", "无性");
	set("age", 1);
	set("long", "一只红头苍蝇，专爱在粪堆里打转。\n");
	
	set("str", 30);
	set("dex", 30);

	set("limbs", ({ "头部", "翅膀", "前脚", "後脚"}) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
              "苍蝇不停在你身边打转，发出嗡嗡声。\n",
		"苍蝇停在一堆粪便上，贪婪地吮吸着。\n",
	 	"苍蝇突然一个俯冲，钻进了你的鼻孔，又飞了出来。\n",
		"苍蝇不声不响的停在了你鼻上，怪痒痒的。\n",
		"苍蝇看你一个不留神，飞到你手中的面包上舔了舔。\n",
		"苍蝇不小心掉进了你的可乐里，被你喝了下肚，呃，你呕得一地都是。\n"}));
	set_temp("apply/attack", 10);
       set_temp("apply/parry", 10);
       set_leader(1);

	setup();
}

void init()
{	
	object me;

	set_heart_beat(1);
	::init();
	if( interactive(me = this_player()) ) {
		remove_call_out("killing");
		call_out("follow", 1, me);
	}
}

void follow(object who)
{
  object me;
  me = this_object();
if( !wizardp(who)) {//禁止fly的follow wiz 
  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)  {
    command("follow " + who->query("id"));
    me->set_leader(who);

  }
}
}


void die()
{
	object ob;
	message_vision("$N"HIB"嗡嗡地一声飞走了......\n"NOR, this_object());
	destruct(this_object());
}
