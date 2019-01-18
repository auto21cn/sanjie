//奖励npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int answer_me();

void create()
{
         set_name(HIW"冰雪儿"NOR, ({"bing xue er"}));
        set("long", HIM"冰雪儿是阿修派出专门发放装备的仙女，美丽异常！\n"NOR);
           set("gender", "女性");
        set("title",HIR"婀娜可爱 漂亮百分"NOR);
        set("age", 18);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 

            "tuimo jing" : "/d/wizz/cigar/zb/jing",
            "beidou armor" : "/d/wizz/cigar/zb/tianjia",
            "zibing kui" : "/d/wizz/cigar/zb/kui",
            "biluo pao" : "/d/wizz/cigar/zb/pao",
            "feitian shoes" : "/d/wizz/cigar/zb/xue",
            "tian dun" : "/d/wizz/cigar/zb/shield",
            "tiancai pifeng" : "/d/wizz/cigar/zb/pifeng",
            "yinyang ring" : "/d/wizz/cigar/zb/jiezhi",
            "qilin wan" : "/d/wizz/cigar/zb/wan",
            "tianguang lian" : "/d/wizz/cigar/zb/necklace",
        ]) );

        setup();
        carry_object("/d/moon/obj/luoyi.c")->wear();
}
int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}



void init()                            
{                                      
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
