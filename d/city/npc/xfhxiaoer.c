// Created by waiwai@2000/10/12

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("店小二", ({"xiao er", "xiao", "er"}));
        set("gender", "男性");
        set("age", 25);
        set("long", HIC"他是春和楼的店小二。\n"NOR);
        set("kee", 100);
        set("max_kee", 100);
        set("sen", 100);
        set("max_sen", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("obj/cloth")->wear();
}

int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
    if( me->query("newplayer_questP")) {
      tell_object(me,"你已经完成过洗盘子的差使了，不能再做了！\n");
     return 1;
	}

    if( me->query_temp("gongzuo/xipanzi")>0){
                tell_object(me,"快去洗盘子吧。\n");
                return 1;
    } else
    if( me->query("daoxing")>100000) {
	me->set("newplayer_questP",1);
      tell_object(me,"你的道行已经不能再增长了！不用洗盘子了！\n");
     return 1;
	}
	message_vision(CYN"小二对$N说道：这几天客人多！盘子洗不过来，你去厅堂找管事要点盘子来洗吧。\n"NOR,me); 
       me->set_temp("gongzuo/xipanzi", 1);
       return 1;   
}

int accept_object(object me, object ob)
{
        object ob1;

        if (me->query_temp("gongzuo/xipanzi")<1) {
         command("say 你没有找我要过工作吧。\n");
        }
        else if ( ob->query("name") != "盘子" ) {
            command("say 这是洗好的盘子？你不是开玩笑吧！\n");
        } else {
		message_vision(CYN"小二对$N说道：辛苦了，这是你的劳动所得,加油呀！！！\n"NOR,me);
              me->delete_temp("gongzuo/xipanzi");
              me->delete_temp("gongzuo/geipanzi");
                if ( me->query("daoxing")>50000 
			&& me->query("daoxing")<=100000) {
                  me->add("daoxing",200);
                  me->add("potential",5);
                  me->add("combat_exp",10);
//                  me->add_maximum_force(1);
//                  me->add_maximum_mana(1);

                  ob1=new("/obj/money/silver");
                  ob1->move(me); 
                  call_out("destroying", 1, this_object(), ob);
                }
                else if (me->query("daoxing")<=50000) {
                me->add("daoxing",100+random(10));
                me->add("potential",5+random(5));
                me->add("combat_exp",5+random(10));
//                me->add_maximum_force(1);
//                me->add_maximum_mana(1);
 
                ob1=new("/obj/money/silver");
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                }
            return 1;
        }

	if (ob->query("money_id") && ob->value() >= 300) {
		tell_object(me, MAG"小二一点头，笑嘻嘻说道：多谢您了，您请进去休息吧。\n"NOR);
		me->set_temp("rent_paid",1);
		return 1;
	}

    return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
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
