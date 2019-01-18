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
                return notify_fail("你要对谁施展这一招「心情」？\n");

        if(!me->is_fighting())
                return notify_fail("「心情」只能在战斗中使用！\n");

         if ((string)me->query("class")!="sanjie")
     return notify_fail("你是哪里的门徒？\n"); 
         if ((string)me->query("family/family_name")!="三界山")
     return notify_fail("你是哪里的门徒？\n"); 
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((string)me->query_skill_mapped("force")!="huntianforce")
        return notify_fail("“心情”必须要用混天宝鉴做底子。\n");
        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query_skill("huntianforce", 1) < 200)
                return notify_fail("你的内力有限，使用这一招会有困难！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        i=(int)me->query_skill("tianyaofa",1);

        if( i < 200)
                return notify_fail("你的棒法还不够，使用这一招会有困难！\n");

        if( time()-(int)me->query_temp("xinqing_end") < 4 )
                return notify_fail("你意乱，心不乱，无法用此招？\n");
        message_vision(HIC"\n$N心情无限惆怅，心中酝酿滋味，乏味，乏味。\n\n"NOR,me,target);
             
        mypot=(int)me->query_skill("tianyaofa");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/3 || !living(target) ) 
{       
        
         message_vision(HIG"\n$N心中茫然，乱七八早的招数随手就出。\n\n"NOR,me, target);  
         message_vision(HIY"\n$n眼前昏花，真无奈$N到底在干什么。\n\n"NOR,me, target);  
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("kee",random(me->query_skill("stick")*2/5),me,"pfm");
         COMBAT_D->report_status(target);
                
         if (target->query("eff_kee")< -100 || !living(target))  
 {str=target->name()+"被"+me->name()+"的「泪花一朵朵」震死，魂魄都无处寻觅。";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        if ( random(20)>3 )
{
  message_vision(HIG"\n\n$N心灵麻木，完全没了自我平日潇洒脱俗的举止。\n"NOR,me,target);
  message_vision(HIY"\n\n$n无奈的表情顿生，茫然的心情折腾的浑身不是滋味。\n\n"NOR,me,target);
         COMBAT_D->do_attack_damage(me, target);
         target->receive_damage("kee",random(me->query_skill("parry")*7/5),me,"pfm");
         COMBAT_D->report_status(target);
   
              target->start_busy(1);
             }
          
}
     
         else  {message_vision(HIC"\n$N镇定自若，毫不把这些零乱放在眼里！\n"NOR, target);
                me->start_busy(random(2)+1);
               }
               
        me->add("force", -150);
        me->receive_damage("sen", 50);
        me->set_temp("xinqing_end",time());
        return 1;
}
