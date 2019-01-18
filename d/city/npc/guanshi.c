// Update by waiwai@2001/04/17

#include <ansi.h>
#include <command.h>
inherit NPC;

string ask_gongzuo();
void create()
{
        set_name("管事", ({"guan shi", "guan"}));
        set("gender", "男性");
        set("age", 35);
        set("long", 
                "他是喜福会的管事，虽然很忙，但却很开心。\n");
        set("kee", 100);
        set("max_kee", 100);
        set("sen", 100);
        set("max_sen", 100);
        set("per", 22);
        
        set("combat_exp", 1500);
        set("score", 200);
	set("limit_fight", 1);
        set("no_kill", 1);
  
        set("inquiry", ([
                "盘子" : (: ask_gongzuo :),
                "panzi": (: ask_gongzuo :),
        ]) );

        setup();
        carry_object("obj/cloth")->wear();
}

string ask_gongzuo()
{
        object me,ob;
        me = this_player(); 

        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "你还是先去给店小二打个招呼吧。\n";

        if( me->query_temp("gongzuo/geipanzi")> 0)
                return "我不是给过你盘子了吗？难道你丢了它？\n";

        ob = new("/d/city/obj/zangpanzi");
//        ob = set("zangpanzi_owner",me->query("id"));
        ob->move(me);

        me->set_temp("gongzuo/geipanzi", 1);
        message_vision("管事给了$N一叠脏盘子。\n",me);
        return "好吧，你快去厨房洗干净这些盘子吧。";
}

void die()
{
  if (environment())

  set("eff_kee", 200);
  set("eff_gin", 200);
  set("eff_sen", 200);
  set("kee", 200);
  set("gin", 200);
  set("sen", 200);
  set("force", 200);
  set("mana", 200);
}

void unconcious()
{
  die ();
}
