//Cracked by fbbz
//Ansi 2001/10

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,damage,mypot;
        string msg;
        object weapon;
        int k1,k2,k3,k4;        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「剑魂」？\n");

        if(!me->is_fighting())
                return notify_fail("「剑魂」只能在战斗中使用！\n");
                
        if (!PFM_D->valid_family(me, "蜀山剑派"))
                return notify_fail("不是蜀山的不能用「剑魂」！\n");
                
        if ((int)me->query_skill("shushan-jianfa",1)<120)
                return notify_fail("你的蜀山剑法修为还不够，使用这一招会有困难！\n");
        if ((int)me->query_skill("yujianshu",1)<120)
                return notify_fail("你的御剑术修为还不够，使用这一招会有困难！\n");
        if ((int)me->query_skill("mindsword",1)<120)
                return notify_fail("你的心剑修为还不够，使用这一招会有困难！\n");
        if ((int)me->query_skill("canxin-jian",1)<120)
                return notify_fail("你的残心剑修为还不够，使用这一招会有困难！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 800 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        dp = target->query("combat_exp"); 
        ap = me->query("combat_exp"); 
     
        msg=HIW"\n$N大喝一声，"+HIR"“万剑之尊，唯我蜀山”，"+HIB"「剑魂」随声而出！\n"NOR;
        msg += HIM"只见$N手中长剑在空中划了个半弧，"+HIG"「御剑」"+HIM"从天而降，盖天的射向$n！\n"NOR;
        k1=(int)me->query_skill("yujianshu",1);      
        mypot=k1*k1*k1/10 + ap;        
        if ( random( mypot+dp ) > dp*3/5 ) 
        {              
                damage = k1+random(k1)+me->query("force_factor");
                msg += HIC"结果$n"+HIC"被漫天"+HIG"「御剑」"+HIC"射个半死！\n"NOR;
                message_vision(msg, me, target);                                                                     
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm"); 
                COMBAT_D->report_status(target);                                 
        }
        else 
        {
                msg +="但是被$n全躲开了。\n"NOR;
                message_vision(msg, me, target);       
        }
        msg = HIY"只见$N长剑倒转，剑尖向心，"+HIM"「心剑」"+HIY"随后而出，剑穗笔直扫向$n！\n"NOR;
        k2=(int)me->query_skill("mindsword",1);      
        mypot=k2*k2*k2/10 + ap;        
        if ( random( mypot+ dp) > dp*3/5 ) 
        {              
                damage = k2+random(k2)+me->query("force_factor");
                msg += HIC"结果$n"+HIC"被扫个正着！\n"NOR;
                message_vision(msg, me, target);                                                                      
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg +="$n看破了你的企图，挡开了剑穗。\n"NOR;
                message_vision(msg, me, target);       
        }
     
        msg = HIG"$N手中长剑不停，剑尖刺向胸口，顿时出现一缕悲愤而惆怅的情思，原来竟是"+HIB"「残心剑」"+HIG"！\n"NOR;
        k3=(int)me->query_skill("canxin-jian",1);      
        mypot=k3*k3*k3/10 + ap;        
        if ( random( mypot+dp ) > dp*3/5 ) 
        { 
                damage = k3+random(k3)+me->query("force_factor");
                msg += HIC"结果$n"+HIC"毫无防备，被这惆怅的剑气染透！\n"NOR;
                message_vision(msg, me, target);   
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg +="但是被$n就地一躺，躲开了。\n"NOR;
                message_vision(msg, me, target);       
                                 
        }
        msg = HIW"$N将手中长剑一抖，隐隐约约之中似乎又有一剑从剑中飞出，赫然是最后一式"+HIR"「剑魂」"+HIW",似有在劫难逃之势！\n"NOR;
        k4=(int)me->query_skill("shushan-jianfa",1);      
        mypot=k4*k4*k4/5 + ap;        
        if ( random( mypot+dp ) > dp/2 ) 
        {              
                damage = k4+k4+me->query("force_factor");
                msg += HIB"结果$n"+HIB"大吃一惊，被"+HIR"剑魂"+HIB"刺中，魂魄好象也受到了伤害！\n"NOR;
                message_vision(msg, me, target);                                       
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage/2,me,"pfm");
                COMBAT_D->report_status(target);                                
        }
        else 
        {
                msg +="$n一声冷笑：原来如此，说罢冲天而起，不可思议的躲开了。\n"NOR;
                message_vision(msg, me, target);       
                                 
        }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-300);
        me->start_busy(2);
        return 1;
}


