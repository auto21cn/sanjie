#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("huxiaojian", 1);  
        weapon = me->query_temp("weapon");
     
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招『道可道 非常道』？\n");

        if(!me->is_fighting())
                return notify_fail("『道可道 非常道』只能在战斗中使用！\n");
                
    if (!PFM_D->valid_family(me, "三界山"))
                return notify_fail("你是哪儿偷学来的武功，也想用『道可道 非常道』?\n");
                     
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("没剑怎么发挥『道可道 非常道』的威力。\n");

        if( time()-(int)me->query_temp("dunno_end") < 4 )
                return notify_fail("绝招用多就不灵了！\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("你的精神不足，没法子施展『道可道 非常道』！\n");

        if(myskill < 60)
                return notify_fail("你的虎啸剑法级别还不够。\n");
        else 
            if(myskill <60){
                times = 1;        
                number = "一";}
            else
                if (myskill <80){
                    times = 2;
                    number = "二";}
                else
                    if(myskill <120 ){
                           times = 3;
                           number = "三";}
                else
                    if(myskill <160 ){
                           times = 4;
                           number = "四";}
                else
                    if(myskill <200 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        damage = random((int)me->query_skill("sword")/3);

       message_vision(HIM"\n$N突然剑招一变，手中的"+ weapon->query("name")+ HIB"无影无踪，浑身喷薄出凌厉的剑气。闪电般向$n攻出了"+number+"剑！\n"NOR,me,target, "");

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20,target);
        me->add("force", -(times*30+10));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target) && times>5)
        {

        target->receive_damege("sen", damage,me,"pfm");
        target->receive_wound("sen", random(damage),me,"pfm");
        target->receive_damege("kee", damage+1,me,"pfm");
        target->receive_wound("kee", random(damage),me,"pfm");
message_vision(HIR"\n结果$n被$N的『道可道 非常道』剑气穿心，眼前一黑，身子向后飞出丈许！！\n\n $n身上剑痕鲜血涌出......\n" NOR,me,target,"");
                COMBAT_D->report_status(target, 0);
        }
        me->start_busy(1+random(2));
/*
if (target->query("eff_kee")<0 || !living(target))
{msg=target->name()+"被"+me->name()+"用"HIC"三界山"HIM"绝技"+HIW"[『道可道 非常道』"HIM+"杀死了！";
message("channel:rumor",HIM"【空穴来风】某人："+msg+"\n"NOR,users());
}
*/
        me->set_temp("sky_end",time());
        return 1;
}

