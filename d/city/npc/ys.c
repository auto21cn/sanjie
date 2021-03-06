
inherit NPC;
#include <ansi.h>;
string bar_string =   "";
string blank_string = "　　　　　　　　　　　　    ";
string tribar_graph(int val, int eff, int max, string color);

int do_bihua(string arg);
int do_halt();

void create()
{
        set_name("妖神精灵", ({ "ys spirit", "spirit", "ys" }) );
        set("title", GRN "妖神第一" NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
        "妖神比武赛场上的执法官。\n");
        set("combat_exp",6000000);
        set("attitude", "friendly");

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        set("max_mana",2000000);
        set("mana",200000000);
        set("mana_factor",1000);
        set_skill("spells",1000);
        set_skill("buddhism",1000);

        map_skill("spells","buddhism");
        setup();
        carry_object("/obj/cloth")->wear();
//       carry_object("/obj/weapon/sword")->wield();
}


void init()
{
        ::init();       
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}
string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*15/max)*2-1]
                + ((eff > val) ? blank_string[(val*15/max)*2..(eff*15/max)*2-1]
: "") + NOR;
}

int do_bihua(string arg)
{     
        object ob1, ob2,*fighting;
        object old_target;
        
        ob1 = this_player();

fighting=all_inventory(this_object())->is_fighting();

        if(!arg || arg=="")
        {
                write("你要和谁比划？\n");
                return 1;
        }
        if ( sizeof(fighting)>=2)
                return notify_fail("现在有人正在比武！\n");


        if ( arg == "ys spirit" || arg == "spirit" || arg == "ys" )
           {
             command("hoho");
             command("say  "+ob1->name()+"，你为什么要和我比划？\n");
             return 1;
            }


        if (!ob2 = present(arg,environment(ob1)) ) 
                return notify_fail("你想跟谁比划？\n");

        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道" 
                        + RANK_D->query_self(ob1) 
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 fight 指令。\n" NOR);

                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
                return 1;
        }
            
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");


        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        if( ! present(ob1,environment()) ) return ;
        if( ! present(ob2,environment()) ) return ;

        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
        command("say " + ob1->query("name")
            + " 与 " + ob2->query("name") + "在妖神擂台上一决高下！\n");

//        this_object()->set_temp("busy",1);
        call_out("observe",1,ob1,ob2);
 }

int observe(object ob1,object ob2)
{
        object ob;
        object player;

        object where=environment();
        int time ,i;
        this_object()->add_temp("time",1);
        time =- this_object()->query_temp("time");
        i=99 +time;
      

  if(ob1->is_fighting()) 
        {
//ob1->command_function("cls");
//ob2->command_function("cls");
                if( i <= 0 )
                {
                command("say 时间结束，双方不分彼此！\n");
                ob1->remove_all_killer();
                ob2->remove_all_killer();

                  return 1;
                }
tell_room(where,"\n\n【"+HIC+ob1->name()+NOR+"】与【"+HIG+ob2->name()+NOR+
"】一决高下中..............\n");
     
tell_room(where,"〖气血〗"+tribar_graph(ob1->query("kee"),
ob1->query("max_kee"),ob1->query("max_kee"),HIG)+"〖" + i +"〗"
+tribar_graph(ob2->query("kee"),ob2->query("max_kee"),ob2->query("max_kee"),
HIG)+"〖气血〗\n");

tell_room(where,"〖精神〗"+tribar_graph(ob1->query("sen"),
ob1->query("max_sen"),ob1->query("max_sen"),HIR)+"     "
+tribar_graph(ob2->query("sen"),ob2->query("max_sen"),ob2->query("max_sen"),
HIR)+"〖精神〗\n\n");

               
 call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
        

        if ( !present(ob1, environment()) ) 
        {
                command("say " + ob1->query("name") + "落荒而逃！\n");
                this_object()->delete_temp("time");
                return 1;
        }

        if ( !present(ob2, environment()) ) 
        {
                command("say " + ob2->query("name") + "落荒而逃！\n");
                this_object()->delete_temp("time");
                return 1;
        }
           
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("say " + ob1->query("name") + 
                       "中途放弃比武！\n");
                this_object()->delete_temp("time");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("say " + ob2->query("name") + 
                       "中途放弃比武！\n");
                this_object()->delete_temp("time");
                return 1;
         }
      ob = new("/d/jz/obj/good");
        if ( ob1->query("kee")*2 > ob1->query("max_kee")
          && ob1->query("sen")*2 > ob1->query("max_sen") ) 
        {
              
                if  (ob2->query("kee")*2 > ob2->query("max_kee")
                  && ob2->query("sen")*2 > ob2->query("max_sen") )
                {
                        command("say " + ob1->query("name") 
                                + "与" + ob2->query("name") + "比武不分胜负！\n");
                this_object()->delete_temp("time");
                        return 1;
                }
                command("say " + ob1->name() 
                        + " 比武战胜 " + ob2->name() + "，奖励"+ob->name()
                +"一"+ob->query("unit")+"！\n");
                this_object()->delete_temp("time");
                ob->move(ob1);
        }
        else
        {
                command("say " + ob2->query("name") 
                        + " 比武战胜 " + ob1->query("name") + "，奖励"+ob->name()
                +"一"+ob->query("unit")+"！\n");
                this_object()->delete_temp("time");
                ob->move(ob2);
        }
        
        return 1;

}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}


