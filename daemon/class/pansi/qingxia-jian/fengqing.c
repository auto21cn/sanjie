// keelv.c 那一剑的风情
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // 对手的武器
        string msg;
        int i,attack_time,skill,damage;
        me=this_player();
        skill = me->query_skill("qingxia-jian",1);
//      target=this_object();
//      ob=target->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character() )                return notify_fail("「那一剑的风情」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("qingxia-jian", 1) < 200 )
                return notify_fail(HIM"你无法自行体会出「那一剑的风情」。\n"NOR);
               if(me->query("family/family_name")!="盘丝洞")
                            return notify_fail("“「那一剑的风情」”只有盘丝洞门人才可以用！\n");


              if( (int)me->query("max_force") < 2000 )
                return notify_fail("你的内力修为还不够高！\n");

        if( (int)me->query("force") < 1000 )
                return notify_fail("你现在的内力不足！\n");


        msg = HIM "$N轻声长叹,使出了「那一剑的风情」,剑招中带着三分惊艳,三分潇洒,三分可爱和一分不可一世。\n";

  if(random(me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int"))/3)
        {
 
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIM "那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n\n" NOR;
                        me->start_busy(1);
                        damage = 700 + random(skill);
                target->receive_damage("kee", damage,me,"pfm"); 
                target->receive_wound("kee", damage/3,me,"pfm");
                        target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n" NOR;
                          msg += "\n"YEL"那一剑,击断了$n手里的"+ob->query("name")+"。\n\n"NOR;

                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", YEL"断了的"NOR + ob->query("name"));
                        ob->set("long", "一"+ob->query("unit")+ob->query("name")+"。\n");
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        damage = 400 + random(skill);
                target->receive_damage("kee", damage,me,"pfm");
                        me->start_busy(1);
                        target->start_busy(1);

        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"那剑犹如一道电光闪过,却比彩虹更加绚丽!\n"NOR"\n"HIY"结果$n让自身真气灌注四周空间,消解了$N的剑意。\n" NOR;
                me->start_busy(2+random(1));
                message_vision(msg, me, target);

        } 

 me->add("force", -300);

                
}
