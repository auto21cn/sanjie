inherit F_VENDOR_SALE;
void create()
{
    reload("lanling_mawencai");
       set_name("马文才", ({"ma wencai", "ma","wencai","boss"}));
       set("long",
"这是一位上知天文下知地理的难得之才,只是家境贫寒,所以只得流落街头靠贩卖地图谋生!\n");
       set("gender", "男性");
        set("title", "地图尊者");
        set("combat_exp", 10000);
       set("age", 28);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
       set("vendor_goods", ([
                "box": "/d/calvin/obj/mapbox",
                 "he": "/d/calvin/obj/he.c",
       ]) );
        setup();
       add_money("silver", 15);
        carry_object("/d/obj/armor/mlcloth")->wear(); 

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say(name()+ "一副乡巴老的苦样走了过来：这位" +
RANK_D->query_respect(ob)
                                + "，要些地图吗?\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }

message_vision("\n忽然从远处跑过来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);  

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

