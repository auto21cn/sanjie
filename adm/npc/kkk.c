#include <ansi.h>
inherit NPC;
inherit F_SAVE;
mapping ips_res=([]);
int give_lllll();
void create()
{
         
           
         if( !restore() )
        {
                ips_res=([]);

        }
        else
        {
                if( !mapp(ips_res) ) ips_res = ([]);

        };
        set_name("依然妹妹", ({"yiran meimei","yiran mm"}));
      set ("long", @LONG
他是在这里负责给大家发开站礼物的，大家赶快向他要（ask）吧。
LONG);
        set("gender", "女性");
        set("title",HIY"欢迎光临三界神话嘉峪关站"NOR);
        set("age", 20);
        set("max_kee", 10000);
        set("kee", 10000);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([           
            "重开礼物"  :(:give_lllll:),  
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
             message_vision("$N对着$n说道：开站礼物等你先领新人礼物才来！。\n",this_object(),this_player());
           return 1;
            }     
       if (this_player()->query("lll/skills") != "got" )
           {
              message_vision("$N对着$n说道：开站礼物等你先领门派礼物才来！。\n",this_object(),this_player());
              return 1;
            }
        
         if (this_player()->query("lll/kgift") == "got" ){
               message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
               command("say 开站礼物只有一份！领过就不给了！\n");
               return 1;
                } 
          
                      ips=values(ips_res);
                      if (sizeof(ips)==0) ips=({"ddd","fff",});
                      ipp = query_ip_number(who); 
                      if ( member_array(ipp,ips) ==-1)
                      { 
                        
                        who->add("combat_exp",200000);
                        who->add("daoxing",200000);
                        who->add("force",800);
                        who->add("mana",800);
                        who->add("maximum_force",600);
                        who->add("max_mana",600);
                        who->add("max_force",600);
                        who->add("maximum_mana",600);
                        who->add("balance",500000);
                        who->set("lll/kgift","got");
                        skill=who->query_skills();
                        skillnames=keys(skill);
                        for(i=0;i<sizeof(skillnames);i++)
                        { who->set_skill(skillnames[i],101);}
                        ips_res[who->query("id")]=ipp;
                        save();
                        command("chat 恭喜恭喜，"+who->query("name")+"得到了开站礼物！");
                        command("say 恭喜恭喜，"+who->query("name")+"得到了开站礼物！");
                       return 1;
                      }
         
                message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 哪来的大米！领过就不给了！\n");
       
                return 1;


}


