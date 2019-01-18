// chuanfu.c 老船长

#include <ansi.h>
inherit NPC;
int  chu_hai();
void goto_dao(object ob);
void create()
{
        set_name("老船长", ({ "lao chuanzhang","chuanzhang","lao" }));
        set("gender", "男性");
        set("age", 56);
        set("long",
        "这是一个老船长。饱经风霜的脸上透出一丝狡猾。他经常出海，以前曾经\n"
        "是个来往东瀛岛的商人。现在他拥有一艘大船可以出海。\n",
            );
        set("combat_exp", 500000);
        set("daoxing", 100000);
        set("attitude", "peaceful");
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("max_gin", 2500);
	set("force", 2000);
	set("max_force", 2000);
 	set("force_factor", 100);
 	set("max_mana", 2000);
 	set("mana", 2000);
 	set("mana_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("inquiry", ([
                
                "东瀛岛" : "东瀛岛是现在最繁荣的一个大岛，听说岛上的人武功都很厉害！\n",
                "出海" :   (: chu_hai :),
        ]) );
        setup();
        carry_object("/d/dongying/obj/cloth")->wear();
 }
int chu_hai()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision("老船长上上下下打量了$N一下：想要出海吗？总要给点样子我看看呀？！\n"
                 "老船长又想了一下：如果给我一两金子，或许可以考虑。\n"
                 ,ob);
  ob->set_temp ("出海" , 1 );
  return 1;
}
int accept_object(object who, object ob)
{
	object myenv;
    if (!(int)who->query_temp("出海"))
    {
    message_vision("老船长笑着对$N说：你给我钱干什么，您还是自己留着吧！\n", who);
    return 0 ;
    }
    if (ob->query("money_id") && ob->value() >= 10000) {
        message_vision("老船长对$N说：好！既然这位" + RANK_D->query_respect(who) +
        "出得起钱，\n那我就带你去一躺吧！\n" , who);
        this_player()->delete_temp("出海" );
        message_vision("老船长一招手，叫来几个年轻船夫。\n", who);
        message_vision("一声「起锚」之后，船就开走了.....\n", who);
        myenv = environment (who) ;
        who->move ("/d/dongying/dahai");
        tell_object(who, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("goto_shenlong",20,who) ;
        return 1;
    }
    else  
    message_vision("老船长皱眉对$N说：您给的也太少了吧？\n", who);
    return 0;
}
void goto_shenlong (object ob)
{
        if( !ob || ob->is_ghost()) return;
   tell_object(ob , "大船终于停在了一个小岛的海港边。你走下船来。\n" ) ;
   ob->move ("/d/dongying/haigang2") ;
}

