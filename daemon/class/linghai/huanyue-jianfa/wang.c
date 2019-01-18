//by dewbaby@sk_sjsh
//【忘怀】
#include <ansi.h> 
#include <combat.h>
inherit SSERVER; 
        
        
       int perform(object me, object target) 
       { 
               object weapon, ob; 
               string msg; 
               string str; 
               int damage;
               int myexp,youexp;

              if( !target ) target = offensive_target(me); 
       
              if( !target 
              ||      !target->is_character() 
              ||      target->is_corpse() 
              ||      target==me) 
                      return notify_fail("你要对谁施展这招【忘怀】？\n"); 
       
       
              if( !me->is_fighting() ) 
                  return notify_fail("「忘怀」只能在战斗中使用。\n"); 

              if((string)me->query("family/family_name")!="凌海神宫")
                       return notify_fail("你不是凌海神宫中人，哪里偷学来的?\n");      
       
              if (!objectp(weapon = me->query_temp("weapon")) 
                      || (string)weapon->query("skill_type") != "sword") 
                              return notify_fail("你使用的武器不对。\n"); 
       
              if( environment(me)->query("no_fight") ) 
                      return notify_fail("在这里不能攻击他人。\n"); 
       
              if( (int)me->query_skill("huanyue-jianfa",1) < 200 ) 
                      return notify_fail("你的环月剑法等级不够，你怎么能使出【忘怀】？。\n"); 
       
              if (me->query("force") < 890) 
                      return notify_fail("你内力不继，难以使出「忘怀」。\n"); 
       
              myexp = (int) me->query("combat_exp");
              youexp = (int) target->query("combat_exp");
                      
              msg = HIW "$N使出凌海神宫绝技"HIB"「忘怀」"WHT+"手中宝剑上隐现出丝丝"HIB+"暗蓝"WHT+"之气\n\n" NOR; 
              message_vision(msg, me); 
       
              me->clean_up_enemy(); 
              ob = me->select_opponent(); 
    
              message_vision(HIY"$N身形迅如闪电，圈圈剑气不断地涌向$n。\n\n"HIB"$N吟：“山雨忽来溪水涨，风摇竹韵泪先淌。 
”\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIY"$N一招之后第二招随即而起，$n"HIY+"被困得手忙脚乱。\n\n"HIB"$N黯然道:“岩蛙应睡为何鸣，星月难期共谁赏。”"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIY"$N脚步渐慢，手中剑舞却毫不停顿。$n"HIY+"只能暗自叫苦。\n\n"HIB"$N仰天道：“好梦焉能每夜圆，痴心不记几回往。”"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
 
              message_vision(HIY"$N转身绕过$n，"HIY+"回手又是一剑，动作快而不躁。\n\n"HIB"$N咏:“依窗只说已忘怀，酒入愁肠偏又想。”"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIW"$N连连几剑出手，身法快若魅影。$n被剑气逼得无法动弹。\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              target->start_busy(3); 
              target->add("force", -200);
              target->add("kee", -200);
              target->add("sen", -200);
       
       
              return 1;   
       
      } 








