/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
	set_name("居民",({ "jumin" }) );
        set("gender", "男性" );
        set("age", 33);
	set("long", "一位中年男子，看起来越三十来岁。\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 10000);
	set("attitude", "peaceful");

        setup();

       carry_object("/d/obj/cloth/linen")->wear();
}

