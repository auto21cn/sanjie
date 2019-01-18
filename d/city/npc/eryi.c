//added job by wuyou

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();

void create()
{
        set_name("二姨太", ({"er yitai", "yitai"}));
        set("age", 22);
        set("gender", "女性");
        set("long",
"姚家的二姨太太，见你看她，对你抛了个媚眼．\n");
        set("attitude", "friendly");
        set("per", 22);
        set("combat_exp", 1000);
        set("shen_type", 1);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
        ]) );
        setup();

        carry_object("/d/obj/cloth/nichang")->wear();
        carry_object("/d/obj/cloth/yuanxiang")->wear();

}

void init()
{
      ::init();
   add_action("do_fight", "fight");
   add_action("do_kill", "kill");
}

int do_fight(string arg)
{
   object who = this_player();
   object me = this_object();
    if (arg && present(arg,environment(who))==me)
    {
      message_vision("$N看样子想打架，但二姨太很有涵养,不和$N动粗。\n",who,me);
     return 1;
   }
   return 0;
}

int do_kill(string arg)
{
     object who = this_player();
    object me = this_object();

    if (arg && present(arg,environment(who))==me)
  {
    message_vision("$N看样子想杀死二姨太，二姨太笑了笑,没跟$N一般见识。\n",who,me);
    return 1;
   }
return 0;
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        if (me->query("combat_exp")>=150000)
        {
               command("say 你的武功比我恩公宇文无忧还要高了，这种小事不敢劳您大架。\n");
               return 1;
         }
        if( me->query_temp("newbiejob/yunbu")>0)
        {
                tell_object(me,"快去把布匹熨好后交给我吧。\n");
                return 1;
        }  
        message_vision(CYN"二姨太对$N说道：现在熨好的布匹不够用了，你就到后面的库房里去熨些布来。\n"NOR,me); 
        me->set_temp("newbiejob/yunbu", 1);
        return 1;   
}

int accept_object(object me, object ob)
{
        object ob1;
        if (strsrch(ob->query("name"), "熨好的布") < 0) 
        {
            command("say 你别来蒙我啦，这是熨好的布吗？\n");
        }
        else if (me->query_temp("newbiejob/yunbu")<1)
        {
            command("say 我没有叫你帮我熨布呀！\n");
        }
        else
        {
            message_vision(CYN"二姨太对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
            message_vision(CYN"二姨太递给$N一些银子。\n"NOR,me);  
                me->delete_temp("newbiejob/yunbu");
                me->add("combat_exp",20+random(20));
                me->add("potential",10+random(10));
                me->start_busy(3+random(2));
                ob1=new("/obj/money/silver");
                ob1->set_amount(10 + random(5));  
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}



