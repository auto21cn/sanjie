//cigar
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int give_qingren();
void create()
{
         set_name(HIW"小阿修"NOR, ({"xiao cigar"}));
   set ("long", HIR@LONG


     这位就是情人节的礼物大使，你可以(ask xiao cigar)领取礼物

     你要领取情人节礼物必须要有十二点五万以上的武学才行！

     在此祝愿大家新春快乐，合家快乐，心想事成，万事如意！

     情人节与你心爱的人快乐的度过，是我最大的祝福与心愿！


        (补充说明：wx没有12.5万，ask了之后将不再给奖励，惩罚贪心，大意之人）
LONG);
           set("gender", "男性");
        set("title",HIY"★"+HIB"☆"+HIR"情人节礼物小使"+HIM"☆"+HIG"★"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("inquiry", ([
            "情人"    :(:give_qingren:),
            "约会"    :(:give_qingren:),
            "爱情"    :(:give_qingren:),
   ]));
        setup();
        carry_object("/d/obj/flower/rose999")->wear();
        carry_object("/u/cigar/obj/adier/marrys")->wear();
}
int give_qingren()
{
        object who=this_player();
        if (!userp(who)){
                  command("say 能要礼物吗？");
                return 1;
        }

         if (who->query("combat_exp") < 125000 ){
                command("joke "+who->query("id") );
                command("say 抓紧时间去练功吧，还有时间。");
                command("wave "+who->query("id") );
                return 1;
         }
         if (this_player()->query("lucky/qingren") > 0 ){
         message_vision("\n$N"+HIG"对着"+HIY"$n"+HIG"一巴掌刮了过来，“不要脸的东西，想背叛爱情”？\n",this_object(),this_player());
                command("say 已经拿过情人节礼物了，明年还有！\n");
        return 1;
        }
        who->add("potential",100000);
        who->add("kar",1);
        who->add("str",1);
        who->add("combat_exp",100000);
        who->add("daoxing",150000);
        who->add("per",1);
        who->set("lucky/qingren",1);
message_vision("\n$N"+HIR"对着"+HIG"$n"+HIR"说道："+HIY"“祝愿你新年快乐，并且祝愿你情人节美满、幸福。\n"NOR,this_object(),this_player());
        command("say  "+who->query("name")+"得到：
               武学十万点!\n 
               基本属性->臂力增加了一点!\n 
               基本属性->福缘增加了一点!\n 
               潜能增加了十万点!\n 
               道行增加了一百五十年!\n 
               基本属性->容貌增加一点\n");
                  return 1;
}

