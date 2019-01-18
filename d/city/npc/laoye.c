// Update by waiwai@2001/03/21 

#include <ansi.h>
inherit NPC;
void del_gaoed(object me);
void create()
{
        set_name("蔡建德",({"cai zhifu", "zhifu"}));
        set("title", "长安知府");
        set("nick_name", HIR"廉明清正"NOR);
        set("gender", "男性");
        set("age", 54);
        set("long",
        "困死了，做完这个不做了，\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("sen", 2000);
        set("max_kee", 5000);
        set("kee", 5000);
        set("combat_exp", 200000);
        set_skill("blade", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set("chat_chance", 8);
        set("chat_msg", ({
       "威…威…威…\n",
        }));
        set("inquiry", ([
        "告状": HIC "你想告谁,我可是很清廉的好官哦!\n" NOR,
        ]));

        setup();
         carry_object("/d/obj/cloth/choupao")->wield();
        }
void init()
{
add_action("do_gao","gao");
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() <50000+random((50-who->query("kar")))*10000)        {
        tell_object(who, "知府大人勃然大怒，说道：大胆！竟敢对本官行贿？\n");
        message_vision(CYN"知府大人大喝道:大胆狂徒,胆敢行贿，来人给我拖下去重责五十大板！\n"+
                        "两旁闪出几个身强力壮的衙役一佣而上,架起$N就拖了出去,接着板子\n"+
                        "像雨点般打在$N的屁股上,打的$N哭爹喊娘，叫天天不应，叫地地不灵。\n"NOR,who);
        message_vision(YEL"突然$N一口气没上来,晕死过去，一个衙役来到知府大人身边耳语了几句\n"+
                        "只听知府大人说:这次暂且饶你一次，下次再敢行贿本官，决不轻饶，退堂！\n"NOR,who);
        who->move("/d/city/laofang");
	who->set_temp("summon_time",300);
        who->unconcious();
        return 0;
       }
        else {
        message_vision(HIY"知府大人对$N嘿嘿地笑了几声。\n"NOR,who);
        who->set_temp("gao_paid",1);
        }
        return 1;
}


void beating(object ob)
{
        message_vision(CYN"知府大人大喝道:大胆狂徒,胆敢诬告,来人,给我托下去重责五十大板！\n"+
                        "两旁闪出几个身强力壮的衙役一佣而上,架起$N就拖了出去,接着板子\n"+
                        "像雨点般打在$N的屁股上,打的$N哭爹喊娘，叫天天不应，叫地地不灵。\n"NOR,ob);
        message_vision(HIR"突然$N一口气没上来,晕死过去，一个衙役来到知府大人身边耳语了几句\n"+
                        "只听知府大人说:这次暂且饶你一次，下次再张嘴乱咬人，决不轻饶，退堂！\n"NOR,ob);
        ob->move("/d/city/laofang");
        ob->unconcious();
}


void beating2(object ob)
{
        message_vision(HIY"知府大人喝道:大胆狂徒, 就算你犯了案吧！来人,给我托下去重责五十大板！\n"+
                        "两旁闪出几个身强力壮的衙役一佣而上,架起$N就拖了出去,接着板子\n"+
                        "像雨点般打在$N的屁股上,打的$N哭爹喊娘，叫天天不应，叫地地不灵。\n"NOR,ob);
        message_vision(HIR"突然$N一口气没上来,晕死过去，一个衙役来到知府大人身边耳语了几句\n"+
                        "只听知府大人说:这次暂且饶你一次，以后如果再落在本官手里，决不轻饶，退堂！\n"NOR,ob);
        ob->move("/d/city/laofang");
        ob->unconcious();
}

void dzj(object ob)
{
int j;
message_vision("两旁衙役高呼:威～～～\n",ob);
j=random(3);
if (j == 0){remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
message_vision("两旁衙役高呼:威～～～\n",ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
        if (objectp(me) &&  me->query("gaoed"))
           me->delete("gaoed");
}

int do_gao(string str)
{
        object ob,me;
      
        me=this_player();

        if (!me->query_temp("gao_paid")) return notify_fail("再怎么也得交点手续费嘛！\n" );

        if((int)me->query("combat_exp")<1000000)
        return notify_fail("就你这么点修为,还在瞎告什么呢！\n" );

        if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);

        if (!ob) ob= find_living(str);

        if (!ob) return notify_fail("找不到你要的疑犯！\n");
        me->set("gaoed",1);

        if(ob->query("id")=="waiwai")
        {call_out("beating", 1, me);}
	else
        if(!ob->query_condition("killer"))
        {call_out("beating", 1, me);}
	else
        if (me->query_condition("killer")>0) {
        message_vision(HIY"知府大人喝道：大胆$N自己犯科还要来告他人, 是你自己送上门来的！
来人,给我投入大牢，等待秋后处斩。。。\n"NOR,me);
        me->delete("gaoed");

        me->move("/d/city/misc/dalao");
	}
             else {

        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");

        tell_room(environment(ob),"一群衙役一拥而上，把"+
        (string)ob->query("name")+"绑了个结实，然后押着去了官府。\n", ob);

        tell_object(ob,"一群衙役一拥而上，对你说：有人告了你，跟爷几个去一趟衙门吧！\n");

        ob->move(environment(me));
        me->start_busy(2);
        ob->set("summon_time",time());

        tell_object(me, (string)ob->query("name")+"被抓到了衙门。\n");

        tell_object(ob,"你发现是"+(string)me->query("name")+
                "告你的.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然被抓"+
        "到衙门来了。\n",({me,ob}));

          message_vision("\n$N看到$n站在大堂上暗笑不止,不由心火上升"
                +(string)me->query("name")+ "咱们等着瞧！\n",ob,me);

	if( (ob->query("summon_time")+3600) >time()) {

        message_vision(HIY"知府大人喝道:大胆狂徒, 到了这里还不老实！来人,给我投入大牢，等待秋后处斩。\n"NOR,ob);

        ob->move("/d/city/misc/dalao");
	} else
        if (random(10)<7) call_out("dzj2", 5, ob);
        else {
        message_vision(WHT"知府大人大声喝道: 这次算你走运，既然没有犯案，来人那，给我乱棍打出去！\n" NOR,ob);
        message_vision(WHT"只见两旁冲出几个衙役将$N乱棍打了出去！\n" NOR,ob);
        ob->move("/d/city/caishikou");
	}
       }

       return 1;
}