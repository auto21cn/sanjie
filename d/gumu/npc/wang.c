//轩辕古墓NPC 王贵人

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string say_key();
void punish_player(object me);
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name(HIW"王贵人" NOR, ({"wang guiren", "wang", "guiren"}));
    set_weight(1000000);
  set("gender", "女性" );
  set("age", 23);
   set("long", "
与妲己一同在昆仑山修炼的一只石琵琶精，道行尚浅，却禁不住人世间
五光十色、扑朔迷离滚滚尘世的诱惑，堕入魔道，终在朝歌被化做占卜
道士的太公望·姜子牙一记打神鞭送往了封神台，后与妲己一同逃脱
\n");
  set("title", HIB"玉石琵琶精" NOR);
  set("combat_exp", 10000000);
  set("attitude", "heroic");
  create_family("轩辕古墓", 1, "弟子");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set("per", 40);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("mace", 220);
  set_skill("parry", 220);
  set_skill("spells", 220); 
  set_skill("youming-spells", 220);
  set_skill("yinlei-mace", 220);
  set_skill("sword",220);
  set_skill("qinghu-jian",220);
  set_skill("blade", 220);
  set_skill("zizhi-blade", 220);
  set_skill("kongming-steps", 220);
  set_skill("jiuyin-zhua", 220);
  set_skill("force", 220);   
  set_skill("jiuyin-force", 220);
  map_skill("force", "jiuyin-force");
  map_skill("spells", "youming-spells");
  map_skill("unarmed", "jiuyin-zhua");
  map_skill("sword", "qinghu-jian");
  map_skill("parry", "zizhi-blade");
  map_skill("blade", "qinghu-blade");
  map_skill("dodge", "kongming--steps");
  map_skill("mace", "yinlei-mace");
  set("per", 50);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 150);
  set("mana",6000);
  set("max_mana", 3000);
  set("mana_factor", 150);
  set("inquiry",([
       "name": "我就是王贵人了，你要找我？",
       "here": "这里就是轩辕古墓天阴玄石殿，想在这里撒野，哼，还轮不到你！",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
    (: perform_action, "sword.hebi" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/sword/xy_sword.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
/**************************************************************/

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
if(me->query("family/master_id") != "da ji" && me->query("family/master_id") != "xi mei")
  {
      command("say 什么东西？也配拜我为师？");
      return 1;
  }
else  if (me->query_skill("jiuyin-force", 1) < 50 || me->query("combat_exp") < 200000)
  {
    command("say "+me->name()+"你个废物！就凭那点本事还不配！");
    return 1;
  }
else if (me->query_temp("gumu/kill")!="done") {
  command("bite");
  command("say 老娘恨一人入骨。"+myname+"去把他给我宰了，我要见他的信物！");
return 1;
}
  command("recruit "+myid);
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}


int prevent_learn(object me, string skill)
{
  int myyinlei=me->query_skill("yilei-mace", 1);
  if (wizardp(me) && me->query("env/immortal"))
    return 0;
  if (skill == "yinlei-mace")
  {
      if (myyinlei>=200)
      {
   command("say 你还不去给我杀了那个糟老头子？！小心我宰了你！");
   return 1;
      }
if (myyinlei<=1 && me->query_temp("gumu/kill")) return 0;
  if (myyinlei>1 && me->query_temp("gumu/kill")) return 0;
//      if (myyinlei141 && me-query("gumu/given_book_2")) return 0;
//      if (myyinlei=81 && me-query("gumu/given_book_1")) return 0;
      command("say 不教！此乃我自创绝学！");
      return 1;

    }
if (skill == "youming-spell" && me->query("gumu/kill")=="done")
  {
      call_out("punish_player", 1, me);
      return 1;
  }
  return 0;
}
int accept_object(object me, object ob)
{
        object nowords;
        if(userp(ob)) return 0;
        if( (string)ob->query("name")=="打神鞭" )
        {
                command("thank " + me->query("id"));
   command("say 嗯，果然是打神鞭。我自当履行诺言，收你为徒！");
         command("recruit "+me->query("id")); 
      me->set_temp("gumu/kill","done");
    return 1;
}
        else
{
            command("say 你给我的这是什么鬼东西？？？？？？");
            return 1;
}
}

