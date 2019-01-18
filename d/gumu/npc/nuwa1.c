//轩辕古墓终极师承 女娲
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name("女娲", ({"nu wa", "nuwa", "nu","wa","master","tianshen"}));
       set("long", "天地之母，以身躯化作五彩石补天，
其举动感动上苍，封为天地智圣大慈天尊，后收妲己等九
天玄女，专伺辅佐天神。
\n");
       set("title", HIM"天地之母"NOR);
       set("color", HIW);
       set("gender", "女性");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "上尊");
       set("cor", 30);
       set("per", 40);
      set("looking", "轻若飘渺,虚无实幻。");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 8000);
       set("max_force", 5000);
       set("force_factor", 305);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 400);
       set("combat_exp", 10000000);
       set("daoxing", 8000000);
       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
      set_skill("youming-spells", 350);
       set_skill("jiuyin-zhua", 350);
     set_skill("jiuyin-force", 350);
      set_skill("shengling-sword", 350);
      set_skill("kongming-steps", 350);

   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("sword", "shengling-sword");
   map_skill("parry", "shengling-sword");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                 (: perform_action, "sword", "sword21" :),
        }) );
create_family("轩辕古墓", 1, "红");
setup();


        carry_object("/d/wizz/junhyun/obj/weapon/shengling-sword")->wield();
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
        ob->set("title", HIW"女娲座下 "HIB"九天圣使"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}

