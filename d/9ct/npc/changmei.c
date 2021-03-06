// 九重天神 巴蜀神圣 长眉 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIG"长眉"NOR, ({ "chang mei", "bai mei", "mei","changmei","tianshen" }));
        set("title",HIG"巴蜀神圣"NOR);
        set("long", 
          "蜀山剑派创始人，他最有特征的是其又白又长的眉毛。\n");

        set("gender", "男性");
        set("age", 100);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","swordsman");
    
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 5000000);
        set("daoxing", 5000000);

        set_skill("spells",350);
        set_skill("force", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("zixia-shengong", 350);
        set_skill("sevensteps", 350);
        set_skill("hunyuan-zhang", 350);
        set_skill("literate", 350);
        set_skill("unarmed", 350);
        set_skill("mindsword", 350);
         set_skill("yujianshu", 350);
set_skill("taoism",350);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "hunyuan-zhang");


        create_family("蜀山剑派", 4, "掌门人");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","fenguang" :),
                (: cast_spell, "jianshen" :),                
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
       setup();
        
        carry_object("/d/9ct/zb/jiezhi")->wear();
        carry_object("/d/9ct/zb/haotian");
}
void attempt_apprentice(object ob)
{        
        if (ob->query_skill("sword",1) < 200) {
        command("say 我蜀山剑派，最注重御剑术的修行，依我看" + RANK_D->query_respect(ob) + "是不是该多下下苦功呢？");
                return ;
        }
        if ((int)ob->query_int() < 38) {
        command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
                return;
        }
        /*
        if (ob->query("shushan/ask_zuidao_go")) {
        if (ob->query("nyj/shushan")!="done"){
                command("say " + RANK_D->query_respect(ob) + "，你既然要违背门规去镇妖塔，还想我跟我剑圣学蜀山剑派武功？");
                return;
        }
        command("say 上天不可逆转。");
        
     }*/
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("class", "swordsman");
        ob->set("title",HIG"巴蜀奇侠"NOR);
}

