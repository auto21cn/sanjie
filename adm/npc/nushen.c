#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name("自由女神", ({ "ziyou nushen", "nushen"}));
  set("title", HIC"三界神话"NOR);
// 17    set("long", HIW"\n一位娇柔万分的女子，伶俐地扭动着腰肢。\n手举自由火把，有关于自由的事，可以问问她。\n"NOR+HIC"\n ask nushen about pk 选择ＰＫ的道路。\n ask nushen about nopk 选择ＮＯＰＫ的道路。\n ask nushen about gift 拿取取经完成大闹天宫过关的奖励。\n ask nushen about back 对你的人生选择有一次重新选择的机会。\n\n"NOR);
  set("long", HIW"\n一位娇柔万分的女子，伶俐地扭动着腰肢。\n手举自由火把，有关于自由的事，可以问问她。\n"NOR+HIC"\n ask nushen about pk 选择ＰＫ的道路。\n ask nushen about nopk 选择ＮＯＰＫ的道路。\n ask nushen about back 对你的人生选择有一次重新选择的机会。\n\n"NOR);
  set("color", HIW);
  set("gender", "女性");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);
  set("inquiry", ([ //
  "name" : "我就是蛇口站的自由女神，你可以选择“pk”或者“nopk”来决定你以后的人生。\n",
  "here" : "你可以选择“pk”或者“nopk”来决定你以后的人生。\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  /*
  "gift" : (:gift:),
  "奖励" : (:gift:),
  */
  "back" : (:back:),
  "反悔" : (:back:),
  ]));
  setup();
}

int pk()
{
    object who = this_player();
    if (who->query("pk")=="pk")
    {
        tell_object(who,"你已经选择了 PK 这条道路! \n");
        return 1;
    }
    else
    {
        message_system("自由女神："+who->name()+"已经选择了PK这条道路，望大家知照。");
        message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了PK这条道路，以后好自为之啦。”\n",who);
        who->set("ziyouchoose","pk");
        who->set("pk","pk");
        return 1;
    }
}

int nopk()
{
    object who = this_player();

    if (this_player()->query("PKS")>3)
    {
        tell_object(who,"你杀人过多，无法再选择 NOPK ！\n");
        return 1;
    }
    else
    {
        message_system("自由女神："+who->name()+"已经选择了NOPK这条道路，大家以后不要再为难他了。");
        message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了NOPK这条道路，以后请多帮别人的忙。”\n",who);
        who->set("ziyouchoose","nopk");
        who->set("nopk","nopk");
        who->set("ziyou","got");
        return 1;
    }
}

int back()
{
    object who = this_player();

    if (who->query("PKS") > 0)
    {
        tell_object(who,"自由女神对着$N说：“人都杀过了，还要怎么样？”\n");
        return 1;
    }
    if (who->query("ziyouback")=="got")
    {
        message_vision("自由女神对着$N说：“你的人生已经反悔一次了，做人还是不要太反复无常好？”\n",who);
        return 1;
    }
    else
    {
        message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经重新选择你的人生道路。”\n",who);
        who->delete("ziyouchoose");
        who->set("ziyouback","got");
        PKMANAGER_D->change_choose(who);
        return 1;
    }
}
