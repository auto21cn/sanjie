
#include <ansi.h>
#include <condition.h>
#include "/daemon/skill/eff_msg.h";
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        int damage, p;
        string msg;
      
        damage = me->query_condition("qiankunyibang")/5 +2;
        damage *= me->query_con();
      
        tell_object(me, "突然你感觉胸口疼痛异常，浑身无力，骨头像散架似的，鲜血从伤口口中涌了出来！\n");
        tell_room(environment(me), HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
        me->receive_damage("kee", damage/2);
        me->receive_wound("kee", damage/2);
        me->start_busy(random(2));
        p = (int)me->query("kee")*100/(int)me->query("max_kee");
        msg = "( $N"+eff_status_msg(p)+" )\n";
        if(living(me)) 
                message_vision(msg, me);
//      me->set_temp("last_damage_from", "乾坤一棒劲力发作");
        me->set_temp("death_msg","乾坤一棒内伤发作死了。\n");
        me->apply_condition("qiankunyibang", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}


