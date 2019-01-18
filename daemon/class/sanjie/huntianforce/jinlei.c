#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, forcee;
        int kee_wound;

        where=environment(me);
        if( me == target )
                return notify_fail("找死呀，自杀更好！！\n");
        if( where->query("no_fight") )
                return notify_fail("安全区内不能引动九天灵气！\n");
        if( userp(target) ) 
                return notify_fail("不可以这样的哟！\n");
        if( !me->is_fighting() )
                return notify_fail("小金雷只能在战斗中使用。\n");
        
        if( (int)me->query("force") < 1000 )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("kee") < 200)
                return notify_fail("你的力气不够了。\n");
        if( (int)me->query("pfmjinlei") < 0 )
                return notify_fail("你的金雷用完了。\n");
        if( (int)me->query_skill("force", 1) < 150 )
                return notify_fail("你的内功修为还不够，使用这一招会有困难！\n");
                
                
        skill = me->query("force");
        forcee = target->query("force")/5-50;
        me->add("force", -400);
        me->receive_damage("kee", 150);

        me->start_busy(2);
        message_vision(HIR "\n$N右手向前一指，屏气凝神，引动出九天灵气！\n
        顿时指尖凝出一个金黄色的小球！\n
        $N大喝一声：去！小球急速向$n飞去！\n\n"NOR, me,target);
        if(random(20)>2)
        {
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        kee_wound = me->query("eff_kee")/(6+random(8));
        me->receive_damage("kee", 50);
        target->set("kee", -1); 
        target->add("eff_kee", -(kee_wound));
        target->add("force",-(forcee));
        me->add("force", -100);
        me->add("pfmjinlei",-1);
        message_vision(HIY"$n顿时被炸着。受伤严重，全身凝满金粉，昏倒在地！\n"NOR,me, target);
        target->start_busy(1);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
         }
         }
         else   message_vision(HIY"可是$p躲过了$P的金球，嘘叹了一声，幸哉！\n" NOR, me, target);
                       
        return 1;
}


