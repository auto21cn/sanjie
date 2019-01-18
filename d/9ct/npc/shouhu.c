// 精华台守护神 天极 by Calvin
 
inherit NPC;
#include <ansi.h>
#include "star.h"
inherit F_MASTER;
 
void create()
{
        set_name(HIW"天极"NOR, ({"tian ji", "shouhu shen","shen","tianshen","ji","tianji"}));
        set("title",HIW"精华台守护神"NOR);
        set("long", "传说是盘古的滴血化身。其轮回精华之中,无生无灭。\n");
        set("gender","男性");
        set("age",37);
        set("con",40);
        set("attitude", "aggressive");
        set("per",30);
        set("str",43);
        set("int",54);
        set("combat_exp",10000000);
        set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "天极说道:看谁敢私闯精华台,小心我宰了他。\n"   
        }));
        set("max_force", 12000);
        set("force", 12000);
        set("max_mana",8000);
        set("mana",8000);
        set("mana_factor",300);
        set("force_factor", 300);
        set("max_gin", 1500);
        set("max_kee", 1500);
        set("max_sen", 1500);

        setup();
          carry_object("/d/9ct/zb/yjl")->wear();
              add_money("silver", 30); 
           carry_object("/d/9ct/zb/lingzhu")->wear();
           carry_object("/d/9ct/zb/baowu");
// carry_object("/d/9ct/obj/cao");
}
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：我乃$N，你想耍什么花样？\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object ghost;
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(6))
     {        
      case 0:
        {
        message_vision(HIY"$N手指$n，$N的指尖突然串出一道白光！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"白光之后，$N感到身上无比的疼痛！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
          }
        else
        message_vision(HIW"$N毫无惧色，一个转身，躲开了白光。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一吹口哨，一只大白鸟向$n冲去！\n",ob,me);

        if(random(2)==0)
                {
message_vision(HIM"$N被大白鸟一口咬中了要害！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N振作精神，仔细一看，原来只是幻象。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N双手合十，禁闭双眼，$n顿时迷惑起来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N感觉浑身的力量正从脚下被吸走！\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N站稳脚跟，好象在和大地搏斗。\n"NOR,me);
        }
        break;
                    

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}

