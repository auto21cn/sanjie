#include <ansi.h>
inherit F_VENDOR_SALE; 
int answer_me();
int answer_mudring();
int answer_douzi();
int answer_axj();
void clear_room();
void create()
{
set_name("莹莹", ({ "girl" }) ); 
set("title", "吧台小招待");
set("gender", "女性" );
set("color", HIW);
set("age", 22);
set("per",30);
set("str", 40);
map_skill("dodge", "moondance");
set_skill("moondance",900);
set("int", 40);
set("long",
"好可爱的小姑娘啊，一看见她你就想和她说几句话，\n不过不买酒她是不会和你说话的哦。" );
set("combat_exp", 30000000);
add_money("gold", 10);
remove_call_out("clear_room");
call_out("clear_room",300); 
set("attitude", "heroism"); 
set("force", 12000);
set("max_force", 12000);
set("force_factor", 10);
set("inquiry", ([
"here": "这里当然是小酒酒吧，欢迎光临。\n",
"???": "我知道的不多，可以回答的有 here,drink,hboy,plum,leoy,gg,mm,莹莹,food,小姐,酒,name,axj,买酒,mudring,douzi,xiaofeng \n",
"drink": "你想喝酒吗？那就先看看有什么酒再买吧～\n",
"hboy": "你说那个傻小子啊，哈哈。大笨蛋一个。\n",
"plum": "梅小姐你都不知道啊？那就是小酒的大姐头啊～ \n",
"leoy": "你说寒啊，好象是小酒的大姐头的老公啊～关系好复杂哦。 \n",
"gg": "哦，原来你想找个帅哥陪你啊，这个好办啊，象你这么漂亮不用我介绍都有人来找你呢。\n",
"mm": "你想找mm啊，那就凭你本事自己去找啊，让我给你介绍啊，多没出息。\n",
"莹莹": "那就是本小姐我的芳名啊，你怎么知道的，不会你对我有什么企图吧。。\n",
"food": "本酒吧只卖酒不卖吃的，要想吃东西可以去旁边的客栈买哦。\n",
"小姐": "你这个人怎么这么色啊，这里是很文雅的地方哦，没有那些乱七八糟的东西。\n",
"酒": "我们这里有红酒，啤酒，XO，人头马，各种名酒，请问您要什么呢？\n",
"name": "小女子叫莹莹，请多多指教，不过还要多喝酒哦。\n",
"axj" : (:answer_axj:),
"买酒": "您先坐，桌子上有酒单，请您看了以后再说。\n",
"mudring" : (:answer_mudring:),
"douzi" : (:answer_douzi:),
"xiaofeng" : (:answer_me:),
]) );
set_skill("dodge", 900);
set_skill("unarmed", 900);
set_skill("sword", 900);
set_skill("snowsword", 900);
map_skill("sword", "snowsword");
              set("vendor_goods", ([ 
"pijiu": "/u/axj/pijiu",
              ]) ); 
setup();
carry_object("/d/wizz/xianzi/marrycloth")->wear();
carry_object("/d/wizz/xianzi/shose")->wear();
carry_object("/d/wizz/xianzi/shoushi")->wear();
}
int accept_fight(object me)
{
command("say 老板吩咐过，不许和来这里的客人过招。");
return 0;
}
int accept_kill(object me)
{
           command("say 你怎么能对我这样呢，大家都是文明人啊。");
           return 0;
}
int answer_me()
{
        command("hehe");
          if (getuid(this_player())=="xiaofeng")
                     {
                        command("say 你就是xiaofeng啊,我主人的师傅啊!你好笨啊!你不是失去记忆了吧?\n");
                       return 1;
                      }
           command("say 晓峰就是我主人的师傅啊!这你都不知道,真是笨!\n");
        return 1;
}
int answer_mudring()
{
command("hehe");
if (getuid(this_player())=="mudring")
{
command("say 我看你就是哪个什么风铃吧～是不是想问我家小姐的事情啊？想问你就问啊，不问我怎么告诉你啊。\n");
 return 1;
 }
command("say 你说哪个mudring啊，他叫风铃。不过我觉得他人笨笨的，不过也挺可爱哦。\n");
 return 1;
}
int answer_douzi()
{
command("hehe");
if (getuid(this_player())=="douzi")
{
command("say 你就是那个豆子啊，还问我豆子是谁，你找打啊。别看你是西安的，我不怕你哦。\n");
 return 1;
 }
command("say 那个臭豆子，死豆子，炒豆子，煮豆子。你不说我还不生气呢，他就知道欺负我家小姐。你见到他帮我修理他哦。\n");
 return 1;
}
int answer_axj()
{
 command("hehe");
if (getuid(this_player())=="axj")
{ 
 command("say 小姐，就是你啊。想变个人来看我偷懒了吗？我可很勤快哦，一点都没有偷懒～\n");
return 1;
 } 
command("say 哦，那是我家小姐，也是这个店的老板，你对她要好点哦。\n");
 return 1; 
}
      void init() 
      { 
              object ob; 
                        ::init(); 
                        if( interactive(ob = this_player()) && !is_fighting() ) { 
                      remove_call_out("greeting"); 
                      call_out("greeting", 1, ob); 
              } 
}
void greeting(object ob)
{
        object ball;
        if( !ob || environment(ob) != environment() ) return;
        if((string)ob->query("id")=="axj" )
                {
                command("bow axj");
                say("酒吧小姐亲切的问候" + ob->query("name") + "：快进来坐下,我给你拿一杯饮料。\n");
                say("酒吧小姐为" + ob->query("name") + "拿来了一瓶菠萝啤。\n");
                ob->set("food",(int)ob->query("max_food"));
                ob->set("water",(int)ob->query("max_water"));
               }      
        if(ob->query_temp("kill_girl"))
               {
                message_vision("酒吧小姐对保安说道说道：这个在酒吧捣乱的人又来了,快快赶他出去！\n",ob);
                message_vision("只见几个魁梧的保安驾起$N拖到了门口，轮流一人一脚踢在$N的屁屁上面。\n",ob);
                ob->move("/d/city/kezhan");
                message_vision(ob->name() + "被小酒酒吧的保安踢了出来。\n",ob);
        }
        if((string)ob->query("id")!="axj") 
                say("酒吧小姐高高兴兴的跑来：这位" + RANK_D->query_respect(ob)
              + "请进，欢迎您来本酒吧消费。\n");
}

