// bingfeng.c 寒冰咒

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="寒冰咒";
        return str;
}

string get_help(string str)                
{
        str="指令：ｃａｓｔ　ｂｉｎｇｆｅｎｇ\n"
        +"条件：登仙大法100级"
        +"将对方用寒冰冻住不能动弹！";
        return str;
}

void free(object target);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, howlong;

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("dengxian-dafa", 1) < 100 )
                return notify_fail("你还没学会寒冰咒。。。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想对谁施咒？\n");

        if(target->query_temp("no_move"))
                return notify_fail(target->query("name")+"已经冰封了。\n");

        if((int)me->query("mana") < 500 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 100)
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -300); 
        me->receive_damage("sen", 40);

        msg = HIC "$N口中念了句咒文，朝$n一挥，顿时冰天雪地，无数冰块封住了$n。\n" NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp + dp) < dp ) success = 0;
//here we compared max_mana.   

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp + dp) < dp ) success = 0;
//here we compare current mana. this is important. you need recover to try again.

        howlong = 0;        
        if(success == 1 )
        {
                msg +=  HIR "结果$n手足冰封了，动弹不得！\n" NOR;
                target->set_temp("no_move", 1);
        
                howlong = 15 + random((me->query_skill("spells") -100));
                if(howlong>60) howlong=60;
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
        }           
        else 
        {
                msg +=  HIR "结果$n避开无数冰块，嘿嘿狂笑不已。\n" NOR; 
        } 

        message_vision(msg, me, target);

//he'll try kill you...
        if( living(target) ) me->kill_ob(target);

        if (success == 0) 
        {
                //me->start_busy(1);
                return 1+random(2);
        }

//      me->start_busy(5);        
        if( howlong>0 ) call_out("free", howlong, target);
        
        return 3+random(5);
}

void free(object target)
{
        if(target) target->delete_temp("no_move");      
        return;
}


