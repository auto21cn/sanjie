// maren.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
//        set("channel_id", "频道精灵");
        if( duration < 1 ) {
        write(HIR"观察期已过，所有频道开启,希望你能改过自新。\n"NOR);
                    me->delete("channel/chblk_on");
                       write(HIW"【三界神话】频道精灵： "HIR+me->query("name")+"("+me->query("id")+")"+HIW" 的观察期已满，恢复使用频道的权利。\n"NOR,users());
                    // CHANNEL_D->do_channel( me, "sys",HIY+me->query("name")+"("+me->query("id")+")"+HIR" 已被开启所有频道。\n"NOR);
        return 0;
        }
        me->apply_condition("maren", duration - 1);
        
        return 1;
}

string query_type(object me)
{
        return "sleep";
}


