// 九重天神 "八重天神 阿布及" by Calvin
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name(HIM"阿布及"NOR, ({"a buji", "a", "buji","abuji","master","tianshen"}));
       set("long", "西王母曾经的师傅,后来转封为九重天神。\n");
       set("title", HIM"月影圣者"NOR);
       set("gender", "男性");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "圣者");
       set("cor", 30);
       set("per", 40);
      set("looking", "轻若飘渺,虚无实幻,风流倜傥,一表人才。");
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
       set_skill("sword", 350);
       set_skill("blade", 350);
       set_skill("xuanhu-blade", 350);
       set_skill("spells", 350);
      set_skill("moonshentong", 350);
       set_skill("baihua-zhang", 350);
     set_skill("moonforce", 350);
      set_skill("snowsword", 350);
      set_skill("moondance", 350);
  set_skill("whip", 350);
  set_skill("jueqingbian", 350);
   map_skill("spells", "moonshentong");
   map_skill("unarmed", "baihua-zhang");
   map_skill("force", "moonforce");
   map_skill("sword", "snowsword");
   map_skill("parry", "snowsword");
   map_skill("dodge", "moondance");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "mihun" :),
                (: cast_spell, "arrow" :)
        }) );
create_family("月宫", 1, "红");
setup();

        carry_object("/d/9ct/zb/wan")->wear();
//        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="月宫") {
   if (((int)ob->query("combat_exp") < 2000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
     command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIG"月宫月影仙子"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}

