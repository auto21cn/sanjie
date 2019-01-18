/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Npc: /d/city/shangshu/npc/guard.c
//Creat by waiwai@2001/05/12
//Pay Npc 之一

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("门房", ({ "guard" }) );
        set("id", "guard");
        set("long","尚书府的门房虽然没什么官衔，但所有想晋见\n"
                "尚书的白衣无不对他毕恭毕敬的n");

        set("attitude", "peaceful");
	 set("area_name","长安城");
	 set("money_need",2000);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 1000);

        set("chat_chance", 5);
                set("chat_msg", ({
                "门房慢吞吞地说：是。。想[拜访]尚书大人的吗？。。\n",
                "门房嘿嘿地笑了笑，手里比划着一个数字"+MONEY_D->money_num(this_object()->query("money_need"))+".\n"
                }) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge", 90);

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
       object ob,area;
       area=new("/obj/area");
	area->create(query("area_name"));
       set("banghui",(string)area->query("banghui"));
       destruct(area);
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_ask","ask");
}

int do_ask(string str)
{
	string banghui;
	object me;
	string sb,sth;

	if(! str)	return 0;

	me=this_player();

	if(! living(me))	return 0;

	if(sscanf(str,"%s about %s",sb,sth)!=2)	return 0;

	if(sb!=this_object()->query("id"))	return 0;

	if(sth!="拜访") return 0;

	banghui=(string)me->query("banghui");

       if(! banghui || query("banghui")!=banghui)   {
		if((int)me->query_temp("have_asked")>=3)	{
		message_vision(HIG"\n$N"HIG"一瞪眼道："+me->query("name")+HIG
		"！问个没完没了，分明是不想掏钱，让我送你去鬼门关再问吧！\n\n"NOR,
		this_object());
		me->delete_temp("have_asked");
		kill_ob(me);
		me->fight_ob(this_object());
		return 1;
		}
		command("hehe");
		message_vision("$N说道：便宜你了"+me->query("name")+
		"就付(pay)俺"+MONEY_D->money_num(this_object()->query("money_need"))+"吧。\n",this_object());
		me->add_temp("have_asked",1);
		return 1;
	}
	message_vision("$N拍了拍$n的肩膀道：都是帮中兄弟，我哪会要你的钱呢。\n",this_object(),me);
	return 1;
}

void greeting(object ob)
{
	string banghui;

	if( !ob || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

	banghui=(string) ob->query("banghui");

       if(! banghui || query("banghui")!=banghui)   {
		say("鼻子里哼了一声，头掉了过去。\n"NOR);
		return;
		}
	command("say 这位"+RANK_D->query_respect(ob)+"，帮主身体可好？\n");
	return;
}
/*
void die()
{
  if (environment())

  set("eff_kee", 200);
  set("eff_gin", 200);
  set("eff_sen", 200);
  set("kee", 200);
  set("gin", 200);
  set("sen", 200);
  set("force", 200);
  set("mana", 200);
}
*/
void unconcious() { die (); }

