//Edited by wuyou@sk_sjsh 2003-4-21

inherit NPC;
#include <ansi.h>
#define CRON_DIR "/d/quest/baoshi/baoshi.c" 

void create()
{
        set_name("武则天", ({"wu zetian", "wu"}));
        set("long", "一代女皇武则天，虽是一介女流，但她高高在上，其威严毫不逊色。\n");
        set("title", HIY"一代女皇"NOR);
        set("gender", "女性");
        set("rank_info/respect", "陛下");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 40);
        set("int", 40);
        set("max_kee", 700);
        set("max_gin", 700);
        set("max_sen", 700);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 800);
        set("mana", 800);
        set("mana_factor", 40);
        set("combat_exp", 220000);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);
        set_skill("force", 50);
        set_skill("seashentong", 50);
        set_skill("dragonforce", 50);
        set_skill("dragonstep", 50);
        set_skill("dragonfight", 50);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");
        map_skill("spells", "seashentong");
        set_weight(5000000);  
        setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init ()
{      
        object who=this_player();
        if(!who) return;

        call_out ("test_player",1,this_player());
        if ((int)who->query("quest/colors")){
        who->start_busy(2);
        }

}

string *strs = ({
  "$N对$n惊叹道：",
  "$N对$n赞赏道：",
  "$N微笑着对$n说道：",
  "$N赞许地对$n说道：",
});

void test_player (object who)
{
        object me = this_object();
        object where = environment (me);
       object newob; 
          int level;
        string str;
        int count, times, color;
        int i, j, k;
        mapping colors;

        colors=who->query("quest/colors");
        color=sizeof(colors);
        if (who->query("quest/colors")) 
        {  
                message_vision ("\n一进鸾凤殿，$N身上涌起淡淡的"+
                (color>2?chinese_number(color)+"彩":"")+
                "祥云。\n",who);
        }
        if(color == 7) { 
     
        message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
                  "七彩祥云缭绕，面生瑞气，朕果然有赏御赐与你！\n",me,who);
        message_vision ("\n$N走上前，赶紧在$n的殿前俯身跪下。\n",who,me);
        who->start_busy (3);
        times = (int)who->query("quest/number");
        if (times > 10000) times = 10000;
        count = times % 30;  
        i = 2500 + times*5/2 + 250 * (count + 1);
//        i = 2500 + times*5/2 + 200 * (count + 1);
        j = i + random(2000) - random(2000);
        k = i/5;
        who->add("daoxing", j);
        who->add("combat_exp", i);
        who->add("potential", k);
        who->add("balance", 30*i+25*j);
        who->add("weiwang", 10);
        who->delete("quest/colors");
    newob = new(CRON_DIR);
    if (newob->query("b_lvl") > 7) 
{
    level=random(7)+1;
     CRON_DIR->changename(newob,level);
   }
    newob->move(who); 
   message("channel:rumor",HIY"【"+HIR" 武则天 "NOR+HIY"】："+who->query("name")+"坚持不懈解迷，七彩祥云缭绕，朕有旨，赐"+chinese_daoxing(j)+"的道行！"+chinese_number(i)+"点武学！
"+chinese_number(k)+"点潜能！"+MONEY_D->money_str(30*i+25*j)+"的奖励,并奖励一个" + newob->name() + "\n"NOR, users() ); 

        call_out ("reward_player",2,me,who);
        }
}

void reward_player (object me, object who)
{

  message_vision ("\n$N连忙俯身一拜，小心翼翼地站起来。\n",who,me);

}

