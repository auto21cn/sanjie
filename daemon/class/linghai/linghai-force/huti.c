//jiz
//huti.c


#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能用凌海心法保护自己。\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的气血不足。\n");
        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);

        message_vision(
                HIY"\n\n$N双目紧闭，十指相对。瞬间只觉体内真气翻滚，力量又增强了许多！\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, CYN"你的凌海心法运行一周天完毕，身体渐渐又恢复成以前的样子。\n"NOR);
        return;
}

