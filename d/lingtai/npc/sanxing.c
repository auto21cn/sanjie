//三星圣母
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"三星圣母"NOR, ({"sanxing shengmu","sanxing", "master"}));
       set("long", "乾坤倒转。万妙无方\n");
       set("title", HIC"万妙无方"NOR);
       set("gender", "女性");
       set("age", 20);
        set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "圣母");
       set("per", 40);
        set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);

       set_skill("literate", 200);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("parry", 220);
        set_skill("stick", 220);
        set_skill("sword", 220);
        set_skill("liangyi-sword", 180);
        set_skill("spells", 220);
        set_skill("dao", 220);
        set_skill("puti-zhi", 180);
        set_skill("wuxiangforce", 220);
        set_skill("force", 220);
        set_skill("qianjun-bang", 180);
        set_skill("jindouyun", 180);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

create_family("方寸山三星洞", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/longxingjian")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="方寸山三星洞") {
        if ((int)ob->query("daoxing") < 500000 ) {
        command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，我不原再收你为徒了！\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 35) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("dao", 1) < 120 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我道家仙法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say 我不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n三星圣母微皱眉头，道：这厮果是个天成地就的！\n\n", environment());
        command("sigh");
        message("sound", "\n三星圣母身形一转，化做青烟走了。。。\n\n", environment());
        }

        destruct(this_object());
}
