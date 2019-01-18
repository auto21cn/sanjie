

#include <ansi.h>
inherit NPC;

int heal_other();

void create()
{
        set_name("天宫伤兵", ({ "shang bing", "bing" }));
        set("gender", "男性" );//性别与上面对应
        set("long",
"天宫护卫者，在守护天宫中不幸被妖兵打伤。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("nickname",HIC"誓死守护天宫"NOR);
        set("kee",300);
        set("sen",300);
        set("max_kee",400+random(590));
        set("max_sen",400+random(590));
        set("per", 25);
        set("age", 22);
        set("combat_exp", 200000+random(300000));
        set("chat_chance", 5);
        set("chat_msg", ({
                "天宫伤兵说道：唉呀呀，好疼啊！！\n",
                "天宫伤兵说道：这次全靠众位仙友，才能不失天宫！\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
        set("inquiry", ([
                "疗伤" : "谢谢这位仙家，你愿意救冶(jiuzhi)我？！\n",
        ]) );   
        
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

}
void init( )
{
        object ob;
        add_action("heal_other","jiuzhi");
        call_out("hunting",180);
}

void hunting()
{
        object ob=this_object();
        write(HIR"天宫伤兵，由于无人为其冶疗，吐血而亡！\n"NOR);
        destruct(ob);
}



int heal_other()

{
        object me=this_player(); 
        object ob=this_object(); 

        if (me->query("gender")=="男性")
                return notify_fail(HIC"这种事不适合大男人来做，你还是去抗击妖兵吧。\n"NOR);

        if ( (int)me->query("sen")<20)
                return notify_fail("你太累了，歇息一下吧。\n");

        if (me->query_temp("guo/sanbing")>9)
                return notify_fail("此人已经冶疗好了！\n");

       message_vision(HIB"$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....。\n"NOR,me,ob);
       me->add("sen",-me->query("eff_jing")/10);
       me->add_temp("guo/sanbing",1);
       if ( (int)me->query_temp("guo/sanbing")==8)

      {
            message_vision(CYN"$N过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,ob);
            me->delete_temp("guo/sanbing");
            if((int)me->query("combat_exp") < 1000000)   
            {
                message("vision", me->name() + HIG"由于成功的救冶了天宫伤兵,增加了200经验,一百天道行和100潜能。\n"NOR, me);
                me->add("combat_exp",200);
                me->add("daoxing",400);
                me->add("potential",100);
                me->add("weiwang",1);
                destruct(ob);
              }
        message("vision", me->name() + HIG"成功的救冶了天宫伤兵。\n"NOR, me);
        me->add("score",1);
        destruct(ob);

      
      }

      return 1;

} 


