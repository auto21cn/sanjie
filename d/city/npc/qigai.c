inherit NPC;
static int base_price=5000;
void create()
{
        seteuid(getuid());
        set_name("乞丐", ({"qi gai", "qi"}));
        set("long", "这人衣衫褴褛，两眼醉意，身上有几个布袋，原来是个中年乞丐。\n");
        set("gender","男性");
         set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",50000);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        "乞丐伸出一个破碗：可怜.....可怜下吧。\n",
        "乞丐突然对你一笑：施舍几文钱吧......\n",
        "乞丐一声长叹：朱门狗肉臭，路有冻死骨。\n",
        (: random_move :)
        }));
        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("stick", 60);
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();

}
 

int accept_object(object who, object ob)
{       object m;
        int shishe;

        m=new("/d/ourhome/obj/shuidai.c");
        shishe=ob->value();
                
        if(!ob->query("money_id"))
                {
                command("say 施舍几文钱吧......");
                write("好象乞丐对你的东西不感兴趣。\n");
                return 0;
                }
        if( shishe < base_price ){
                command("say 好心有好报。");
                write("看来乞丐嫌你给的太少。\n");
                return 0;
                }
        else{
              if(objectp(present("shui dai", who)) ){
                  command ( "whisper " + who->query("id") + 
                  " 爷的大恩无以回报，你好心有好报! \n");
                  return 1;
               }	
              command ( "whisper " + who->query("id") + 
                " 爷的大恩无以回报，送你一个睡袋吧，出门在外，用得着的！\n");
              m->move(who);
        }
        return 1;
}

