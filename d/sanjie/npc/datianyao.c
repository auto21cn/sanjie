// datianyao.c 大天妖

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"大天妖"NOR, ({"master tianyao", "master"}));
       set("long", "与大天魔一样是邪类，妖中之王。\n");
       set("title", HIC"天妖宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 3000);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老妖精");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 240);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("spells", 160);  
        set_skill("tianmogong", 160);
        set_skill("literate", 160);
        set_skill("stick", 200);  
        set_skill("tianyaofa", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 160);   
        set_skill("huntianforce", 160);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("stick", "tianyaofa");
        map_skill("parry", "tianyaofa");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

        create_family("三界山", 1, "蓝");

	set("inquiry", ([
	"name"     : "我就是大天妖，妖中之王。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/tianyaojia")->wear();
	carry_object("/d/sanjie/obj/yaobang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="三界山") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "你曾背我派，我不原再收你为徒了！\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("tianyaofa", 1) < 120 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我天妖屠神法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
