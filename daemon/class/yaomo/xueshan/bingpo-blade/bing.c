//write by swagger
//2001.5.10
//Changed by Wuyou@Sanjie

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="寒光斩";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｂｉｎｇ\n"
        +"条件：冰魄寒刀100级，冰谷凝血功100级，内力1200";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int damage, def, extra;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("寒光斩只能对战斗中的对手使用。\n");
        if (!PFM_D->valid_family(me, "大雪山"))
                return notify_fail("“寒光斩”只有雪山弟子才可以使用！\n");
        weapon = me->query_temp("weapon");
        if( (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你手上无刀，不能使用寒光斩！\n");
        if ((int)me->query_skill("bingpo-blade", 1) < 100 )
                return notify_fail("你冰魄寒刀不够娴熟，使不出寒光斩。\n");
        if ((int)me->query_skill("ningxie-force", 1) < 100 )
                return notify_fail("你的冰谷凝血功修为不够。\n");
        if ((int)me->query_skill("dengxian-dafa", 1) < 100 )
                return notify_fail("你的登仙大法修为不够。\n");                 
        if (me->query_temp("bing_busy")) 
                return notify_fail("你刚发过寒气,再用会有危险!\n");
        if( (int)me->query("force") <= 1200 )
                return notify_fail("你内力不够，使用寒光斩会有危险！\n");
                
        msg = HIC "\n$N念了几句咒语，右手一挥，周围顿时变的其冷无比！
$N运起凝血神功，一团刺骨的寒气向$n直逼而来！\n" NOR;
        
        
        if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
        {
                
                msg += HIW"\n$n被$N发出的这团寒气包了个正着！\n\n" NOR;
                
                target->start_busy(2+random(3)); 
                
                msg +=  HIC ">>$N手中"+ weapon->name() + HIC"寒光一闪，身形也随着腾空而起，
随即一式"HIW"「寒光斩」"HIC"幻出无数刀光向$n迎面劈来！\n\n"NOR;
                                
                if (me->query_skill("parry") > random(target->query_skill("parry")))
                {
                        msg += HIC"$n还没想出该怎样拆招，一道血光已经象闪电一般，穿体而过！\n"NOR;
                        damage = (int)me->query_skill("parry", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor_vs_force");
                        //damage -=damage*def/3000;
                        damage -=damage*def/6000;
                        damage = damage + me->query("force_factor");
                        target->receive_damage("kee", damage, me, "pfm");
                        target->receive_wound("kee", damage/2, me, "pfm");
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else 
                {
                        msg += HIC"$n忙一运功，往后一撤，无形中化解了这招的威力。\n"NOR;
                        message_combatd(msg, me, target, "");
                } 
                
                msg =   HIC">>$N手中"+ weapon->name() +""HIW"--寒光又闪，"HIC"$N也由静转动。
一动便急如风，脚踏奇门，刀走奇招，式式从$n意想不到的方位奇快劈出！\n" NOR;                
                       
                if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
                {
                        msg += HIC"$n一阵手忙脚乱，不知该如何去招架这静若水、快如电的刀法！\n"NOR;
                        damage = damage + random(200);
                        if(damage<1)damage = 1;
                        target->receive_damage("kee",damage*3/2,me,"pfm");
                        target->receive_wound("kee", damage, me,"pfm");
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else
                {
                        msg += HIC"$n却心静如水，见招拆招，瓦解了$N这无声的攻势。\n"NOR;
                        message_combatd(msg, me, target, "");
                        
                }

                me->add("force", -100);
                me->add("mana", -100);
        }
        else 
        {
                msg = WHT"\n$n早已经看出$N的企图，身形一闪，已避开了这团寒气。\n" NOR;
                message_combatd(msg, me ,target, "");
                me->start_busy(2);
                me->add("force", -100);
                me->add("kee", -50);
        }
        
        me->set_temp("bing_busy",1);
        
        call_out("remove_effect",2+random(2),me);
        return 1;
}

void remove_effect(object me, object target) 
{
        string msg;
        if (!me) return;
        me->delete_temp("bing_busy");
        msg = HIR"\n过了一会,寒气渐渐的散去了。\n" NOR;
        message_vision(msg, me ,target);
}



