#include <ansi.h>
inherit NPC;
inherit F_SAVE;
int give_lllll();
void create()
{
      set_name("三界新年大神", ({"wushi dashen","wushi"}));
      set ("long", @LONG
他是在这里负责给大家发新年礼物的，大家赶快向他要（ask）吧。
LONG);
        set("gender", "男性");
        set("title",HIY"欢迎光临三界神话成都站"NOR);
        set("age", 20);
        set("max_kee", 10000);
        set("kee", 10000);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([           
            "新年礼物"  :(:give_lllll:),  
                         ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
        
}
string query_save_file()
{
        return DATA_DIR+"gift_temp";

}
int give_lllll()
{       
        object who;
        mapping skill;
        string *skillnames,*ips,ipp;
        int i;
        who=this_player();
//
        if (!userp(who)){
                command("heng");
                command("say 什么小猫小狗也来要礼物？！");
                command("qi");
                return 1;
        }
        if(who->is_busy())
           {               
            tell_object(who,"你正忙着呢！\n");
                return 1;
            }
       if (this_player()->query("lll/gai") != "got" )
           {
             message_vision("$N对着$n说道：大米也来要？\n",this_object(),this_player());
           return 1;
            }     
       if (this_player()->query("lll/skills") != "got" )
           {
              message_vision("$N对着$n说道：大米也来要？\n",this_object(),this_player());
              return 1;
            }
        if (this_player()->query("age")<15 )
           {
              message_vision("$N对着$n说道：大米也来要？\n",this_object(),this_player());
              return 1;
            }
         if (this_player()->query("combat_exp")<150000 )
           {
              message_vision("$N对着$n说道：大米也来要？\n",this_object(),this_player());
              return 1;
            }
         if (this_player()->query("lll/xngift") == "got" ){
               message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
               command("say 新年礼物只有一份！领过就不给了！\n");
               return 1;
                } 

                        who->add("combat_exp",200000);
                        who->add("daoxing",400000);
                        who->add("force",200);
                        who->add("mana",200);
                        who->add("maximum_force",100);
                        who->add("max_mana",100);
                        who->add("max_force",100);
                        who->add("maximum_mana",100);
//                        who->add("balance",500000);
                        who->add("potential",88888);
                        who->set("lll/xngift","got");
                        save();
                        command("chat 恭喜恭喜，"+who->query("name")+"得到了新年礼物！");
                        command("say 恭喜恭喜，"+who->query("name")+"得到了新年礼物！");
                       return 1;

}


