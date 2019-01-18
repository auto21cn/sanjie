inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
        set_name(HIR"烈火孽龙"NOR, ({ "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 200);
        set("long", 
"这是一条全身赤红，吸天地之间的火气而长大的孽龙！
它全身散发着赤红色的火焰。\n");
        
        set("str", 248);
        set("con", 252);
        set("dex", 222);

        set("dodge", 5100);
        set("force", 5100);
        set("unarmed", 5100);
        set("parry", 5100);
        set("max_kee", 9999999);
        set("max_sen", 9999999);
        set("max_force", 901000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(30)+10);
        set("chat_msg_combat", ({
        (: big_blowing :)
        }) );

                set("combat_exp", 901100000+random(600110000));
                set("bellicosity", 30000 );
        
        set_temp("apply/attack", 1560+random(400));
        set_temp("apply/damage",1500+random(400));
        set_temp("apply/armor", 1500+random(400));

        setup();
} 
int big_blowing()
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n烈火孽龙深深地吸入一口气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n" NOR,
        this_object());
        call_out("hurting",random(1)+1);


       return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n烈火孽龙吐出一股炽可焚金的火焰．．整个天地似乎都被燃烧着！！！\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(300)+100;
        if(dam <0) dam = 0;
        inv[i]->receive_wound("kee",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
void die()
{
        object obj;
        object me;
        obj = new("/d/quest/tulong/obj/drug");
        obj->move(environment(this_object()));
        obj = new("/d/quest/tulong/obj/drug");
        obj->move(environment(this_object())); 
        if(objectp(me=query_temp("last_damage_from") )); 
          tell_object(me, HIR "\n\n一团火焰猛地升腾，一个声音说道：谢谢你解开了第四个封印，这两颗龙元就作为谢礼吧！！！\n"NOR); 
        message("channel:chat", HBMAG"【精灵神界】"+me->query("name")+"成功地杀死了恶龙，解开了封印！\n"NOR,users());

        {
            if(!me->query_temp("m_success/孽龙"))
                  {
                me->set_temp("m_success/孽龙",1);
                me->add("combat_exp",100000);
                me->add("daoxing",100000);
                me->add("potential",8000);
                 }
        }
        ::die();
} 


