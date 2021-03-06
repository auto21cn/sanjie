//天魔降伏
//modify by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object *inv, obj;
        object weapon;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天魔降伏」？\n");

        if(!me->is_fighting())
                return notify_fail("「天魔降伏」只能在战斗中使用！\n");

        if (!PFM_D->valid_family(me, "南海普陀山"))
                return notify_fail("你还没有四大皆空、超脱世俗怎能天魔降伏？\n");

        if((int)me->query("max_force") < 2000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("你的轮回杖级别还不够，使用这一招会有困难！\n");
                
        if( time()-(int)me->query_temp("xiangfu_end") < 3 )  
                return notify_fail("你的内息尚未平复，不能再次使用天魔降伏。\n");                

        message_vision(HIY"$N口中念动"HIW"《金刚般若波罗蜜经》"HIY"：\n"NOR,me,target);
        message_vision(HIY"\n\t生死炽燃，苦恼无量，发大乘心，普济一切。\n"NOR,me,target);
        message_vision(HIY"\t愿代众生，受无量苦，令诸众生，毕竟大乐。\n"NOR,me,target);
        message_vision(HIY"\t凡所有相，皆是虚妄，诸相非相，即见如来。\n"NOR,me,target);
        message_vision(HIY"\t降伏其心，愿乐欲闻，即见如来，未为胜也。\n"NOR,me,target);
        message_vision(HIY"\t知我说法，如筏喻者，法尚应舍，何况非法。\n"NOR,me,target);
        message_vision(HIY"\t放下屠刀，立地成佛，佛说非身，是名大身!\n"NOR,me,target);
//      message_vision(HIR"\n$N手中的"+weapon->query("name")+HIR"发出阵阵霞光，只见几道金光射向$n……\n"NOR,me,target);
        message_vision(HIY"\n        〓〓"HIR"魑魅魍魉"HIW">>>>><<<<<"HIR"天魔降伏"HIY"〓〓\n"NOR,me,target);
        
        mystr=(int)me->query("str");
        tastr=(int)target->query("str");
        myexp=(int)me->query("combat_exp")/20;
        taexp=(int)target->query("combat_exp")/30;
        mylvl=(int)me->query_skill("staff")+(int)me->query_skill("lunhui-zhang");
        talvl=(int)target->query_skill("parry")+(int)target->query_skill("dodge");
        mypot=mystr*mylvl+myexp;
        tapot=tastr*talvl+taexp;
        y=random(3);
        if( mypot >tapot/2+random(tapot)/2) 
        {
                message_vision(HIY"\n$N两眼痴痴看着远方，意识好象受到了佛的召唤,似乎杀意全无，楞然矗立顾不及躲闪...\n\n"NOR, target);
                
                target->receive_damage("kee", 200 + random((int)me->query("max_force")/4+(int)me->query("max_force")/10+(int)me->query("force_factor")),me,"pfm");
                target->receive_damage("sen", 200 + random((int)me->query("max_mana")/4+(int)me->query("mana_factor")),me,"pfm");    
                target->receive_wound("kee", 100 + random((int)me->query("max_force")/4+(int)me->query("max_force")/10+(int)me->query("force_factor")),me,"pfm");
                target->receive_wound("sen", 100 + random((int)me->query("max_mana")/4+(int)me->query("mana_factor")),me,"pfm");    

                COMBAT_D->report_status(target);
                COMBAT_D->report_sen_status(target);         
                
        }
        else 
        {
                message_vision(HIG"谁知$N"HIG"竟然全无感觉，脸上杀气却越来越浓！\n"NOR, target);
        }
        
        me->add("force", -200);
        me->receive_damage("sen", 60);
        me->set_temp("xiangfu_end",time());

        return 1;
}

