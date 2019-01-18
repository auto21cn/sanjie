// guanjia.c 管家

#include <ansi.h>

int random_go(object me, string* dirs);

//int change_tianyi();
//int change_tianyao();
//int change_tianmo();
//int change_cangshi();
//int change_leidao();
string ask_cancel();
int change_mieyao();
//int change_menpainame();

//int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"管家"NOR, ({"guan jia", "master"}));
       set("long", "三界山的管家，不干涉门派纷争，于是在岛上开了一家客栈。\n");
       set("title", HIC"三界山"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老仆人");
       set("max_kee", 500);
       set("max_gin", 100);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 50);
       set("combat_exp", 45000);
       set("daoxing", 55000);

	set("inquiry", ([
	"name"     : "我是这里的老板，你有事吗？\n",
	"here"     : "这里是「浪儿店」，你有需要可以进来住住店。\n",
//        "三界山"    : (:change_menpainame:),
/*      "天一宫"   : (:change_tianyi:),
      "天妖宫"   : (:change_tianyao:),
      "天魔宫"   : (:change_tianmo:),
      "藏尸地"   : (:change_cangshi:),
      "雷刀门"   : (:change_leidao:),
*/      
      "灭妖"     : (:change_mieyao:),
//      "礼物"     : (:gift:),
	]));
	
	setup();
}

void init()
{
object ob, me;
me=this_object();
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
}

int random_go(object me, string* dirs)
{
int             i, j, k;
object  newob;
mixed*  file;
if( !sizeof(dirs) )  return 1;
i = random(sizeof(dirs));
file = get_dir( dirs[i]+"*.c", -1 );
if( !sizeof(file) )
return 1;
k = sizeof(file);
while(1)  {
j = random(k);
if( file[j][1] > 0 )
break;
}
if( (newob=find_object(dirs[i]+file[j][0])) )   {
me->move( newob ); 
}
else  {
seteuid(getuid(me));
newob = load_object(dirs[i]+file[j][0]);
if (newob)
me->move(newob);
else  {
tell_object(me, "Error.\n");
}
}
return 1;
}

void greeting(object ob)
{
if( !ob || !visible(ob) || environment(ob) != environment() ) 
return;
switch( random(3) ) {
case 0:
say( name()+"笑咪咪地说道：这位" +RANK_D->query_respect(ob)+ "，进来歇歇脚吧。\n");
break;
        }
}
/*
int change_tianyi()
{
object tianyi;
object who=this_player();
message_vision("$N在帐本上草草几笔，对$n说道：“行了，你现在就是天一宫门人了。”\n",this_object(),this_player());
who->set("family","三界山");
who->set("title","「浪儿店」住客");
return 1;
}

int change_tianyao()
{
object tianyao;
object who=this_player();
message_vision("$N在帐本上草草几笔，对$n说道：“行了，你现在就是天妖宫门人了。”\n",this_object(),this_player());
who->set("family","三界山");
who->set("title","「浪儿店」住客");
return 1;
}

int change_tianmo()
{
object tianmo;
object who=this_player();
message_vision("$N在帐本上草草几笔，对$n说道：“行了，你现在就是天魔宫门人了。”\n",this_object(),this_player());
who->set("family","三界山");
who->set("title","「浪儿店」住客");
return 1;
}

int change_cangshi()
{
object cangshi;
object who=this_player();
message_vision("$N在帐本上草草几笔，对$n说道：“行了，你现在就是藏尸地门人了。”\n",this_object(),this_player());
who->set("family","三界山");
who->set("title","「浪儿店」住客");
return 1;
}

int change_leidao()
{
object leidao;
object who=this_player();
message_vision("$N在帐本上草草几笔，对$n说道：“行了，你现在就是雷刀门门人了。”\n",this_object(),this_player());
who->set("family","三界山");
who->set("title","「浪儿店」住客");
return 1;
}    
*/


/*
int gift()
{
object sanjie;
object who=this_player();
if (this_player()->query("lucky")==2)
{
message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
command("say 礼物只有一份！领过就不给了！");
return 1;
}
message_vision("$N在兜里掏出一道符咒，往$n头上一贴说道：“这是给你的奖励。”\n",this_object(),this_player());
//who->set("class",sanjie);
//who->set("family","三界山");
//who->set("title","「浪儿店」住客");
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
//who->set("maximum_force",3000); 
//who->set("max_force",3000); 
//who->set("force",3000); 
//who->set("maximum_mana",3000); 
//who->set("max_mana",3000); 
//who->set("mana",3000); 
//who->set("combat_exp",1700000); 
//who->set("daoxing",2000000); 
//who->set("sanjie","got");
who->set("lucky",2);
return 1;
}
*/

int change_mieyao()
{
    object who=this_player();
    string family;
    family=who->query("family/family_name");
   switch(family) {
    	case "三界山":      
        case "天一宫":      
        case "天妖宫":
        case "天魔宫":
        case "藏尸地":
        case "雷刀门":       
return "/d/obj/mieyao"->query_yao(who);
break;
        default:
         command("heng");
         command("say "+who->query("name")+"非我门人,何故来此? \n");
   //      return 1;
                     } 
}

string ask_cancel()
{
    object me=this_player();
// lost add
// if((int)me->query_temp("m_mieyao"))
if((int)me->query("secmieyao"))
{
      me->add("m_fangqi",1);
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
       me->delete("secmieyao_mudage");  
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}


int change_menpainame()
{
    object who=this_player();
    string family;
    family=who->query("family/family_name");
   switch(family) {
    	case "三界山":      
           command("say "+who->query("name")+"你没事！滚一边去！ \n");
             break;
        case "天一宫":      
           who->set("family","三界山");
           command("say "+who->query("name")+"已经脱胎换骨了！ \n");
             break;
        case "天妖宫":
           who->set("family","三界山");
           command("say "+who->query("name")+"已经脱胎换骨了！ \n");
             break;
        case "天魔宫":
           who->set("family","三界山");
           command("say "+who->query("name")+"已经脱胎换骨了！ \n");
             break;
        case "藏尸地":
           who->set("family","三界山");
           command("say "+who->query("name")+"已经脱胎换骨了！ \n");
             break;
        case "雷刀门":       
           who->set("family","三界山");
           command("say "+who->query("name")+"已经脱胎换骨了！ \n");
             break;
        default:
         command("heng");
         command("say "+who->query("name")+"非我门人,何故来此? \n");
   //      return 1;
                     } 
}


�
