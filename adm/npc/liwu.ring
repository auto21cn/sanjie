// liwu.c

inherit NPC;
#include <ansi.h>

#include "2002.h"

int give_newbie();
int give_family();
int give_bag();
int give_book();
int answer_me();
int give_saozhou ();

void create()
{
    set_name("小小财神", ({"xiao caishen","caishen"}));
    set ("long", @LONG
他是在这里负责给新手做指引的，如果你是刚来到游戏，可以
向他寻求帮助(ask caishen about gift)，大家也可以要(saozhou)
打工，开始自己的三界神话历程(ask caishen about 扫大街)
LONG);
    set("gender", "男性");
    set("title",HIY"欢迎光临三界神话"NOR);
    set("age", 20);
    set("max_kee", 10000);
    set("kee", 10000);
    set("per", 40);
    set("attitude", "peaceful");
    set("inquiry", ([ //
        "bonnet"   : "这里有“金丝禅衣”，那个更好，我的天师法冠过时了，哎！",
        "东方财神" : "东方财神他住在深圳，有空可以打电话，tel：0755-6888808",
        "stey"     : "stey就是宝宝啊，你怎么蠢得连这都不知道？",
       "newbie"    :(:give_newbie:),
         "gift"    :(:give_newbie:),
         "礼物"    :(:give_newbie:),
       "family"    :(:give_family:),
       "新手礼物"  :(:give_newbie:),
       "门派礼物"  :(:give_family:),
        "百宝袋"   : (: give_bag :),
        "魔法书"   : (: give_book :),
        "name"     : (: answer_me :),
        "扫大街"   : (: give_saozhou :),
    ]));

    setup();
    carry_object("/d/lingtai/obj/faguan")->wear();
}

int answer_me()
{
    command("say 小心我扁你！嘿嘿 。\n");
    return 1;
}

int give_newbie()
{
    object who = this_player();

    if (who->query("combat_exp") > 410000)
    {
        command("hammer "+who->query("id") );
        command("say 你都这么厉害了还差这么一点小东西么？");
        return 1;
    }
    if (who->query("lll/gai") == "got")
    {
        command("heng " + who->query("id"));
        command("say 新人礼物只有一份！领过就不给了！\n");
        return 1;
    }

    who->add("combat_exp",80000);
    who->add("daoxing",80000);
    who->add("force",800);
    who->add("mana",800);
    who->add("maximum_force",1000);
    who->add("max_mana",1000);
    who->add("max_force",1000);
    who->add("maximum_mana",1000);
    who->add("potential",80000);
    who->set("lll/gai","got");
    message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",
                    this_object(), who);
    command("tell " + who->query("id") + 
       "你的道行增加了八十年!\n
        你的潜能增加了80000。\n
        您现在有1000点内力和1000点法力，您可以在Enable没有超过上述两值的情况下不用打坐明思\n");
    command("chat 恭喜恭喜，" + who->query("name") + "得到了新人礼物！");
    return 1;
}

int give_family()
{
    object who=this_player();
    string family;

    family=who->query("family/family_name");

    if (who->query("combat_exp") < 5000 )
    {
        command("addoil "+who->query("id") );
        command("say 现在拿礼物要求有诚心，你看看够不够武学5000,够了再来找我！？");
        return 1;
    }
    if (who->query("lll/skills") == "got" )
    {
        command("heng " + who->query("id"));
        command("say 门派礼物只有一份！领过就不给了！\n");
        return 1;
    }
    if (who->query("combat_exp") > 700000)
    {
        command("hammer "+who->query("id") );
        command("say 你都这么厉害了还差这么一点小东西么？");
        return 1;
    }
    if (!family)
    {
        command("pat " + who->query("id"));
         command("say "+who->query("name")+"你还是先去拜师吧，拜师之前你可以用\n"
                 "help menpai来看《三界神话》的各个门派介绍。\n");
         return 1;
    }

    STATU_D->set_npc_skill(who, 50, family);
    who->set("lll/skills","got");
    command("nod "+who->query("id") );
    command("chat " + family + "弟子" + who->query("name") 
            + "得到了门派奖励，希望以后多为本门派争光。");
    return 1;
}

#if 0
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}

void greeting(object who)
{
return;
    if (!who || environment(who) != environment()) return;
if (who->query("mudring/merry") > 0)
return;
    if (who->query("combat_exp") < 600000)
    {
who->add("potential", 20000);
who->add("combat_exp", 20000);
who->add("daoxing", 20000);
/*
        tell_object(who,"小小财神悄悄告诉你：可以向我要礼物哦(ask)(l xiao caishen)。\n");
        tell_object(who,"小小财神悄悄告诉你：可以向我要门派礼物哦(ask caishen about family)。\n");
*/
    }
who->add("potential", 20000);
who->add("combat_exp", 20000);
who->add("daoxing", 20000);
tell_object(who,BLINK HIM"\n\n\n\n\t\tMerry Christmas!\n\n"NOR);
tell_object(who,BLINK HIM"\n\n\t\t三界神话巫师组祝您圣诞快乐！\n\n"NOR);
who->set("mudring/merry", 1);
}
#endif

int give_bag()
{
    object bag,who;
    who = this_player();

    if (who->query("daoxing") < 500000 && !metep(who))
    {
        command("addoil "+who->query("id") );
        command("say 拿百宝袋需要五百年道行,够了再来找我！");
        return 1;
    }

    if (present("baibao bag",who))
    {
         message_vision("$N对着$n哼了一声。\n",this_object(), who);
         return 1;
    }
    bag =new("/obj/sjsh_bag");
    if (!objectp(bag))
    {
        command("say 百宝袋一时难拿到，等等！");
        return 1;
    }

    bag->set("owner_id", who->query("id"));
    who->start_busy(3);
 
    if (!who->query("sjsh_bag"))
    {
        who->set("sjsh_bag",1);
        bag->save();
        who->save();
    }
    if (bag->restore())
    {
        bag->save();
        bag->move(who);
        message_vision("$N对着$n神秘的笑了笑。\n$N拿出一个三界神话百宝袋给了$n。\n",
                       this_object(), who);
        return 1;
    } else
    {
        command("say 百宝袋一时难拿到，等等！");
        destruct(bag); 
        return 1;
    }
}

int give_book()
{       
    object book, who;
    who = this_player();

    if (present("magic book",who))
    {
        message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        return 1;
    }
         
    book =new("/obj/book/magic_book");
    if (!book)
    {
         command("say 魔法书一时难拿到，等等！");
         return 1;
    }

    book->set("owner_id",who->query("id"));
    who->start_busy(3);

    book->move(who);
    message_vision("$N对着$n神秘的笑了笑。\n$N拿出一个"+book->name()+"给了$n。\n",
                   this_object(),who);
    return 1;
}

int give_saozhou ()
{
    object ob;
    object who = this_player();

    if (present("sao zhou", who))
    {
        command_function("hmm");
        tell_object(who, CYN"你不是刚拿过吗，想倒卖啊？\n"NOR);
        return 1;
    }
    command_function("nod");
    ob = new("/d/quest/small/saozhou");
    ob->move(who);
    tell_object(who, CYN"小小财神拿出一把大扫帚给你，去扫大街吧！\n"NOR);
    tell_object(who, "你可以用(look saozhou)来获得帮助！\n");
    return 1;
}

