//Created by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, mypot, tapot;
        object weapon;
        weapon = me->query_temp("weapon");
        
        damage = (int)me->query_skill("bingpo-blade", 1) + (int)me->query_skill("blade", 1);
        damage = damage/2 + random(damage/2);
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"你要对谁施展"HIR"“千里冰封漫天雪”"WHT"？\n"NOR);
        if( !me->is_fighting(target) )
                return notify_fail(HIR"“千里冰封漫天雪”"WHT"只能在战斗使用。\n"NOR);
        if (!PFM_D->valid_family(me, "大雪山"))
                return notify_fail(HIR"“千里冰封漫天雪”"WHT"是大雪山绝技！\n");                        
        if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail(WHT"只有用冰谷凝血功才能运用"HIR"“千里冰封漫天雪”"WHT"。\n"NOR);
        if (me->query_skill("bingpo-blade",1)<200)
                return notify_fail(WHT"你的冰魄寒刀不够纯熟，还得继续努力。\n"NOR);     
        if (me->query_skill("ningxie-force",1)<200)
                return notify_fail(WHT"你的冰谷凝血功不够纯熟，还得继续努力。\n"NOR);                    
        if((int)me->query("force") < 300 )
                return notify_fail(WHT"你的内力不足。\n"NOR);
        if( me->query("max_force") < 1000 )
                return notify_fail(WHT"你的内力修为甚浅，不足以用"HIR"「千里冰封漫天雪」"WHT"。\n"NOR);     
        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(WHT"你身体太虚弱了，无法施展"HIR"「千里冰封漫天雪」"WHT"！\n"NOR);
        if( time()-(int)me->query_temp("bxffs_end") < 3 ) 
                return notify_fail(WHT"烈日炎炎何来千里冰雪落尘埃！\n"NOR); 
            
        msg = MAG "\n\t☆★☆★"HIW"玉雪"HIG"为"HIB"骨"HIW"冰"HIG"为"HIR"魄，"HIY"幻梦"HIW"冰雪"HIM"落"HIC"晴空！"NOR""MAG"★☆★☆\n" NOR;                      
                     
        me->add("sen", -50);
        me->add("kee", -50);
        
        msg += WHT "\n\t～～～六月飞霜～～～\n" NOR;
        msg += WHT "\t\t\t千里冰雪谁人怨？\n" NOR;
        msg += HIC "\n炎炎烈日，晴空万里。$N哀嚎一声，顿时瑞雪纷飞，怨气冲天！\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
        {
                msg += HIY "$n不知躲闪，被怨气包围了！\n" NOR;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n运功相抗，将怨气阻止在身体外围。\n" NOR;
                message_combatd(msg, me, target, "");
        }               
        
        msg = MAG "\n\t～～～冰雪碎梦～～～\n" NOR;
        msg += MAG "\t\t\t万物成灰一场空？\n" NOR;
        
        mypot=(int)me->query_skill("bingpo-blade");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        
        msg += HIW "\n天空闪现霞光万道，隐隐约约$n看见天宫中仙子嬉戏，众仙聚宴。
$n不禁看的出神，猛然间一股寒气从后背袭来。\n" NOR;
        
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {
                msg += HIY "$n早已进入梦幻之中尚未清醒，被刺了一个透心凉。\n" NOR;
                COMBAT_D->do_attack_damage(me, target);
                target->receive_wound("kee", damage, me, "pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);                
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n不被幻象所迷惑，避开了这股寒气。\n" NOR;
                message_combatd(msg, me, target, "");
        }
                
        msg = HIR "\n\t～～～踏雪寻梅～～～\n" NOR;
        msg += HIR "\t\t\t曲尽知谁解"HIW"冰心？\n" NOR;        
        msg += HIM "\n冰雪将尽，寒梅盛开。点点梅花，阵阵飘香。万朵梅花齐飘落，如点点寒星袭向$n。\n" NOR;
        
        if (me->query_skill("force") > random(target->query_skill("force")))
        {
                msg += HIY "$n被梅花花瓣打的遍体鳞伤。\n" NOR;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n居然不可思议的躲过了万朵花瓣！\n"NOR;
                message_combatd(msg, me, target, "");
        }
                                
                        
        me->set_temp("bxffs_end",time());
        return 1;
}



