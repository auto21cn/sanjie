//qinghu-jian perform hebi 紫青合璧 風雷四擊
// /daemon/class/gumu/qinghu-jian/hebi
// writted by ivy 2002-1-18
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1,myskill2, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
        myskill1= (int)me->query_skill("qinghu-jian",1);
        myskill2= (int)me->query_skill("zizhi-blade",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="sword")
        return notify_fail("无刀无剑如何合璧？");
        if ( myskill1 < 210) return notify_fail("你的青狐剑法还不够火候！\n");
        if ( myskill2 < 210) return notify_fail("你的紫雉刀法还不够火候！\n");
        if (!PFM_D->valid_family(me, "轩辕古墓"))
                return notify_fail("你是哪儿偷学来的武功，也想用『紫青合璧』?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『紫青合璧』只能在战斗中使用。\n");
        if ((int)me->query("force")<300)
                return notify_fail("你的内力不够。\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIW"$N双手一扬，只见刀剑齐飞，紫青炸现，使出了轩辕古墓的绝学--『风雷四击』！\n\n" NOR,me,target);        
     message_vision(MAG"$N左手一挥，一道紫光浮现天际，快，夹杂着阵阵雷声！            "+BLINK""+HIW"       ※※"NOR""+HIW"风"+BLINK"※※\n"NOR,me);
     message_vision(MAG"这一招『紫雷天矶』挟着滚滚雷声源源不断的劈向对方！\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = MAG"$n只觉得一股劲气象闪电炸雷一般，穿体而过！\n"NOR;
        damage= (int)(((int)me->query("max_force")/2+myforce -  (int)target->query("max_force")/2 - tforce)/3);
        if(damage<1)damage = 1;
        target->receive_damage("kee", me->query("eff_kee")*damage/60,me,"pfm");
        target->receive_wound("kee", me->query("eff_sen")*damage/80,me,"pfm");
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        }
     else {
            msg = HIC"$n忙运功向抗，深厚的内力将$N的攻势都激散了。\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIG"$N右手一挥,一道青光快如风,急如闪般飞至,煞是好看！     "+BLINK""+HIW"               ※※"NOR""+HIW"雷"+BLINK"※※ \n" NOR,me,target);
     message_vision(HIG"这一招『青风破邪』像无尽狂风要把天下妖孽尽数扫净！\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIG"$n马上手忙脚乱，不知该如何去招架这股劲风！\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
     target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$n丝毫不显慌乱,绕过风头,瓦解了$N这激烈的攻势。\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIB"$N双手一分,紫青两道光芒圈成光环猛然间激射向对手！     "+BLINK""+HIW"               ※※"NOR""+HIW"四"+BLINK"※※ \n" NOR,me,target);
     message_vision(HIB"这一招『大道归源』气势磅礴,加之风吼雷鸣,镇人心扉！\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIB"$n见那光环扑面而来，不仅骇然，手足无措！\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
     target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$n却心静如水,见招拆招,瓦解了$N这气势磅礴的攻势。\n\n"NOR;
            message_vision(msg, me, target);
        }


          message_vision(HIW"$N双手一合，紫青之光合于一体，大喝一声向前推去！                  "+BLINK""+HIW"   ※※"NOR""+HIW"击"+BLINK"※※\n"NOR,me);
          message_vision(HIW"这一招『紫青合璧』把风雷四击的精髓发挥地淋漓尽致！\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIW"$n急忙跳起,那知这道灵光随心而欲猛然间向上一挑！\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIC"$n身形一低,待灵光低头的瞬间轻轻跃起，避过致命一击！\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(3+random(1));
        
     
        return 1;
}


