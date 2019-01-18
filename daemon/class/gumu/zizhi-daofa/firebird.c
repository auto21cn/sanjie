#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void fb_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「紫雉」？\n");
                if(me->query("family/family_name") != "轩辕古墓")
                return notify_fail("非古墓弟子不能使用「紫雉」！\n");
        if(!me->is_fighting())
                return notify_fail("「紫雉」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("zizhi-blade", 1) < 100)
                return notify_fail("你的紫雉刀法不够熟练，使用这一招会有困难！\n");
         if(me->query_temp("no_fb"))
                        return notify_fail("此技过于费力，少用为好！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N刀过头顶，积聚全身力量，一刀劈出\n\n"NOR,me,target);
message_vision(MAG"\n刀锋带着一道紫色火焰划过,犹如一只翱翔天际的火鸟\n"NOR,me,target);
message_vision(MAG"\n火鸟冲天而起，直扑过来……………………\n"NOR,me,target);
              damage=(int)me->query_skill("blade")+random((int)me->query_skill("blade"));
              if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIW"\n$n$n周身被紫色火焰包围着......\n"NOR,me,target);
             target->receive_damage("sen",damage,me,"cast");
              target->receive_wound("sen",damage/2,me,"cast");
             COMBAT_D->report_status(target);
}
else {
             message_vision(HIG"\n$n急忙后跃，才将将躲开火焰的攻击！\n"NOR,me,target);
             }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_fb",1);
                call_out("fb_ok",1+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}

void fb_ok(object me)
{
if (!me) return;
      me->delete_temp("no_fb");
}

