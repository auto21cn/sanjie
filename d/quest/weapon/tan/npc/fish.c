// animal: eat_fish.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("噬人鱼", ({ "fish", "yu" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "这是一只身形并不很大的鱼，浑身覆满绚丽的鳞片，\n"
            "一口锋利的牙齿，正虎视耽耽的看着你\n");
        set("attitude", "aggressive");

        set("max_kee",10000);
        set("str", 100);
        set("kar", 30);

        set("limbs", ({ "头部", "身体", "腹部", "尾巴" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000000);
        set("max_sen", 10000);
        
        set_temp("apply/attack", 45);
        set_temp("apply/damage", 200);
      set_skill("unarmed", 150); 
        set("force_factor", 100); 
        set_temp("armor", 53);
        setup();
}

void die()
{
        object ob;
        message_vision("$N口中吐出一颗夜明珠，肚皮往上一翻，$N死了。\n", this_object());
      ob = new("/d/quest/weapon/tan/item/zhenzhu");
        ob->move(environment(this_object()));
        destruct(this_object());
}

