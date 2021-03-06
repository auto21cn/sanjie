//Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit NPC;
string ask_money();
string ask_imbue();

void create()
{
        set_name("兵器铸造师", ({ "bingqi zhuzaoshi", "zhuzaoshi" }));
        set("nickname", HIY"巧夺天工"NOR);
        set("gender", "男性");
        set("long", "这名铸造师的技艺高超，听说是曾经打造出绝世神兵『干将』和『莫邪』宝剑的铸剑师的后人！
你可以向他打听他的事迹(name)。\n\n");
        set("age", 41);
        set("attitude", "heroism");
        set("unique", 1);
        set("combat_exp", 100000);
        set("no_quest", 1);
        set("str", 1000);
        set("int", 1000);
        set("con", 1000);
        set("dex", 1000);
        set("jiali", 200);
        set("max_kee", 900000);
        set("max_sen", 900000);
        set("max_mana", 900000);
        set("max_force", 900000);
        set("inquiry", ([  
                "dazao": (: ask_imbue() :),
                "money": (: ask_money :),
                "name": "我现在负责帮助玩家打造(dazao)武器，能打出最好的来！机率吗.....嘿嘿。

要求： 一把随意的武器(暗器不行)。
理论上最高威力可以达到目前三界世界中最好武器的两倍，还有很多附加属性。

限制： 每人经验一百万时可以打造，以后每二百万经验增加一次打造机会，好好把握哦！\n",
        ]) );
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_temp("apply/dodge", 700);
        set_temp("apply/parry", 700);
        set_temp("apply/attack", 700);
        
        setup();
        carry_object("/d/obj/cloth/linen")->wear();     
}

void init()
{
         ::init();
         add_action("do_imbue","dazao");    
         add_action("do_setimbue","setimbue");      
}

string ask_money()
{
         return "我现在已经赚了" + MONEY_D->money_str(this_object()->query("balance")) + "！";
}

string ask_imbue()
{
         object wp, me = this_player();
         mapping im;
         int i = me->query("get_imbue_weapon");
         
         if( !me->query("occupation") || me->query("occupation") != "铁匠")
                 return "只有铁匠才能打造兵器。\n";
                
         if( me->query("combat_exp") < 1000000 )
                 return "依您目前的水平，我看是用不了什么好武器的，你以后再来吧。\n";
                
         if ( me->query_temp("dazao_ask/name")|| me->query_temp("dazao_ask/id") ) 
                 return "不是让你去找打造兵器所需的原料吗？别磨蹭了。\n";
        
         if( i && i > time() )
                 return "还没打造好呢，你再等等吧！\n";
         if( i && i <= time() ){
                 me->delete("get_imbue_weapon");
                 if( !mapp(im = me->query("imbue_weapon")) )
                         return USER_WEAPOND->ask_imbue();
                 me->delete("imbue_weapon");
                 wp = USER_WEAPOND->make_weapon(me, im["type"], im["i"] , im["mar"]);  
                 if( wp )        
                         wp->move(me);
                 else return "武器生成出错，请通知 kuku! \n";
                 
                 me->add("user_weapon_imbued", 1);
                me->add("work/makeweapon",1);
                message("channel:rumor",HIM"【"+HIW"神兵现世"+HIM"】"+me->name()+"打造出了神兵"+wp->name()+"，威力不可小觑。\n"NOR,users());
                 message_vision("$N将打造好的"+wp->name()+"交给$n。\n\n", this_object(), me);
                 write(HIW"详细使用请看 uweapon 命令。\n"NOR);
                 return "别弄丢了！\n";
         }
                 
         return USER_WEAPOND->ask_imbue();
}
// special cmds for Kuku & Koker.
int do_setimbue(string arg)
{
         int i;
        
         // hehe...only 2 of us can do it :-)
         if( geteuid(this_player()) != "kuku" && geteuid(this_player()) != "koker")
                 return 0;
                
         if( !arg )
                 return notify_fail("格式： setimbue special|super|great|good\n");
        
         if( sscanf(arg, "%d", i)==1 ){
                 USER_WEAPOND->imbue_q(i);
                 return notify_fail("Setimbue -> imbue_sta == "+i+"\n");
         }
        
         if( arg != "special" && arg != "super" && arg != "great" && arg != "good" )
                 return notify_fail("格式： setimbue special|super|great|good\n");
                 
         USER_WEAPOND->imbue_s(arg);
         return notify_fail("Setimbue -> imbue == "+arg+"\n");
}

int do_imbue(string arg)
{
        object wp, me;
        string type, mar;
        int i,j;
        object *inv; 
        
        if( !living(this_object()) ) return 0;
        
        if( !arg )
                return notify_fail("格式： dazao <你身上要打造的武器>\n");
        
        me = this_player();
        
        if( (int)me->query("get_imbue_weapon") )
                return notify_fail("你先把打造的武器取了再说吧(ask zhuzaoshi about dazao)。\n");
        
        if ( !me->query_temp("dazao_ask/name")||!me->query_temp("dazao_ask/id") ) 
                return notify_fail("打造兵器还需要些原料，你必须问我(ask zhuzaoshi about dazao)才能知道都需要些什么。\n");
                
        if( me->is_fighting() )
                return notify_fail("等你打完再说吧。\n");
                
        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
                                
        if( geteuid(me) != "kuku" && geteuid(me) != "koker" && wizardp(me) )
                return notify_fail("巫师禁止打造兵器，请使用clone命令得到游戏中已有的武器。\n");
        
        if( !objectp(wp = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        
        if( !wp->query("weapon_prop") )
                return notify_fail("这里目前只能打造武器。\n");
        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你先忙完再说吧。\n");
                
        if( this_object()->is_busy() )
                return notify_fail("我正忙着呢，等等。\n");
                
        if( wp->query("equipped") )
                return notify_fail("要打造，请先放下手中的兵器。\n");
                
        if( wp->query("imbued") )
                return notify_fail("你这武器已经打造过了。\n");
                
        if( !stringp(type = wp->query("skill_type")) )
                return notify_fail("这里只能打造各式武器。\n");

        if( !me->query("occupation") || me->query("occupation") != "铁匠")
                return notify_fail("只有铁匠才能打造兵器。\n");
        
        if( wp->is_corpse() ){ 
                me->start_busy(5);
                message_vision("$N被吓得晕了过去！\n", this_object());
                this_object()->unconcious();
                return notify_fail("糟糕！\n");
        }
        if( me->query("combat_exp") < 1000000 )
                return notify_fail("依您目前的水平，我看是用不了什么好武器的，你以后再来吧。\n");
        
        if( me->query("combat_exp")/2000000 < (int)me->query("user_weapon_imbued") ){
                if( me->query("imbue_reward") )
                        me->delete("imbue_reward");
                else if( !me->query("imbue_paid") )
                        return notify_fail("依您目前的经验来说，这好武器还是以后再来打吧。\n");
        }
        
        if( me->query("imbue_paid") ){
                me->delete("imbue_paid");
                me->add("user_weapon_imbued", -1);
        }
        
        inv = all_inventory(me);                        
        for(j=0; j<sizeof(inv); j++) {
                if (inv[j]->query_temp("dazao_owner")==me->query_temp("dazao_ask/id") ){
                        message_vision("$N给了$n一"+inv[j]->query("unit")+inv[j]->query("name")+"！\n", me,this_object());
                        destruct(inv[j]);
                        me->delete_temp("dazao_ask");

                        switch(type){
                                case "sword": 
                                case "axe":
                                case "blade":
                                case "mace":
                                case "club": 
                                case "dagger":
                                case "fork": 
                                case "hammer": 
                                case "hook":
                                case "spear": 
                                case "staff": 
                                case "stick":
                                case "whip": break;
                                default:
                                        return notify_fail("这里不能打造这种武器。\n");
                        }
        
                        if( wp->id("xiao") ) type = "xiao";     
                        message_vision("$N拿出"+wp->name()+"想要$n帮忙打造。\n\n",me,  this_object());
                        this_object()->start_busy(2);    
                        me->start_busy(2);
                        mar = wp->query("material");
                        mar = stringp(mar)?mar:"steel"; 
                        destruct(wp);                    
                        if( me->query("combat_exp") > 15000000 && random(me->query("kar")) > 33  
                        && !random(me->query("per")) && !random(me->query("cps")) && me->query("work/makeweapon")>100 )
                                i = 4;          
                        else if( me->query("combat_exp") > 8000000 
                        && random(me->query("kar")) > 26 && random(20) > 15 && me->query("work/makeweapon")>50 )
                                i = 3;
                        else if(  me->query("combat_exp") > 4000000
                        && random(me->query("kar")) > 17 && random(15) > 11 && me->query("work/makeweapon")>20 )
                                i = 2;
                        else if(  random(me->query("kar")) > 12 )
                                i = 1;
                        else i = 0;
        
                        me->set("imbue_weapon/type", type);
                        me->set("imbue_weapon/mar", mar);
                        me->set("imbue_weapon/i", i);
         
                        if( !wizardp(me) ){
                                me->set("get_imbue_weapon", time() + 7200);
                                message_vision("$N点点头道：你一个时辰后来取吧。\n\n", this_object());
                        }
                        else {
                                message_vision("$N点点头道：打造好了。\n\n", this_object());
                                me->set("get_imbue_weapon", 10000);
                        }
                        return 1;
                }
                else{
                        command("say 你身上没有打造所需的原料。\n");
                        return 1;
                }
        }
        return 1;
}
