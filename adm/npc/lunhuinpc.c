//cigar 轮回转世NPC

#include <ansi.h>
inherit NPC;
string ask_for_leave();

void create()
{
        set_name(HIW"转世轮回菩萨"NOR, ({"lunhui pusa","pusa"}));
        set("gender", "女性" );
        set("age", 25);
        set("title",HIY"眼望世间虚缈，空、无、灭"NOR);
        set("long", HIG"\n\n佛祖如来身边掌管转世轮回的大智、无我菩萨\n\n"NOR);
        set("combat_exp", 1000000000);
          set("daoxing", 5000);

        set("attitude", "peaceful");
        set("per", 40);
        set("max_kee", 20000);
        set("max_gin", 20000);
        set("max_sen", 20000);
        set("inquiry", ([
                "轮回转世" : (: ask_for_leave :),
                "投胎" : (: ask_for_leave :),
                ]) );
        setup();
        carry_object("/d/ourhome/obj/pink_cloth")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

      if ((int)me->query("combat_exp") > 120000000 )
{
                command("say 你可思虑过？轮回转世不可儿戏，你苦练已久的武功和情感方面都要放弃。");
                me->set_temp("c_lunhui", 2);
                return ("沧海桑田，无望无我，你可愿意抛弃你的一切的一切，破红尘，忘自我，离师判门，你愿意否(agree)？");
        }

        return ("你现在转世轮回有如沧海小舟，无济于事。\n");
}

int do_agree(string arg)
{
        int i,j,level;
        mapping skill;
        object who;
        string *skillnames,*xing,*ddel,*fa,family;
        who=this_player();
        seteuid(getuid());
        xing=({"str", "cor", "int","spi",
               "cps", "per", "con","kar",});
        ddel=({ "family",       "dntg",
                "obstacle",     "shengri",
                "quiz_num",     "secmieyao_mudage",
                "secmieyao",    "secmieyao_killedtime",
                "MKS",          "bellicosity",
                });

        family=who->query("family/family_name");
        
        if(!who->query_temp("c_lunhui"))
                 {
                 command("say 你从哪里来？。");
                 return 1;
                 }
        if(who->query_temp("c_lunhui") > 1 )
        {
                message_vision("$N说道：“红尘淡淡，我欲轮回转世，超度一生的罪孽”。\n\n", who);
                command("say 既然如此，我现在就上奏佛祖如来，破你红尘之身，圆你超度之意！");


         who->set("combat_exp",2000000);
         who->set("daoxing",2000000);
         who->set("maximum_mana",1000);
         who->set("maximum_force",1000);
         who->set("mud_age",100000);


          //给此玩家设定转世之后的属性+3
         for(i=0;i<sizeof(xing);i++) { who->set(xing[i],who->query(xing[i])+3); }

          //给此玩家消除的参数
         for(i=0;i<sizeof(ddel);i++) { who->delete(ddel[i]); }

          // 给此玩家skills
         skill=who->query_skills();
         skillnames=keys(skill);
         for(i=0;i<sizeof(skillnames);i++)
               { who->set_skill(skillnames[i],123);}
         //记录转生门派
         if(who->query("opinion/family_allow")) 
               {
                        fa=who->query("opinion/family_allow");
                        if (member_array(family,fa)== -1)
                        {
                                fa +=({family});
                        }
                }
               else fa=({family,});
         who->set("opinion/family_allow",fa);
         
         
                who->set("title", HIW"转世轮回"+ HIY"空有一切似云烟"NOR);
                who->add("lunhui_zhuanshi", 1);
                who->add("lunhui/lunhui",1);
                who->add("opinion/mete",1);
                who->add("balance",10000000);
                who->delete("learned_points");
                who->delete("potential");
                who->add("potential",100000);
                who->set("class","lunhui");
                who->delete_temp("betray");
                who->set("startroom","/d/city/kezhan");

                command("say 你现在极限无量！\n");
                command("chat 所有一切众生类摄。若卵生若胎生若湿生若化生。若有色若无色。若有想若无想。若非有想若非无想。乃至众生界及假名说。\n");
                command("chat 不应生住法心。不应生住非法心。不应生有所住心。何以故。若心有住则为非住故。\n");
                command("chat 轮回转世空空荡去，世间万物终有一度，"+who->query("name")+"破红尘之身，化世俗凡念，心归我佛，轮回转世了。\n");

                who->move("/d/city/kezhan");
                who->save();

                return 1;
        }
}


