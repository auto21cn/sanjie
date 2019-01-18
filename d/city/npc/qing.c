// 兰陵续 by Calvin
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("项世杰", ({ "xiang shijie", "xiang", "shijie","boss" }));
    set("title", HIG "笔缘书宛" NOR);
    set("nickname", HIW "草圣" NOR );
    set("shen_type", 1);
    set("str", 40);
    set("per", 40);
    set("gender", "男性");
    set("age", 20);
    set("long",
        "这个项世杰是专门给人改名字的。\n");
    set("combat_exp", 150000);
    set("attitude", "friendly");
    set("inquiry", ([
        "改名" : "风铃说我非法改名，吊销我的执照啦，去找别人吧！",
    ]));
    
    setup();
    carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
    object ob;
    
    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
/*
    add_action("do_name","改");
    add_action("do_name","change");
*/
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    switch(random(2)) {
    case 0 :
        say("项世杰笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
            "，快请进来歇口气吧。\n");
        break;
    case 1 :
        say("项世杰说道：哟！这位" + RANK_D->query_respect(ob) + 
            "您来了啊！不好意思，本人执照暂时被吊销，无法为您更名换姓？\n");
        break;
    }
}
/*
int accept_object(object who, object ob)
{
    
    if (ob->query("money_id") && ob->value() >= 1000000)
    {
        tell_object(who, "项世杰笑眯眯地说到：好吧，告诉我您想取个什么样的新名字。\n");
        tell_object(who, "请键入：改 新的中文名字\n");
        who->set_temp("fee_paid",1);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 1000000) 
    {
        tell_object(who, "项世杰嘿嘿一笑，说道：给我这麽多钱？ 将来我可没法还你啊。\n");
        return 1;
    }
    return 0;
}
int do_name(string target)
{
    object me;
    string old_name;
    me = this_player();
    old_name = me->query("name");
    if( !me->query_temp("fee_paid") ) 
        return notify_fail("项世杰冷冷地说道：不管叫我做什麽，您可得先付钱哪！\n");
    if( !target) 
        return notify_fail("项世杰迷惑不解地说道：快告诉我您新的名字呀！\n");
    if( old_name == target )
        return notify_fail("项世杰奇怪地对你说到：您的钱是不是来得太容易了！\n");
    if (!LOGIN_D->check_legal_name(target))
        return notify_fail("你的名字不合法，重新想一个名字吧！\n");
    me->delete_temp("fee_paid");
    me->set("name", target);
    command("chat " + old_name + "(" + me->query("id") +")从现在开始改名为：" + me->query("name") + "。大家以后别认错了人！\n");
    return 1;
}


*/
