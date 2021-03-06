
//lbxianzi.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIC"凌波仙子"NOR,({"lingbo xianzi","lingbo", "xianzi","master"}));
       set("long", "她就是就是凌海神宫的创始人。
本为天界仙子，后下到凡间教授弟子。凌海神宫的
势力也在渐渐扩大。\n");
       set("title", HIB"盈盈微波月下魂"NOR);
       set("gender", "女性");
       set("age", 30);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/self", "圣神");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
           set("daoxing", 4000000);
       set_skill("literate", 300);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 400);
       set_skill("parry", 350);
       set_skill("sword", 400);
       set_skill("spells", 350);
       set_skill("blade", 350);
   set_skill("linghai-force", 400);
   set_skill("lingbo-steps", 350);
   set_skill("huanyue-jianfa", 400);
   set_skill("kongwujian", 350);
   set_skill("fenxin-blade", 350);
   set_skill("fenxin-spells", 350);
   map_skill("spells", "fenxin-spells");
   map_skill("force", "linghai-force");
   map_skill("sword", "huanyue-jianfa");
   map_skill("parry", "huanyue-jianfa");
   map_skill("dodge", "lingbo-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "fengyue" :),
                 (: perform_action, "lianyue" :),
                 (: exert_function, "xuehai" :)
        }) );

create_family("凌海神宫", 1, "红");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/linghai/obj/lingbojian")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="凌海神宫") {
   if( (((int)ob->query("combat_exp") < 1000000 ))|| 
        ((int)ob->query_skill("huanyue-jianfa",1) < 200) || 
        ((int)ob->query_skill("linghai-force",1) < 200) || 
        ((int)ob->query("per") < 20) ){
   command("shake" +ob->query("id"));
   command("say " + RANK_D->query_respect(ob) +
"的修为还不够，即使现在收了，也很难成材。\n");
   return;
   }
        command("nod "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"珍惜时光，把凌海神宫扬名天下！\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIC"凌海圣仙"NOR);
           ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   command("say 哼!本圣神怎可和你挥拳动动手？\n");
   return 0;
}






