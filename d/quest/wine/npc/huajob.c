#include "where.h"

string ask_job()
{ 
  object  ob, me,gift,*team,obj;
  int exp,position,i;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if ((int)ob->query("level")<40)
       return "你的等级不够。\n";
  if (interactive(ob) && (int)ob->query_condition("hua_mission"))  
       return "你上一次的任务还没完成!";
  if (interactive(ob) && (int)ob->query_condition("hua_busy"))  
       return "现在我可没有给你的任务，等会再来吧。\n";
  if ( !ob->query("wine/start") || !present("jiu pai",ob)) 
       return "我这里没有任务给你。\n";
        if(exp<=200000)     
         return "你的武功太差了,等练强了再来吧。\n";
        target = wheres[random(sizeof(wheres))];
    //for(i=100;i*i*i/10<=exp;i++); //i=maxpot
        if(random(10)>7)
        {obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
         i=400+random(250);
         obj->do_copy(ob,i);
         obj->set("title",HIR"将军府"NOR);
        }
        else
        { obj=new(__DIR__"killer");
          i=400+random(200);
          obj->do_copy(ob,i);
        }
        obj->move(target["weizhi"]);
        obj->set_temp("must_killby",ob->query("id")); 
    ob->set_temp("hua_job_target", target["chinese"]);//where
    ob->apply_condition("hua_mission",30);
        command("nod");
        str="本府逃兵在『"+target["chinese"]+"』一带行凶作恶。";
        command("say "+str);
    return "你去巡视一下。";
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say 你给我这个干吗?");
                return 0;
        }
        if ( !who->query_temp("hua_job_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }
                if (ob->query_temp("must_killby")!= who->query("id")
                        ||ob->query("victim_user")||who->query_temp("hua_given") )
                {       command("shake");
                command("say 你杀错人了。");
                return 0;
        } 

        who->set_temp("hua_given",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,count,i;
        if (!who) return;
        command("pat" + who->query("id"));
        command("say 做的好，加油干!");
              who->clear_condition("hua_mission");
                who->delete_temp("hua_job_target");
                who->apply_condition("hua_busy",3+random(6));
             return;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

int ask_jiu()
{
         int tt; 
         object me,jiu;
         me=this_player();
         tt=me->query("wine/huangjiu");
         if (!me->query_temp("hua_given"))
            {command("say 想要酒需要先帮我做些事情。\n");
             return 1;}
         if ( !me->query("wine/start") || !present("jiu pai",me)) 
            {command("say 我这没有这种酒。\n");
             return 1;}
         if( tt) 
         { if(tt<=time() && time()<tt+3600) 
        { message_vision("\n"+this_object()->query("name")+"说道：你刚要过酒，等等再来吧。\n",me); 
            return 1; } 
        }
         jiu=new("/d/quest/wine/obj/huangjiu");
         jiu->move(me);
         me->set("wine/huangjiu",time());
         me->delete_temp("hua_given");
         command("say 谢谢你帮我抓到了逃兵，这盅酒是赏给你的。");
         message_vision("$N给了$n一盅"+jiu->query("name")+"。\n", this_object(),me);
         return 1;
}

string ask_fangqi()
{
         object me;
         me = this_player();
         if(!me->query_temp("hua_job_target"))
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->delete_temp("hua_job_target");
             return "没关系,下次继续努力 。";
}
