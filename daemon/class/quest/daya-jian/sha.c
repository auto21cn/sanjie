
#include <ansi.h>
inherit SSERVER;


int perform(object me, object target)
{

        object weapon;
        int attackp, defendp,damage;
        string msg,str;
        if(!me->query_skill("daya-jian", 1)) return 0;

        if(me->query_temp("pfm-sha-time")+10>time())
        return notify_fail("你刚用了「终极杀剑四气」！就想乱用「终极杀剑四气」！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if(((int)me->query_skill("daya-jian", 1) < 350 ||
            (int)me->query_skill("sword", 1) < 350) &&
            !me->query_skill("force"))
                return notify_fail("你的剑术基本功夫还不够娴熟，就想乱用「终极杀剑四气」？\n");


         if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("终极杀剑四气」只能对战斗中的对手使用。\n");
        if( (int)me->query("max_force") < 2500 )
                return notify_fail("你的内力修为太弱，根本使不出「终极杀剑四气」来！\n");
        if( (int)me->query("force") < 2000 )
                return notify_fail("你的真气不够！\n");
       if(me->query_temp("daya-sha")) return notify_fail("你已经在运用终极杀剑四气的无形杀气了！\n");

   message_vision( HIR "$N突然神情变得极其恐怖，暴喝一声,全身化为一道红色剑气直逼$n！\n" NOR,
                me, target );

        attackp = me->query_skill("sword", 1) + me->query_skill("daya-jian", 1) + me->query_skill("force", 1) / 2;
        defendp = target->query_skill("force",1) + target->query_skill("spells",1);

        me->set_temp("daya-sha", 1);

        if( attackp / 2 + random(attackp) > defendp/10 || !living(target) )
        {
                  message_vision(HIY "$p见到如此难以闪避，就地一滚但还是难以躲避。。\n" NOR, me, target );
                tell_object(me, HIB "你运起全身内力将剑气罩向" + target->name() + "!\n" NOR);
                  message_vision(HIY "$p顿时全身被剑气所伤,瘫倒在地!。”\n" NOR, me, target );
                tell_object(target, HIB "你登时心中一慌，气血翻腾，受伤不轻!。。。\n"    NOR);

                if( !target->is_killing(me) ) target->kill_ob(me);

                target->add("force", -1*((int)me->query_skill("unarmed", 1) + target->query("force_factor")) );
                if ( target->query("force") <1 ) target->set("force",target->qurey("max_force")/10);


                damage=(int)me->query_skill("sword", 1)*2 - (int)target->query("talk",1);
                damage=damage+me->query_str()+random(me->query_temp("apply/damage"))+me->query_temp("apply/damage");
                if (damage <100) damage=80;
                target->receive_damage("kee", damage,me,"pfm");
                target->receive_wound("kee", damage,me,"pfm");
                me->set_temp("pfm-sfa-time",time());
        if ((target->query("eff_kee")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"被"+me->name()+"用"+HIW"终极杀剑第一气"+HIM"杀死了。";
             message("channel:rumor",HIG"【"+HIR"三界神话"HIG"】"+HIM"某人："+str+"\n"NOR,users());
       }
                target->start_busy(3 + random(2));
                me->add("force", -300);
                 call_out("perform3", 1, me, target);

                call_out("del_sucked", 15, me);
        }
        else
        {
                message_vision(HIY "可是$p看破了$P的企图，迅速地避开了终极杀剑四气。\n" NOR, me, target);

                call_out("del_sucked", 25, me);

        }

       me->set_temp("targett",target);
       return 1;
}

void del_sucked(object me)
{

        if ( me->query_temp("daya-sha"))
        me->delete_temp("daya-sha");

}

int perform3(object me, object target)
{

        object weapon;

        int damage;
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("你微微地一笑,缓缓收回剑气，傲然而立!!\n");

        msg = CYN "$N神情肃然，力挽剑身舞起万个剑气，罩向$n。\n"NOR;
        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("daya-jian")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("talk",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-jian", 1);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                target->start_busy(3 + random(2));
                 if ((target->query("eff_kee")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"被"+me->name()+"用"+HIW"终极杀剑第二气"+HIM"杀死了。";
             message("channel:rumor",HIG"【"+HIR"三界神话"HIG"】"+HIM"某人："+str+"\n"NOR,users());
       }
              if( (int)me->query("force") < damage/2 )
                me->set("force", 0);
                me->add("force", -damage/2);
                msg += HIR"只见$N剑气聚为一线，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
        } else
        {
                msg += CYN"可是$p猛地向前一跃,跳出了$P的剑气范围。\n"NOR;
                me->add("force", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        call_out("perform4", 1, me, target);

        return 1;
}

int perform4(object me, object target)
{

        object weapon;

        int damage;
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("你微微地一笑,缓缓收回剑气，傲然而立!!\n");

        msg = CYN "$N神情突变，运起剑身发出第三剑气-杀剑气，直冲向$n。\n"NOR;
        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("daya-jian")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("talk",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-jian", 1);

                target->receive_damage("kee", damage*2);
                target->receive_wound("kee", damage);
                 if ((target->query("eff_kee")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"被"+me->name()+"用"+HIW"终极杀剑第三气-杀剑气"+HIM"杀死了。";
             message("channel:rumor",HIG"【"+HIR"三界神话"HIG"】"+HIM"某人："+str+"\n"NOR,users());
       }
              if( (int)me->query("force") < damage/2 )
                me->set("force", 0);
                me->add("force", -damage/2);
                msg += HIR"只见$N剑气聚为一道血红杀光，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
        } else
        {
                msg += CYN"可是$p猛地向前一滚一爬,跳出了$P的剑气范围。\n"NOR;
                me->add("force", -100);
                me->start_busy(5);
        }
        message_vision(msg, me, target);
        call_out("perform5", 1, me, target);

        return 1;
}

int perform5(object me, object target)
{

        object weapon;

        int damage;
//
        string msg,str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
           return notify_fail("你微微地一笑,缓缓收回剑气，傲然而立!!\n");
        msg = CYN "$N神情突变，运起剑身发出第四剑气-绝剑气，直冲向$n。\n"NOR;
        if( !target->is_killing(me) ) target->kill_ob(me);
        if (random(me->query_skill("daya-jian")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("talk",1) / 200 + 1);

                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("daya-jian", 1);

                target->receive_damage("kee", damage*4);
                target->receive_wound("kee", damage*2);
                 if ((target->query("eff_kee")< 0 || !living(target)) && userp(target))
        {
            str=target->name()+"被"+me->name()+"用"+HIW"终极杀剑第四气-绝剑气"+HIM"杀死了。";
             message("channel:rumor",HIG"【"+HIR"三界神话"HIG"】"+HIM"某人："+str+"\n"NOR,users());
       }
              if( (int)me->query("force") < damage/2 )
                me->set("force", 0);
                me->add("force", -damage/2);
                msg += HIR"只见$N剑气聚为十道血红杀光，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，倒地鲜血狂喷而出气绝了！\n"NOR;
        } else
        {
                msg += CYN"可是$p猛地再次向前一滚一爬,跳出了$P的剑气范围。\n"NOR;
                me->add("force", -100);
                me->start_busy(5+random(5));
        }
        message_vision(msg, me, target);
        return 1;
}


