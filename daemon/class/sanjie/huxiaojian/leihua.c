#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        
        object *inv, obj, obj1;
        int i, mypot,tapot;
        string str;

        object weapon;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「泪花一朵朵」？\n");

        if(!me->is_fighting())
                return notify_fail("「泪花一朵朵」只能在战斗中使用！\n");

    if (!PFM_D->valid_family(me, "三界山"))
     return notify_fail("你是哪里的门徒？\n"); 
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((string)me->query_skill_mapped("force")!="huntianforce")
        return notify_fail("“泪花一朵朵”必须要用混天宝鉴做底子。\n");
        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query_skill("huntianforce", 1) < 200)
                return notify_fail("你的内力有限，使用这一招会有困难！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        i=(int)me->query_skill("huxiaojian",1);

        if( i < 200)
                return notify_fail("你的剑法还不够，使用这一招会有困难！\n");

        if( time()-(int)me->query_temp("fantian_end") < 4 )
                return notify_fail("你哪来的那么多泪水，是不是眼睛进沙子了？\n");
message_vision(HIC"\n思忆过往云烟，种种思绪时时纠缠，$N心生愁思，凝聚心头，双眼微颤．．．．．．\n\n"NOR,me,target,"");
message_vision(HIR"\n　　　　　　　　　“泪花一朵朵”\n\n"NOR,me,target,"");
                
        mypot=(int)me->query_skill("huntianforce");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/3 || !living(target) ) 
{       
        
  message_vision(HIG"\n$N眼中含泪，欲落未落，$n悔恨之心涌上心头。\n\n"NOR,me, target,""); 
 message_vision(HIY"\n情思万万千，愁慕千千万，怎能抵我心头压抑多年的苦与哀愁。\n\n"NOR,me, target,"");  
         COMBAT_D->do_attack_damage(me, target);
   target->receive_wound("kee",random(me->query_skill("huntianforce")*2/5),me,"pfm");
         COMBAT_D->report_status(target);
                
         if (target->query("eff_kee")< -1000 || !living(target))  
 {str=target->name()+"被"+me->name()+"的「泪花一朵朵」震死，魂魄都无处寻觅。";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        if ( random(20)>2 )
{
 message_vision(HIG"\n\n$N双目已经模糊。愁，化作无奈，心中的往事伤痕化作点点泪花。\n"NOR,me,target,"");
 message_vision(HIY"\n\n哀思，笼罩在$n周围，$n慢慢感觉自己心中的空空荡荡。\n\n"NOR,me,target,"");
         COMBAT_D->do_attack_damage(me, target);
     target->receive_damage("kee",random(me->query_skill("parry")),me,"pfm");
         COMBAT_D->report_status(target);
   
              target->start_busy(1);
             }
          
        if ( random(20)>4 )
{
 message_vision(HIG"\n\n$N抬头凝望$n。无奈，无奈花落花尽去。泪水，泪水化作无奈泪花。\n"NOR,me,target, "");
message_vision(HIY"\n\n$n看见$N的泪水化作点点泪花洒落，悔恨之意泛起于心头。\n\n"NOR,me,target, "");
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("sen",random(me->query_skill("spells")*7/4));
         COMBAT_D->report_status(target);
   
             }
          
        if ( random(20)>10 )
{
message_vision(HIG"\n\n既然事已如此，何苦为之落泪，$N借洒落于空中的泪花双掌运力，猛击泪花朵朵。\n"NOR,me,target,"");
message_vision(HIY"\n\n$n见$N脸露微笑甚感诧异，忽见眼见处处都是$N的泪花飞舞，顿感大势不妙，但是已经晚了\n\n"NOR,me,target,"");
         COMBAT_D->do_attack_damage(me, target);
  target->receive_wound("kee",random(me->query_skill("huntianforce")*2),me,"pfm");
         COMBAT_D->report_status(target);
                me->start_busy(1);
              target->start_busy(1+random(2));
   
             }
          
}
     
    else  {message_vision(HIC"\n$N无情无义，早已堕落于情感一面，对$N动情无用，无用矣！\n"NOR, target,0,"");
                me->start_busy(random(2)+1);
               }
               
        me->add("force", -150);
        me->receive_damage("sen", 50);
        me->set_temp("fantian_end",time());
        return 1;
}
