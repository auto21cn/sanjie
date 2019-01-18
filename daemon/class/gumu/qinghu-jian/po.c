//轩辕古墓 青狐剑法 破·暴风忍
//by junhyun@SK
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 string msg;
 object weapon, weapon2;
 int skill, ap, dp, damage;

 me->clean_up_enemy();
 target = me->select_opponent();

 skill = me->query_skill("qinghu-jian",1);

 if( !(me->is_fighting() ))
  return notify_fail(HIW"「破·暴风刃」"NOR+"只能对战斗中的对手使用。\n");

        if( time()-(int)me->query_temp("po_end") < 5 ) 
                return notify_fail("绝招用多了就不灵了！\n"); 
 if (!objectp(weapon = me->query_temp("weapon"))
 || (string)weapon->query("skill_type") != "sword")    
  return notify_fail("你使用的武器不对。\n");


 if( skill < 110)
  return notify_fail("你的青狐剑法等级不够, 不能使用「破·暴风刃」！\n");

 if( me->query("force") < 1000 )
  return notify_fail("你的内力不够，无法召唤风暴」！\n");

 msg = HIC "$N手中"+weapon->name()+HIC"在空中划了一了半圆，同时大喝一声"+HIW"破·暴风刃。

"+HIG"霎时间，龙如卷，马长嘶，剑气如霜......

"HIY"$n眼前处处是寒光剑影，顿感感到一股巨大的压力冲击着自己。\n";
 message_vision(msg, me, target);

 damage = 10 + random(skill / 2);

 ap = me->query_skill("fork") +4*skill ;
 dp = target->query_skill("force") + 4;

 if( dp < 1 )
  dp = 1;                        

 if( random(ap) > random(dp) )
 {
           me->add("force",-100);
          if (objectp(weapon2 = target->query_temp("weapon")))
                {
                 msg = "突然$n觉得手臂一麻，手中";
                 msg += weapon2->name();
                 msg += "脱手而出！\n" NOR;
                 message_vision(msg, me, target);
                 weapon2->move(environment(me));
                 return 1;
                }
  target->receive_damage("kee", damage,me,"pfm");
  target->start_busy(4+random(skill)/20);
 msg = "$n被劲气吹的东倒西歪，顿时破绽百出！\n";
 message_vision(msg, me, target);
// me->start_busy(1);
        me->set_temp("po_end",time());
 return 1;
        }
 else
 {
   me->add("force",-100);
 if (objectp(weapon2 = target->query_temp("weapon")))
{
  msg = "可是$n看破了$N的企图，立刻将手中" + weapon2->name() + "舞
 得风雨不透，使$N的「破·暴风刃」没有起到作用。\n"NOR;
 message_vision(msg, me, target);
  me->start_busy(2);
 return 1;
}
 msg = "谁知$n手中根本就没有武器，$N顿时破绽百出！\n";
 message_vision(msg, me, target);
me->start_busy(2);
 return 1;
 }
                                       
 return 1;
}

