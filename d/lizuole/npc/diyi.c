// 神话世界·西游记
/* 李作乐编于99.08.31 */
//diyi.c
 
inherit NPC;
//string apply_gongming(object me);
void do_drink();

void create()
{
        set_name("第一人", ({"diyi ren", "ren", "diyi"}));
        set("gender", "男性");
        set("age", 23); //岁数
        set("title", "天下");
        set("str", 500);
        set("int", 300);
        set("long", "第一人是李作乐创建的第一个npc\n");
        set("combat_exp", 30000000);
        set("attitude", "friendly"); //状态,(友好)\heroism (英雄主义)\peaceful (和平的)
        set("class", "scholar"); //等级,(学者)\xian (仙)\
      
        create_family("天魔宫", 1, "创始人"); //门派
        set_skill("unarmed", 500);
        set_skill("dodge",500);
        set_skill("literate", 1000);
        set_skill("parry", 500);
        set_skill("wuxing-quan", 60);
        set_skill("baguazhen", 70);
        set_skill("hammer", 90);
        set_skill("kaishan-chui", 100);
        set_skill("force", 70);   
        set_skill("zhenyuan-force", 70);
        set_skill("spells", 80);
        set_skill("taiyi", 80);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("hammer", "kaishan-chui");
        map_skill("dodge", "baguazhen");


        set("force", 5000); 
        set("max_force", 5000);
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 1000);
        set("mana", 1600);
        set("max_mana", 800);   
        set("force_factor", 40);
        set("mana_factor", 40);
   
        set("inquiry", ([
            "name" : "薄名何足挂齿...在下便是第一人，实是愧不敢当。\n",
            "here" : "这里便是苍穹。\n",
           ]) ); //设置ask
        
        set("chat_chance",20); //chat 偶然性
        set("chat_msg", ({
        "第一人低声长吟道：危楼高百尺，手可摘星辰。\n",
        "第一人低吟道：而来四万八千岁，不与秦汉通人烟。\n",
        "第一人鼓腹而歌：挥手自兹去，萧萧班马鸣。\n",

        "第一人击节而歌：赵客缦湖缨，吴钩霜雪明。银鞍照白马，飒沓如流星。\n",
        (: do_drink :),
        "第一人低吟道：夫天地者，万物之逆旅。光阴者，百代之过客。\n",

        "第一人击节而歌：脚着谢公屐，身登青云梯。半壁见海日，空中闻天鸡。\n",
        "第一人吟道：孤帆远影碧空尽，唯见长江天际流。\n",
        "第一人朗声吟道：蜀道之难，难于上青天，侧身西望长咨嗟。\n",
        (: do_drink :),
        "第一人低声长吟：红颜弃轩冕，白首卧松云。\n",
        "第一人醉态毕露，朗声长吟：醉看风落帽，舞爱月流人。\n",
        "第一人长吟道：音尘绝，西风残照，汉家陵阙。\n",
        (: random_move :) //随机移动
        //(: random_walk :), 随机走
        }));   
        
        set("maolu", 0); //毛驴
        setup();
        carry_object("/d/obj/cloth/choupao")->wear(); //穿戴
        carry_object("/d/obj/weapon/sword/changjian")->wield(); //兵器
        carry_object("/d/obj/book/poem"); //物品
        add_money("silver", 40); //钱
}

void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say 酒．．．给我酒．．．");
    }
    return;
}
