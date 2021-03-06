inherit NPC;
#include <ansi.h>

string ask_mofeng();
#define MOFENGD  "/d/quest/mofeng/mofengd"
void create()
{

        set_name("土地公公", ({ "tu di", "mofeng tudi", "tudi" }) );
        set("gender", "男性" );
        set("long", "长长的白发，和蔼可亲的白眉老公公，左手手持一个拐杖。\n");
        set("age",200);
        set("title", "看管魔风岭土地的");
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("spi", 30);
        set("per", 30);
        set("class", "xian");
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        set("daoxing", 2000000);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("force",5000);
        set("max_force",3000);
        set("force_factor", 150);
        set("mana", 5000);
        set("max_mana", 3000);
        set("mana_factor", 150);

      
       

        set_skill("unarmed",170);
        set_skill("dodge",400);
        set_skill("parry",170);
        set_skill("sword", 180);
        set_skill("force", 170);
        set_skill("spells", 170);
        set_skill("changquan", 170);
        set_skill("liangyi-sword", 180);
        set_skill("baguazhou", 170);
        set_skill("moshenbu", 170);
        set_skill("lengquan-force", 170);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("sword", "liangyi-sword");
        map_skill("parry", "liangyi-sword");
        map_skill("dodge", "moshenbu");

        set("chat_chance",10+random(5));
        set("chat_msg", ({
                    name()+"说道：哎。。多少神仙从此多灾多难!\n",
                    }));

        seteuid(getuid());

        set("inquiry", ([
        "攻打魔风岭": (: ask_mofeng :),
        "魔风岭":     (: ask_mofeng :),
           ]) );

        setup();
        carry_object("/d/obj/cloth/baipao")->wear();
        carry_object("/d/obj/weapon/staff/muzhang")->wield();
}

string ask_mofeng()
{
        object who = this_player();
        
        if (!userp(who)) return "滚!\n";
        if (who->query("combat_exp")<1000000) return who->name()+"武学太低还是别去为妙!\n";
        MOFENGD->add_player_list(who);
}
