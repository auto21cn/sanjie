//绕指剑气
//by junhyun@SK
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
        myskill1= (int)me->query_skill("rouqingjian",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="sword")
        return notify_fail("无剑如何运剑？");
        if ( myskill1 < 280) return notify_fail("你的绕指柔情剑还不够火候！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『绕指剑气』只能在战斗中使用。\n");
        if ((int)me->query("force")<300)
                return notify_fail("你的内力不够。\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-200);
        me->receive_damage("sen", 20);
     message_vision(HIW"$N攻势渐缓，运剑成圆，一股股剑气在三尺青锋吞吐！\n\n" NOR,me,target);        
     message_vision(HIG"柔而不断的『绕指剑气』围绕在$N身边！\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIR"$n躲闪不及，一股柔和的剑气透体而过！\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/400, me);
target->receive_wound("kee", me->query("eff_sen")*damage/400, me);
target->start_busy(4);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIW"$n自知不敌，身形一低,贴着剑锋平平的飞了出去！\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(2);
        
     
        return 1;
}


