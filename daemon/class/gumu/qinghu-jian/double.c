// double.c
// by junhyun@SK
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, string arg)
{
        object weapon, weapon1, target;
        int skill, skill1;
// string msg;

    if(!arg) return notify_fail("你想和谁一起双剑合璧？\n");

    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("这里没有这个人。\n");

    if (me->query("gender") == "无性")
            return notify_fail("你不用不了合壁。\n");

    if (target->query("gender") == "无性")
    return notify_fail("对方不能和你合壁。\n");

    if (me->query("gender") == target->query("gender"))
    return notify_fail("合壁需要心意相通，对方无法领会你的心意，无法合壁。\n");

    if( !target->is_fighting() || !target->is_character() || !me->is_fighting() )
                return notify_fail("双剑合璧只能在战斗中使用。\n");

    if(!living(target))
                return notify_fail(target->name()+"已经无法战斗了。\n"); 

    if(target==me) return notify_fail("想和自己合璧？\n"); 
    if(me->is_fighting(target))
                return notify_fail("你正在和"+target->name()+"打架呢。\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "qinghu-jian"
      || me->query_skill_mapped("parry") != "qinghu-jian")
        return notify_fail("你现在无法使用「双剑合璧」。\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "qinghu-jian"
      || target->query_skill_mapped("parry") != "qinghu-jian")
        return notify_fail(target->name()+"现在无法使用「双剑合璧」。\n");


    skill = me->query_skill("qinghu-jian", 1);
    skill1 = target->query_skill("qinghu-jian", 1);
    
    if(skill < 120 )
        return notify_fail("你的青狐剑法等级不够，不能使用「双剑合璧」。\n");
    
    if( skill1 < 120 )
        return notify_fail( target->name()+"的青狐剑法不够纯熟，无法和你配合使用「双剑合璧」。\n");

    if((int)me->query_skill("jiuyin-force", 1) < 120 )
        return notify_fail("你的九阴真经等级不够，不能使用「双剑合璧」。\n");       

    if((int)target->query_skill("jiuyin-force", 1) < 120 )
        return notify_fail(target->name()+"的九阴真经不够纯熟，无法和你配合使用「双剑合璧」。\n");       
    
    if (me->query_skill_mapped("force") != "jiuyin-force")
                return notify_fail("你所使用的内功不对。\n");

    if((int)me->query("force") < 500 )
        return notify_fail("你现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("force") < 500 )
        return notify_fail( target->name()+"现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)me->query("max_force") < 1000 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("max_force") < 1000 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if(me->query_temp("gumu_double")) 
        return notify_fail("你已经在使用「双剑合璧」了。\n");

    if(target->query_temp("gumu_double")) 
        return notify_fail(target->name()+"已经在使用「双剑合璧」了。\n");
    
    if(me->query_temp("gmdouble_target")){
          if(me->query_temp("gmdouble_target")==target)
                return notify_fail("你已经做好和"+target->name()+"双剑合璧的准备了。\n");
          else               
               tell_object(me->query_temp("gmdouble_target"), YEL+me->name()+"决定不和你进行双剑合璧了。\n"NOR); 
               me->delete_temp("gmdouble_target");
               
          }
    if(target->query_temp("gmdouble_target") ==me){
        message_vision(HIW"
$N忽然清吟一声，一式「空谷传声」，越上半空，手腕轻抖，"+weapon->name()+"在空中划出一轮弯月，\n"NOR,me,target);
        message_vision(HIW"
$n会意的用了一招「空穴来风」，飘然至$N身下，手中"+weapon->name()+"由下至上架在$N的"+weapon1->name()+"上！

霎时间剑光绵绵，青狐剑法变的更为精妙了！\n"NOR,me,target);
    
        me->set_temp("gmdouble_target", target);
        me->set_temp("gumu_double", 1); 
        target->set_temp("gumu_double", 1); 
        me->add("force", -300);
        target->add("force", -300);
        me->add("sen", -50);
        target->add("sen", -50);
        call_out("check_fight", 1, me, skill, (skill+skill1)/2);
        call_out("check_fight", 1, target, skill1, (skill+skill1)/2);
                return 1;
        return 1;
        }
    message_vision(YEL"$N将手中"+weapon->name()+"一横，暗示$n和$P一起运用双剑合璧。\n"NOR,me,target);
    tell_object(target, YEL"你如果愿意和"+me->name()+"进行双剑合壁，请也对"+me->name()+"下一次 ( perform double player<name> ) 的命令。\n"NOR);     
    me->set_temp("gmdouble_target", target);
    return 1;
}
void remove_effect(object me, int skill)
{
                if(me->query_temp("gumu_double")){
                me->delete_temp("gumu_double");
                me->delete_temp("gmdouble_target");
                message_vision(HIR"$N双剑合璧完结，攻守也恢复正常了。\n"NOR, me);
        }
}
void check_fight(object me, int skill, int count)
{
        object weapon;
        object target;

        if (!me) return;
        if (count < 1 || !me->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        target = me->query_temp("gmdouble_target");
        if (!target || !target->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        if (target->query_temp("gmdouble_target") != me) {
                remove_effect(me, skill);
                return;
        }
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword") {
                remove_effect(me, skill);
                return;
        }
        if (me->query_skill_mapped("sword") != "qinghu-jian"
                || me->query_skill_mapped("parry") != "qinghu-jian") {
                remove_effect(me, skill);
                return;
        }
        if(environment(me) != environment(target)) {
                remove_effect(me, skill);
                return;
        }
    call_out("check_fight", 1, me, skill, count-1);
}
 

