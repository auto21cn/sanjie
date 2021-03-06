// chan.c 缠剑诀 by stey

#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "zhaoyang jian")
           return notify_fail("你没用朝阳剑，不能使用绝招！\n");

        if( me->query("con") < 20 || me->query("str") < 28 )
            return notify_fail("你的先天膂力身法孱弱, 不能使用「缠剑诀」！\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("huxiaojian",1);

        if( !(me->is_fighting() ))
            return notify_fail("「缠剑诀」只能对战斗中的对手使用。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("对方没有使用兵器，你用不了「缠剑诀」。\n");

        if( skill < 150)
            return notify_fail("你的虎啸皇剑等级不够, 不能使用「缠剑诀」！\n");

//    加上门派判断by seng@2005-1-20
    if( me->query("family/family_name")!="三界山") 
       return notify_fail("你不是三界山的, 不能使用「缠剑诀」！\n");


        if( me->query("force") < 300 )
            return notify_fail("你的内力不够，无法运用「缠剑诀」！\n");

        msg = HIC "$N手中"YEL"朝阳剑"HIC"画出一道金光，斜刺一拉，「缠剑诀」！
"YEL"朝阳剑"HIC"剑尖正好缠在$n的"+weapon2->name()+"上。\n";
    message_combatd(msg, me, target, "");

        damage = 100 + random(skill);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
            if(userp(me))
                 me->add("force",-50);
            msg = "$n顿时觉得眼前金光一闪，手腕一振，手中";
            msg += weapon2->name();
            msg += "脱手飞出！\n" NOR;
            me->start_busy(random(2));
            target->receive_damege("kee", damage,me,"pfm");
            target->start_busy(2);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("force",-50);
            msg = "$n急运内力，将手中" + weapon2->name()+
"斜斜顺势一送一搭，抽了回来。\n"NOR;
            me->start_busy(3);
        }
    message_combatd(msg, me, target, "");

        return 1;
}
