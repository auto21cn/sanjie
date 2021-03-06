//BY Cigar 2002.01 huabian.c <花变>

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void huabian_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("无事花变小心天变人怨？\n");
        if (!PFM_D->valid_family(me, "月宫"))
                return notify_fail("[花变]是月宫不传之密！\n");
        if(!me->is_fighting())
                return notify_fail("「花变」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 650 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 650 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 250 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("jueqingbian", 1) < 200)
                return notify_fail("你的绝情鞭法不够熟练，使用这一招会有困难！\n");
        if(me->query_temp("no_huabian"))
                return notify_fail("无事花变小心天变！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N看着遍地含苞待放的花朵，情到一处油然而生，顺口吟道："+HIR""BLINK"≈≈花变≈≈"NOR""+HIW"吾心不变......\n"NOR,me,target);
message_vision(HIG"\n            “人间花开，春去天涯，红药万株，天然浩态狂香”。\n"NOR,me,target);
message_vision(HIG"\n            “尊贵御衣，独占花王，困倚凝香，用花千万余枝”。\n"NOR,me,target);
message_vision(HIG"\n            “人诧奇芳，结蕊当屏，怜葩就幄，红掩绿绕华堂”。\n"NOR,me,target);
message_vision(HIG"\n            “秉兰观雨，花面交相，幽意难忘，罢酒风亭梦魂”。\n"NOR,me,target);
message_vision(HIC"\n“天香染露，最忆当年，无限春风恨，夜深花睡冷香，多情芳心轻吐，问："+HIR"‘世间情为何物’"+HIC"”\n"NOR,me,target);
        
        damage=(int)me->query_skill("parry")+random((int)me->query_skill("whip"));
        if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$n眼前遍地花草争奇斗艳，被这如此出奇美景早已迷的心乱如麻，顿感心力交瘁。\n"NOR,me,target);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage/2,me,"pfm");
                target->start_busy(2+random(2));
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n心平气和，盘膝而座，怀中掏出玉酿美酒，合着此情此景独自享用起来。\n"NOR,me,target);
        }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_huabian",1);
        call_out("huabian_ok",4,me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}

void huabian_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_huabian");
}

