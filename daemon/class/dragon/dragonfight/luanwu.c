#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage_bonus,target_bonus,damage, wound;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不在战斗中，怎么使用"HIY"乱舞"NOR"？\n");

        if (!PFM_D->valid_family(me, "东海龙宫"))
                return notify_fail("你非我龙王弟子，怎能使用龙宫绝招?\n");

        if((int)me->query_skill("dragonfight",1)<400
        ||(int)me->query_skill("dragonforce",1)<400) 
                return notify_fail("你的修为不够深，还不能领悟"HIY"乱舞"NOR"的精髓。\n");

        if((int)me->query("max_force") < 3000 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if(time()-me->query_temp("lxtx_end")<4)
               return notify_fail(HIY"乱舞"NOR"不能用得这么频繁！\n"); 
               
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"「吟花一笑」"NOR"与"HIY"乱舞"NOR"无法连续使用！\n"NOR);    
                
        if( time()-(int)me->query_temp("jiuxian_end") < 3 )  
                return notify_fail(WHT"「云龙九现」"NOR"与"HIY"乱舞"NOR"无法连续使用！\n"NOR);                                           

        me->set_temp("lxtx_end",time());
        me->add("force",-400);
        
        // dodge
        msg = HIW "$N运转龙神心法，身形化作一团白雾，似乎一条蛟龙腾空而起。\n";
        msg+= HIW "$N你双目圆睁,四肢狂动,使出了"HIR"乱舞"NOR""HIW"绝技。\n"HIY"【飞龙在天】 $N带起的劲风涌向$n全身！\n";
        if(!target->is_busy())
                target->start_busy(3);
        damage_bonus=(int)me->query_skill("dodge", 1);
        target_bonus=(int)target->query_skill("dodge", 1);
        if((damage_bonus)>random(target_bonus)) 
        {
                damage=damage_bonus/2+random(damage_bonus/2);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor")/2;
                msg +=HIB "$n躲闪不及，被劲风带倒在地。 \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "内伤");
        }
        else msg+=GRN"$n见势不妙，就地一滚躲开了。\n" NOR;
        
        // combat_exp
        msg+= CYN "$N巧运掌法，左手虚探，右手早就抓向$n的肋部。\n";
        msg+= CYN"【潜龙勿用】 $N的手掌已经无声无息贴近$n！\n";
        damage_bonus=(int)me->query("combat_exp");
        target_bonus=(int)target->query("combat_exp");
        if((damage_bonus)>random(target_bonus)) 
        {
                damage_bonus=(damage_bonus/40000+random(300))/8;
                damage=damage_bonus+random(damage_bonus);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor");
                msg +=HIB  "$n的肋部已被$N撕出条血痕。 \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "内伤");
        }
        else msg+=GRN"$n顺势左转，神奇般地躲开攻击。\n" NOR;   
        
        // daoxing
        msg+= YEL "$N仗着深厚的道行，左手强行带起掌风砸向$n。\n";
        msg+= YEL"【龙战于野】$n眼看躲闪不及！\n";
        damage_bonus=(int)me->query("daoxing");
        target_bonus=(int)target->query("daoxing");
        if((damage_bonus)>random(target_bonus)) 
        {
                damage_bonus=(damage_bonus/40000+random(300))/8;
                damage=damage_bonus+random(damage_bonus);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor");
                msg +=GRN  "$n被$N一掌震飞一丈多远。 \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "内伤");
        }
        else msg+=GRN"$n缩腹挺胸，暴退而出，躲过了攻击。\n" NOR;   
        
        // unarmed
        msg+= HIR "$N总结多年练习心得，虚探一下，抓住$n的兵刃。\n";
        msg+= HIR"【亢龙有悔】 $N和$n近身肉搏！\n";
        damage_bonus=(int)me->query_skill("unarmed", 1);
        target_bonus=(int)target->query_skill("unarmed", 1);
        if((damage_bonus)>random(target_bonus)) 
        {
                damage=damage_bonus/2+random(damage_bonus/2);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor")/2;
                msg +=HIB  "$n空手功夫不行，显然吃了大亏。 \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "内伤");
        }
        else msg+=GRN"$n的空手功夫竟然也不赖，躲过了$N的招式。\n" NOR;   
        
        // 运气
        if(!random(5))
        {
                msg+= CYN "$N本已力尽，谁知运气竟然不错，又出一招。\n";
                msg+= CYN"【神龙摆尾】 $N趁$n分神之际逼向$n！\n";
                damage_bonus=(int)me->query_kar();
                target_bonus=(int)target->query_kar();
                if((damage_bonus)>random(target_bonus)) 
                {
                        damage_bonus*=6;
                        damage=150+(damage_bonus+random(damage_bonus));
                        if(wizardp(me)) tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                        wound=damage-(int)target->query_temp("apply/armor");
                        msg +=HIB  "$n被脚下石头一绊，而被$N击中一掌。 \n";
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound<=0) wound=random(100);
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=COMBAT_D->damage_msg(damage, "内伤");
                }
                else msg+=GRN"$n迎风使舵，晃过了$N的攻击。\n" NOR;   
        }
        message_vision(msg, me, target);
        return 1;
 }


