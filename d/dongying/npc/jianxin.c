// jianxin.c
// 飞天御剑  不断今朝绕指柔情
// 人斩拔刀  未绝昨日棰心痛恨

#include <ansi.h>

inherit NPC;


int choose_book();
void get_book(string arg, object ob);

void create()
{
	set_name( HIW "绯村剑心" NOR , ({ "feicun jianxin" , "feicun" , "jianxin" }));
	set("gender", "男性");
	set("title", HIR"浪客"NOR);
	set("age", 25);
	set("long", "他是一位英风凛凛的剑客。飞天御剑流十四代继承人。绰号“刽子手拔刀斋”，
	             因剑术高超，杀人不眨眼，而使敌人闻风丧胆。\n");
	set("shen_type", 1);
	set("per", 40);
	set("attitude", "peaceful");
	set("max_kee", 10000);
	set("max_sen", 10000);
	set("max_gin", 5000);
	set("force", 50000);
	set("max_force", 50000);
 	set("force_factor", 500);
 	set("max_mana", 50000);
 	set("mana", 50000);
 	set("mana_factor", 500);
 	set("combat_exp", 900000000);
	set("daoxing", 50000000);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("force", 400);
	set_skill("sword", 350);
	set_skill("feitian-jian", 350);
	map_skill("sword", "feitian-jian");
	map_skill("parry", "feitian-jian");
	map_skill("dodge", "feitian-jian");


	set("inquiry", ([
            "飞天御剑流" : "我学艺不精，我只有七成的功夫记载在书上，其他的我看要找我师傅了。\n",
            "比古清十郎" : "他是我的师傅，你有事找他吗? 他通常不见外人的。\n",
            "师傅" : "我的师傅是比古清十郎，说起来惭愧，我的剑法可比他差多了。\n",
            "剑谱" : (: choose_book :),
	]) );


	setup();

	carry_object("/d/dongying/obj/jxcloth")->wear();
        if (clonep(this_object())) { 
        object ob;
        if (ob = carry_object(BINGQI_D("sword") + "/niren-sword")) ob->wield(); } 
}


int choose_book()
{
        if( !this_player()->query_temp("pass_jianxin") ) {
        object me = this_player();
        write(HIG"\n您要哪本书：\n\n"NOR);
        write(HIW"(1)"HIC" 基础篇 "HIW"(2)"HIM" 进阶篇 "HIW"(3)"HIY" 终级篇 \n\n"NOR);
        write(HIG"请选择：(取消请按 q 或 Q)"NOR);
        input_to( (: get_book :), me);
        return 1;
        } else {
        return 0;
        }
}

void get_book(string arg, object ob)
{
	int  order;
        string order2;
        object shu;
   
        if( arg == "q" || arg == "Q" )    return;
        sscanf(arg, "%d", order);

        if (order <= 0 || order > 3)
        {   
        write(HIG"\n\n您要哪本书：\n\n"NOR);
        write(HIW"(1)"HIC" 基础篇 "HIW"(2)"HIM" 进阶篇 "HIW"(3)"HIY" 终级篇 \n\n"NOR);
        write(HIG"请选择：(取消请按 q 或 Q)"NOR);
        input_to( (: get_book :), ob);
        return;
        }

        switch(order) {
        case 1:
		shu=new("/d/dongying/obj/feitian-book1");
		shu->set("value", 0);
		message_vision("\n\n剑心伸手从怀里拿出一"+ shu->query("unit")+shu->query("name")+" 交了给$N \n", ob);
		shu->move(ob);
	break;

        case 2:
		shu=new("/d/dongying/obj/feitian-book2");
		shu->set("value", 0);
		message_vision("\n\n剑心伸手从怀里拿出一"+ shu->query("unit")+shu->query("name")+" 交了给$N \n", ob);
		shu->move(ob);
	break;

        case 3:
		shu=new("/d/dongying/obj/feitian-book3");
		shu->set("value", 0);
		message_vision("\n\n剑心伸手从怀里拿出一"+ shu->query("unit")+shu->query("name")+" 交了给$N \n", ob);
		shu->move(ob);
	break;
                      }
        return;
}

