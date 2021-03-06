
// killer.c
// by mudring

inherit JOBNPC;

#include <ansi.h>
#include "stealer.h"

object owner() {return query("owner");}
void leave();

string *names = ({
  "蒙面", "疤脸", "残臂", "矮子",
  "黑衣", "凶残", "暴力", "独眼",
});

void setname()
{
    int i;
    string name;
    i = random(sizeof(names));
    name = names[i] + (random(2)?"土匪":"强盗");
    set_name(name, ({"bandit killer"})); 
}

void create()
{        
    setname();
    set("age", 100+random(80));
    set("gender", random(2)?"男性":"女性");
    set("attitude", "heroism");
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set("no_steal",1);
    set("taskguai",1);
    set("chat_chance", 5);
    setup();

    add_money("silver", 25 + random(10));
}

void init()
{
    if (owner() == this_player())
    {
        call_out("kill_owner", 0, owner());
    }
}

void kill_owner(object ob)
{
    command("say 想跑？没那么容易！");
    kill_ob(ob);
}

void heart_beat()
{
    object guai = this_object();
    object who = owner();
  
    ::heart_beat();  

    if (living(who) && is_fighting(who))
    {
        if (who->query("env/invisibility"))
        {
            who->delete_temp("yinshentime");
            who->set("env/invisibility",0);
            message_vision(HIW"\n$N吹了口气,$n又现出了身形。\n"NOR, guai,who); 
        }
    }
}       

void die()
{
    if (owner()) 
    owner()->add_temp("tongchuan/kk", 1);
    message_vision (CYN"\n$N喊道:  算你狠，无天老祖不会放过你的！！！\n"NOR, this_object());
    ::die(0, 1);
}

void leave()
{
    object guai = this_object();

    if (objectp(guai))
    {
        if (environment()) 
        { 
            message("vision",HIB + name() + 
                    "说道：到手了。说完变成一股青烟散去了。\n" NOR, environment());
        }
        guai->move(get_object("/obj/empty"));
        destruct (guai);
    }
    return;
}

