//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("qixiu-jian",1);
        if ( extra < 80) return notify_fail("你的[七修剑]还不够纯熟！\n");
        extra = me->query_skill("huntian-qigong",1);
        if ( extra < 80) return notify_fail("你的[混天气功]还不够纯熟，无法发挥七修剑的威力！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［夺命七剑］只能对战斗中的对手使用。\n");

        if (!PFM_D->valid_family(me, "陷空山无底洞"))
                return notify_fail("你不能用别派的特殊攻击\n");

        if( time()-(int)me->query_temp("qijian_end") < 4 )    
                return notify_fail(CYN"[夺命七剑]对真气损耗太大,无法连续使用！\n"NOR);  
                
        if(me->query_temp("no_kuang")) 
                return notify_fail("[狂杀斩]和[夺命七剑]不能连续使用！\n"); 
  
                
        weapon = me->query_temp("weapon");
        msg = YEL  "$N狂性大发，手中的"+ weapon->name()+  "狂风暴雨般地向$n袭来！" NOR;
                          target->stary_busy(1);
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = random(3)+3;
        for(i=1;i<=lmt;i++)
        {
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->set_temp("qijian_end",time());    
        return 1;
}

