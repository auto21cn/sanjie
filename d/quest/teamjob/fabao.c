//窃贼盗窃的天宫法宝
//fabao.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"天宫法宝"NOR, ({ "fa bao","fabao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long",
                        "一件天宫的小小法宝，被魔界窃贼所盗去。\n");
                set("value", 0);
                set("material", "steel");
                 
         }
}

void init()
{    
        add_action("do_chuansong", "chuansong");
}

int do_chuansong(string arg)
{
        int i,exp,pot,dx,count,base_exp,add_exp;
        object ob,me,*team;
              
        me=this_player();
        ob=this_object();
        if(!arg||arg!="fa bao") 
                return notify_fail("你要传送什么？\n");

        if(ob->query_temp("host")!= me->query("id")
        ||!me->query_condition("zzz_busy")||!me->query_temp("team_count"))
                return notify_fail("这件事好像和你没关系吧？\n");

        if (!present("fa bao",me) )
                return notify_fail("你身上没有天宫法宝。\n"); 
        //check ok
                message_vision(HIY"$N默运法力，只见天宫法宝被一团光球笼罩着。\n"+HIR"只听「轰」的一声，天宫法宝消失了 。\n"NOR, me);
        count=me->query_temp("team_count");
        if (count<2) count=2;   
        base_exp=1500/count;
        team=me->query_team();
        count=sizeof(team);
        //write("\n"+sprintf("%d",count));
        for(i=0;i<count;i++)
        { if(team[i]!=0)
                {
                        if (team[i]->query_condition("zzz_busy"))
                        {if(!team[i]->query("zzz_job_count"))
                         team[i]->set("zzz_job_count",1);
                         else
                         team[i]->add("zzz_job_count",1);  
                         add_exp=team[i]->query("zzz_job_count")/10;
                         exp=base_exp+random(200)+add_exp;
                         dx=exp+random(500)-random(500);
                         pot=exp/5+random(100);
                         team[i]->add("potential",pot);
                         team[i]->add("daoxing",dx);
                         team[i]->add("combat_exp",exp);
                         tell_object(team[i],HIW"你被奖励了：\n
                         " + chinese_number(exp) + "点实战经验！\n
                         " + chinese_number(dx) + "的道行！\n
                         " + chinese_number(pot) + "点潜能\n"+
                       NOR);
                        }
                        } 
                }
                  me->delete_temp("team_count");
                  
                ob->move(get_object("/obj/empty")); 

          return 1;
}


