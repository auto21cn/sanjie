//xiaoer.c
#include <ansi.h>
inherit F_VENDOR_SALE;

void clear_room();

void create()
{
     
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("gender", "男性");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("vendor_goods", ([
                "tu": "/d/city/obj/tasktu",
                "jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "fire": "/obj/fire",
                "jitui": "/d/ourhome/obj/jitui",
                "huasheng": "/d/ourhome/obj/huasheng",
                "zhinan": "/d/obj/misc/xiaqi-zhinan",
        ]) );

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);

}

void init()
{      
        ::init();

        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        switch(random(2))
        {
        case 0:
                say(CYN "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob) +
                    CYN "，进来喝杯茶，歇歇腿吧。\n" NOR);
                break;
        case 1:
                say(CYN "店小二用脖子上的毛巾抹了抹手，说道：这位" +
                    RANK_D->query_respect(ob) + CYN "，请进请进。\n" NOR);
                break;
        }
}

