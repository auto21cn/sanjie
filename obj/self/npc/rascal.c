// Update by Aeddy@2004-1-6

#include <ansi.h>
#include <login.h>

inherit NPC;

void create()
{
        string *my_name = ({ "恶棍", "恶霸", "流氓" });
        string *ob_name = ({ "小男孩", "小女孩", "年轻人", "小姑娘", "姑娘", 
                             "老头子", "老太太" });

        set_name(my_name[ random( sizeof(my_name) ) ], ({ "rascal" }) );
        set("help_ob_name", ob_name[ random( sizeof(ob_name) ) ]);
        set("long", sprintf("这是一名%s，样子很凶狠。\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);
        set("race", "妖魔" );

        set("str", 20 + random(11));            // 力量         
        set("cps", 20 + random(11));            // 定力
        set("cor", 20 + random(11));            // 勇气         
        set("per", 20 + random(11));            // 魅力
        set("int", 20 + random(11));            // 悟性         
        set("con", 20 + random(11));            // 根骨
        set("spi", 20 + random(11));            // 灵性         
        set("kar", 20 + random(11));            // 福缘

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：多管闲事，你活得不耐烦了吧！\n", name()),
                sprintf("%s喝道：呸！大爷的事也管，去死吧！\n", name()),
        }) );
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("force", 3500);
        set("max_force", 3500);          
        set("force_factor", 50);
        set("mana", 3500);      
        set("max_mana", 3500);          
        set("mana_factor", 50);
        set("sen", 5000);
        set("kee", 5000);

        set_skill("force", random(100) + 100 );
        set_skill("spells", random(100) + 100 );
        set_skill("unarmed", random(100) + 100 );
        set_skill("parry", random(100) + 100 );
        set_skill("dodge", random(100) + 100 );
        set("combat_exp", random(400000) + 900000);
        
        setup();

        carry_object("/obj/cloth")->wear();
}

void do_move()
{
        object *ob, me, player;
        int n, i;

        ob = users();
        i = sizeof(ob);
        i--;
        if( i< 0) return;
        me = this_object();
        player = ob[ random(i) ];

        if( wizardp(player) ) return;
        if( !environment(player) || player->is_fighting() 
        || player->query("combat_exp") < 150000 ) {
                me->move(START_ROOM);
                return;
        }

        me->move( environment(player) );
        n = player->query("combat_exp") + random(10000) - 5000;
        if( n <= 0 ) n = random(5000) + 1;
        set("combat_exp", n );

        n = player->query_skill("force", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("force", n );
        n = player->query_skill("unarmed", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("unarmed", n );
        n = player->query_skill("parry", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("parry", n );
        n = player->query_skill("dodge", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("dodge", n );

        message("system",HIW"┋"HIR"小道消息"NOR HIW"┋听说："+me->name()+NOR HIW" 正在为非作歹，欺负一位可怜的"NOR HIW+me->query("help_ob_name")+" \n"NOR,users());    

        tell_object(player, HIR"你突然听到远处传来一阵呼救声：“救命啊，救救我啊……”\n"NOR);
        tell_object(player, sprintf(WHT"你急忙跑过去一看，原来是一个%s正在欺负一位可怜的%s。\n"NOR, 
                me->name(), me->query("help_ob_name")));
        message_vision( sprintf( HIR"$N对%s喝道：“大胆狂徒，敢在光天化日之下欺压百姓！”\n"NOR, me->name() ), player);
        message_vision( sprintf( HIR"%s对$N喝道：“不要命了，敢管大爷的闲事！”\n"NOR, me->name() ), player);

        me->kill_ob( player );
        player->kill_ob( me );
}

void afterdie_func(object killer)
{
        object me;
        int m, n, i;

        me = this_object();
        message("system", HIW"┋"HIR"小道消息"NOR HIW"┋听说："+killer->name(1)+"("+killer->query("id")+")打败了"+me->name()+"，帮助了可怜的"+me->query("help_ob_name")+" \n" NOR, users() );

        message_vision( sprintf( "$N打败了%s，帮助了可怜的%s。\n",me->name(1), me->query("help_ob_name") ), killer);
        message_vision( "由于$N的侠义表现，$N得到了奖励。\n", killer);

        i = killer->query("daoxing") / 10000;
        if( i > 1000 ) i = 1000;
        m = random(50) + i / 10 + 1;
        n = random(500) + i + 1;
        killer->add("potential", m);
        killer->add("daoxing", n);
        tell_object(killer, sprintf("你的潜能增加了%s点！\n", chinese_number(m)));
        tell_object(killer, sprintf("你的道行增加了%s点！\n", chinese_number(n)));
}

