//轩辕古墓终极师承 轩辕公
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
        set_name("轩辕公", ({"xuanyuan gong", "xuanyuan", "gong","master","tianshen"}));
       set("long", "开天辟地之神，与女娲平起平坐，但因为
屡犯天规而得不到众仙的认同。
\n");
       set("title", HIW"开天辟地"NOR);
       set("color", HIR);
       set("gender", "男性");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "上尊");
       set("cor", 30);
       set("per", 40);
      set("looking", "仙风道骨，举止出尘。");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 5000000);
       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("blade", 350);
       set_skill("spells", 350);
      set_skill("youming-spells", 350);
       set_skill("jiuyin-zhua", 350);
     set_skill("jiuyin-force", 350);
      set_skill("mohuang-blade", 350);
      set_skill("kongming-steps", 350);

   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("blade", "mohuang-blade");
   map_skill("parry", "shengling-sword");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                 (: perform_action, "blade", "posui" :),
        }) );
create_family("轩辕古墓", 1, "红");
setup();


        carry_object("/d/wizz/junhyun/obj/weapon/xuanyuan-blade")->wield();
}

void attempt_apprentice(object ob)



{
   if ( (string)ob->query("family/family_name")=="轩辕古墓") {
   if (((int)ob->query("combat_exp") < 2000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
     command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，日后为三界所共仰。\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIW"轩辕拓世 "HIB"梵天承魔"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}

