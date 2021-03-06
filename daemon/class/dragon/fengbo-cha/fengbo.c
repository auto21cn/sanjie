#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mypot,tapot,time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「无尽风波」只有在战斗中才能使用。\n");

        if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
                return notify_fail("你的修为不够深，还使不出这一招！\n");
                
        if(me->query_temp("fengbo_busy"))
                return notify_fail("老用哪那么多风波?\n");
                
        if (!PFM_D->valid_family(me, "东海龙宫"))
                return notify_fail("你非龙族，不能用此招！\n");
                
        if( target->is_busy() )
                return notify_fail(target->name()+"已经够忙了，你使的再漂亮也不会注意到。\n");

        message_vision(HIC"$N挥展开来，左一叉，右一叉，幻出无数大小光环向$n绕去。
虽看起来柔弱无力，却宛若秋波般连绵不绝，实是暗藏杀机！\n\n"NOR,me, target);

        me->add("sen", -60);

        mypot=(int)me->query_skill("fork");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        time=(int)me->query_skill("fengbo-cha", 1)/10 - (int)target->query_skill("parry")/20;
    
        if ( time > 15 ) time = 15;
        if ( time < 6  ) time = 6;

//        if ( (mypot+tapot)/4+random( mypot + tapot ) > tapot ) {
//        if ( (mypot+tapot)/2+random( mypot + tapot ) > tapot ) {
        if ( (mypot+tapot)/2+random( (mypot+tapot)*3/4 ) > tapot ) 
        {
                message_vision(HIR"$N果然被这光环套住，当时目瞪口呆，不知所措！\n"NOR,target);
                target->start_busy(time);
                me->set_temp("no_pfm",time() + 2);
        }
        else 
        {
                message_vision(HIR"不料却被$N看破，攻其不备，$n反被打了个措手不及！\n"NOR,target,me);
//                me->start_busy(3);
                me->start_busy(1+random(2));
        }

        
                if( living(target) ) 
                target->kill_ob(me);
               
       
        me->set_temp("fengbo_busy",1);
        call_out("can_fengbo",3+random(2),me);
        return 1;
}
    
void can_fengbo(object me)
{
        if(!me) return;
        me->delete_temp("fengbo_busy");
}

