//By waiwai@sjmd 2000/09/25
 
#include <ansi.h>
inherit NPC;
string tell_fortune();
string fortune1(object me);
string rsg(object me);
string ask_beauty()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("per")	< $1->query("per") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"的容貌在目前在线玩家中排名第 "
		HIR+chinese_number(no)+" "NOR;
}

string ask_age()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("age")*12+$2->query("month")
			< $1->query("age")*12+$1->query("month") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"的年龄在目前在线玩家中排名第 "
		HIR+chinese_number(no)+""NOR;
}

int ask_exp()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("combat_exp")	< $1->query("combat_exp") :), me);
	no = sizeof(ob) + 1;

	command("say "+me->name()+RANK_D->query_respect(me)+"的武学在目前在线玩家中排名第 "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$N指着$n赞叹道：“"+me->name()+"是在线玩家第 "
		HIR+chinese_number(no)+NOR" 武学高手！”\n" NOR, this_object(), me);
	return 1;
}

int ask_dx()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("daoxing")	< $1->query("daoxing") :), me);
	no = sizeof(ob) + 1;

	command("say "+me->name()+RANK_D->query_respect(me)+"的道行在目前在线玩家中排名第 "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$N指着$n赞叹道：“"+me->name()+"是在线玩家第 "
		HIR+chinese_number(no)+NOR" 道行高手！”\n" NOR, this_object(), me);
	return 1;
}

void create()
{
        set_name(HIM "小神仙" NOR, ({ "xiao shenxian","xiao"}) );
        set("gender", "女性");
        set("age", 20);
        set("title",HIG"仙子"NOR);
        set("nickname",HIY"果仙"NOR);

        set("per", 40);
	set("long", @LONG

[1;31m欲知祸福事，请问小神仙 --------[0m

LONG);
        set("combat_exp", 6000000);
        set("daoxing", 6000000);

        set("attitude", "heroism");
        set("str", 193);
        set("per", 40);
        set("max_kee", 650);
        set("max_gin", 700);
        set("force", 2750);
        set("max_force", 2750);
        set("force_factor", 150);
        set("max_mana",2750);
        set("mana",2750);
        set("mana_factor", 150);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
	set_skill("moonshentong", 350);
	set_skill("baihua-zhang", 350);
	set_skill("moonforce", 350);
	set_skill("snowsword", 350);
	set_skill("moondance", 350);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "puosui" :),
        (: cast_spell, "arrow" :),
        (: cast_spell, "mihun" :),
        (: cast_spell, "huimeng" :),
        (: cast_spell, "shiyue" :),
        (: cast_spell, "hufa" :),
        }) );

        set("inquiry", ([
	    "情义银丹" : (: rsg :),
	    "yindan" : (: rsg :),
		"age": (: ask_age :),
		"beauty": (: ask_beauty :),
		"exp": (: ask_exp :),
		"dx": (: ask_dx :),

          ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
            MAG"小神仙击节而歌:欲知祸福事，请问小神仙。\n"NOR,
            HIY"小神仙嘻嘻地笑了笑:我也要冲上光明宝塔！什么时候带我去呢？！\n"NOR,
            HIR"小神仙上下打量着你，眼中露出似水柔情。\n"NOR,           
                (: random_move :)
        }) );

        setup();
   add_money("gold", 5);
        carry_object("/d/moon/obj/feijian")->wield();
        carry_object("/d/obj/cloth/shoupipifeng")->wear();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/qujing/tianzhu/obj/tiekui")->wear();
        carry_object("/d/qujing/baoxiang/obj/zhanpao")->wear();
        carry_object("/d/qujing/qilin/obj/shield")->wear();
        carry_object("/d/obj/cloth/yuanxiang")->wear();
//        carry_object("/d/obj/book/baguatu");
        carry_object("/d/obj/fabao/bagua");

}

string rsg(object me)
{
        me = this_player();

        if( !me->query_temp("rsg/paid") )
        {
                if( me->query_temp("rsg/asked") ) 
                {
                        message_vision("小神仙白了$N一眼，不理$N了。\n", me);
                        return "今天真没意思，还没开张呢．．．\n";
                }
                else
                {
                        me->set_temp("rsg/asked", 1);
                        message_vision(HIR"小神仙嘻嘻一笑......\n"NOR, me);
//	    message_vision(HIM"小神仙"+HIR"盯着$N，馋得直流哈喇子：馋耶！！！\n"NOR, me);

                        return "不过．．．你确实要算的话得给我 "HIY"30gold \n"NOR;
                }
        }
        else
        {
                me->delete_temp("rsg");
                message_vision("小神仙掐起手指头，开始给$N算起来......\n", me);
                if(me->query("age")<16)
		    return RANK_D->query_respect(me)+
			"小孩子一边玩去，不给算！\n";
		else
                   return RANK_D->query_respect(me)+"好厉害耶，竟然吃了 "HIR+
		       me->query("rsg_eaten")+NOR" 个"+HIW"情义银丹"+NOR"了！！！\n";

        }
}

int accept_object(object me, object ob)
{
        if( ob->value() >= 300000 )
        {
                message_vision("小神仙嘻嘻一笑地对$N道："+RANK_D->query_respect(me)+"有什么事您尽管问吧！\n", me);
                me->set_temp("rsg/paid", 1);
                return 1;
        }
        else
        {
            command("say 您太客气了,不过给的也太少了，我还要靠着这个糊口呢！！！");
            return 1;
        }
}

