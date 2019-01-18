//喜媚
//轩辕古墓

//ximei.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_leave();


void create()
{
              set_name(HIW"喜媚" NOR, ({"xi mei", "ximei", "mei"}));
       set("long", "
一只羽翼初满的雉鸡，尚有百年修为，妲己非常
喜爱她，将玄阴修行之术传于她后，尤好采阳补
阴，在朝歌鹿台之上纣王大宴妲己所邀众妖仙之
时不胜酒力，显露原形毙于太师闻仲的金鞭之下
后于封神台被妲己和王贵人所救\n");
       set("title", HIB"雉鸡精" NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 40);
        set("int", 40);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);
  set("daoxing", 800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 220);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("blade", 220);
       set_skill("spells", 80);
        set_skill("youming-spells", 220);
        set_skill("jiuyin-zhua", 220);
        set_skill("jiuyin-force", 220);
        set_skill("zizhi-blade", 220);
        set_skill("kongming-steps", 200);
        map_skill("spells", "youming-spells");
        map_skill("unarmed", "jiuyin-zhua");
        map_skill("force", "jiuyin-force");
        map_skill("blade", "zizhi-blade");
        map_skill("parry", "zizhi-blade");
        map_skill("dodge", "kongming-steps");


        set("inquiry", ([
                "脱离" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
                ]) );

create_family("轩辕古墓", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        

        command("kiss "+ob->query("id"));
        command("say 嘻嘻，你要多加努力哦，要不然小心妲己姐姐吃了你哟。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "轩辕古墓" ) {
                command("say 你这个逆徒，居然要背叛师门！");
                me->set_temp("m_betray", 2);
                return ("背叛师门要废除你的武功，你可愿意(agree)？");
        }

        return ("贱妾不知。\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("m_betray") > 1 ) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                command("say 既是你与轩辕古墓无缘，你便下山去吧！");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
       this_player()->set("combat_exp", this_player()->query("combat_exp")/100*80);
   this_player()->set("daoxing", this_player()->query("daoxing")/100*80);
                if( this_player()->query_skill("youming-spells") )
                    this_player()->delete_skill("youming-spells");
                if( this_player()->query_skill("shengling-sword") )
                    this_player()->delete_skill("shengling-sword");
                if( this_player()->query_skill("jiuyin-force") )
                    this_player()->delete_skill("jiuyin-force");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->delete_temp("betray");
                this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
        }
}



