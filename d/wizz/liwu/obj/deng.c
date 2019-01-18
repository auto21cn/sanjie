// huadeng.c

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();



void create()
{
        set_name(HIG "元宵走马花灯" NOR, ({"deng", "hua deng","zouma deng"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 100000);
                set("long", "一个神奇的走马灯，点起灯来不停的走着你昔日的回忆图象，让你看到你亲人的熟悉面目\n");
        }

        set("is_monitored", 1);
        setup();
}
void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_give", "嘿嘿，做梦吧! \n");
                set("no_drop","这么美丽的花灯，哪能乱扔! \n");
                set("no_put",1);
                if (!(this_object()->query("owner")))
                      this_object()->set("owner",this_player()->query("id"));
        }

        add_action("do_eat", "dian");
}
int do_eat(string arg)
{
        object victim = this_player();
        int i, level,qn, which=0,max_level=0;
        mapping skill_status;
        string *sname,*str;
        if (!id(arg))
                {tell_object(victim ,"你要干什么？\n");return 1;}

                if (!(this_object()->query("owner")))
        {tell_object(victim ,"你想再次点起这盏灯，结果那等对你没反应！\n");return 1;}
        if (!(this_object()->query("used")) && !(victim->query("lll/deng_2004")))
        {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);

        victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                        qn=(int)victim->query("potential")-(int)victim->query("learned_points");

        qn=qn/5;
        victim->add("potential",qn);

        skill_status = victim->query_skills();
        sname  = keys(skill_status);

        for(i = 0; i < sizeof(skill_status); i++)
           {level = skill_status[sname[i]] ;
            if(level>max_level)
              {max_level=level;
               which=i;
              }
           }
        if(max_level>100)
         {
                tell_object(victim,"你得到两级技能!\n");
                victim->set_skill(sname[which],max_level+2);
         }
         else if(max_level>50)
         {
                victim->set_skill(sname[which],max_level+4);
                tell_object(victim,"你得到四级技能!\n");
         }
              else
              {
                  tell_object(victim,"你得到两级技能!\n");
                victim->set_skill(sname[which],sname[which],max_level+8);
                }
        victim->set("lll/deng_2004",1);
        this_object()->set("used",1);
        if( userp(victim) ) log_file("DENG2004", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

        message_vision(HIG "\n$N点起一盏神奇的元宵走马花灯，四周被这盏灯的祥和光芒照亮了！。\n"
        +"$N得到此灯的神奇的力量！\n" NOR, victim);


        return 1;
        }
        str=({"$N点起花灯，走马灯顿时现出$N丑陋的面孔！\n",
              "$N把灯举起来！花灯现出了祥和之光！",
              "$N小心的把灯点着，灯居然没亮！",
              "$N把灯点亮，被灯玄照一下，被吓楞了！",
              "$N把灯向上一抛，念起咒语，天空出现了美丽的彩霞！",
              "$N点着灯，对灯说道：灯神何在！花灯毫无反应，一副笨拙之像！",
             });

         message_vision(HIC+str[random(sizeof(str))]+"\n", victim);
        return 1;

}



