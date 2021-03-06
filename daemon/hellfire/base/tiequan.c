#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>
string get_name(){return "铁拳术";}//法术名字
string get_help()                  //法术说明以后直接help,方便修改
{
        return "这个法术可以施展铁拳，每个角色攻击力不同,攻击是固定的。\n"
        +"此法术初期所用，需要一定的法力和魔法点１， 攻击效率如下\n"
        +"剑侠:80 魔法师:20 终结者:40 精灵族:50 暗黑地狱使者 60 野蛮人:90百分比。";
}

int do_cast(object me,object target)
{
        string helltype;
       
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        {
                tell_object(me,"你没在战斗中！\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"你的法力太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"你的魔法点太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="野蛮人";
        if(!userp(me)) return 1;
        me->add("mana",-2* magic_power[helltype]);  
        me->add("magic_pointed",-magic_power[helltype]/10);
        message_vision(HIR "$N身形立定手抱双泉，$n只觉得一个巨大的铁拳头打来！\n" NOR,me,target);
        if(random(magic_power[helltype]+50)>50)
        {
                target->receive_damage("kee", magic_power[helltype]*3,me,"magic_book");
                                                       //增加后面"magic_book"参数，如果是 pfm文件话是"pfm",法术的是"cast"，这个参数是区分发出的伤害的来源
                target->receive_wound("kee", (magic_power[helltype])/2,me,"magic_book");         
                                                       //增加后面"magic_book"参数，如果是 pfm文件话是"pfm",法术的是"cast"，这个参数是区分发出的伤害的来源
                COMBAT_D->report_status(target, 0);
                me->start_busy(random(2)+1);          
        }
        else
        {
                message_vision(HIR "$N的巨大铁拳头没打中$n！\n" NOR,me,target);
                
        } 
        
        me->strat_busy(random(2)+1);
        target->kill_ob(me);
        return 1;
}

