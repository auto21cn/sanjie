//奖励npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
//int give_xujl();
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name("玉宝宝", ({"baobao"}));
   set ("long", @LONG
他是在这里负责给大家发武学奖励的可爱的玉宝宝。（ask baobao about 奖励）
（ask baobao about 150万）是1.5M奖励的
LONG);
           set("color", HIC);
           set("gender", "男性");
        set("title",HIY"活泼可爱的"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 
//                "ling":    "/d/obj/stey/ling.c",
                "whip":    "/d/obj/stey/yaowhip1.c",
                "hammer":    "/d/obj/stey/tianhammer.c",
               "sword":    "/d/obj/stey/sttt.c",
                "fork":    "/d/obj/stey/shenfork.c",
                "spear":    "/d/obj/stey/shenspear.c",
                "stick":    "/d/obj/stey/tianbang.c",
               "mace":    "/d/obj/stey/goldjian.c",
                "qin":    "/d/obj/stey/moqin.c",
                "blade":    "/d/obj/stey/guiblade.c",
                "staff":    "/d/obj/stey/shenstaff.c", 
                "spellsbook":    "/d/obj/book/mihou-book.c",   
                "parrybook":    "/d/obj/book/parrybook2",
//                "renshenguo":    "/d/obj/drug/renshen-guo1",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "奖励"    :(:give_wx:),
            "武学奖励"    :(:give_wx:),
//            "官位嘉奖"    :(:give_xujl:),
            "jiangli"    :(:give_wx:),
            "150万"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say 你再努力努力，很快可以拿奖励的。");
                command("addoil "+who->query("id") );
                return 1;
         }
                  if (who->query("combat_exp") > 1500000 ){
                command("hammer "+who->query("id") );
              return 1;
              }
         if (this_player()->query("lucky/njjj") == "got" ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("potential",10000);
        who->add("daoxing",50000);
        who->add("combat_exp",50000);
        who->set("lucky/njjj","got");
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               你的潜能增加了一万点!\n 
               你的武学增加了五万点!\n 
               你的道行增加了五十年!\n ");
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)武学到了50万，给予奖励！\n", 
who->query("name"),who->query("id"))); 
      message_system("恭喜！恭喜！"+HIY""+who->query("name")+""+HIW"得到了武学超过五十万的奖励！"); 
        return 1;
}

int give_xujl()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("office_number") < 2820 ){
                command("slapslap "+who->query("id") );
                command("say 骗子!!!");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("xujl") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("potential",500000);
    who->add("balance",15000000);
        who->add("daoxing",500000);
        who->set("xujl",1);
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)拿了辅佐王奖励！\n", who->query("name"),who->query("id"))); 
message_vision("$N对着$n亲切的笑了笑，$n觉得钱庄里面的存款似乎多了很多，再看看hp哦...\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        你现在存款增加了一千五百两黄金，道行增加五百年，潜能增加五十万点。\n");
          command("rumor 恭喜恭喜，"+who->query("name")+"的官位终于位居★辅佐王★，给予嘉奖！");
          command("chat 恭喜恭喜，"+who->query("name")+"的官位终于位居☆★→辅佐王←★☆，给予嘉奖！");
        return 1;
}

int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say 你再努力努力，很快可以拿奖励的。");
                command("addoil "+who->query("id") );
                return 1;
         }
        if (who->query("level") < 40 ){  
            command("say 你的等级不够，去升级了再来吧。"); 
            return 1; 
        }
         if (who->query("combat_exp") > 1900000 ){
                command("hammer "+who->query("id") );
                command("say 你都这么厉害，还需要吗？贪心！。");
                command("kick "+who->query("id") );
                return 1;
         }
         if (who->query("lucky/jjjjk")=="got") {
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！！！！！！\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("daoxing",300000);
        who->add("combat_exp",1500000);  
        who->add("balance",15000000); 
        who->set("lucky/jjjjk","got");
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               你的潜能增加了五万点!\n 
            你的道行增加了三百年!\n
            你的武学增加了一百五十万点!\n
            你的存款增加了一千五百金!\n "); 
//          command("chat 恭喜恭喜，"+who->query("name")+"武学到了150万，给予奖励！");
      message_system("贺喜！贺喜！"+HIY""+who->query("name")+""+HIW"得到了武学超过"+HIG"一百五十万"+HIW"的奖励！"); 
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)拿了一百五十万奖励！\n", who->query("name"),who->query("id"))); 
        return 1;
}
/*
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
} 
*/
void init()                            
{                                      
// 	call_out("greeting", 1, this_player());
//   	::init();
        add_action("do_vendor_list", "list");   	
        add_action("do_fight", "fight");     
        add_action("do_kill", "kill");       
        add_action("do_cast", "cast");       
        add_action("do_bian","bian");        
        add_action("do_cast", "perform");                           
        add_action("do_steal", "steal");       

}                                            
                                             
int do_kill(string arg)                                                       
{                                                                             
        object who = this_player();                                           
        object me = this_object();                                            
                                                                              
        if(!arg || present(arg,environment(me))!=me) return 0;                
                                                                              
        message_vision("$N对$n威胁道：你敢杀我，不想混了！\n", me, who);    
        return 1;                                                             
}

int do_bian(string arg)                                                                                                                              
{                                                                        
        object who = this_player();                                      
        object me = this_object();                                       
                                                                         
        if(!arg || present(arg,environment(me))!=me) return 0;           
                                                                         
        message_vision("$N嘿嘿奸笑了几声，刁穷小技，呸！\n", me);
        return 1;                                                        
}
                       
int do_cast(string arg)                                                                                                                                                         
{                                                                                                      
        object who = this_player();                                                                    
        object me = this_object(); 
//         if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
        message_vision("$N对$n威胁道：你敢杀巫师，不想混了！\n", me, who);                             
        return 1;                                                                                      
}
int do_steal(string arg)
{
  object who = this_player();
  object me=this_object();

  //if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision ("$N突然对$n笑道：都是同道中人，何必呢？\n",me,who);
  message_vision ("$N发现事情暴露，吓得将手缩了回去。\n",who);
  return 1;
}
                                                                             
                                                                                                                                                                                       
int do_fight(string arg)                                                                                                            
{                                                                                                                                   
        object who = this_player();                                                                                                 
        object me = this_object();                                                                                                  
                                                                                                                                    
        if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
                                                                                                                                    
        message_vision("$N对$n摇了摇头：你不是我对手，滚！\n", me, who);                                                      
        return 1;                                                                                                                   
}                 
void die()
{
  if (environment())
    message("sound", "\n\n玉宝宝哈哈大笑一声，我还会再回来的！\n\n", environment());

  set("eff_kee", 1000);
  set("eff_gin", 1000);
  set("eff_sen", 1000);
  set("kee", 1000);
  set("gin", 1000);
  set("sen", 1000);
  set("force", 1000);
  set("mana", 1000);
}

void unconcious()
{
  die ();
}
