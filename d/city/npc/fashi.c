/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
        set_name("法师", ({"fashi"}));
        set("age", 32);
        set("gender", "男性");
        set("long","一位法师。\n");
        set("attitude", "peaceful");
	set("per", 25);
        set("combat_exp", 8000);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 3);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("spells", 100);
        set("chat_chance", 4);
        set("chat_msg", ({
"法师嘴里不知道在念叨些什么咒术……\n",

}) );
	setup();

        carry_object("/d/lingtai/obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 太上老君急急如令！\n");
        return 1;
}

