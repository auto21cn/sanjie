//created by mind 2001/2


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{       
        string str;
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「名可名 非常名」？\n");

        if(!me->is_fighting())
                return notify_fail("「名可名 非常名」只能在战斗中使用！\n");
        
   if (!PFM_D->valid_family(me, "三界山"))
                return notify_fail("你从哪里偷来的绝招「名可名 非常名」？\n");
        
        if( (int)me->query("bellicosity") > 1000 )
        return notify_fail("你的杀气太重，不符合呼啸皇剑要义。\n");      
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");
              if( time()-(int)me->query_temp("dunno_end") < 4 )   
              return notify_fail(CYN"「名可名 非常名」对真气损耗太大,无法连续使用！\n"NOR);   

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("zhaoyangbu", 1) < 100)
                return notify_fail("你的朝阳步法修为还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("huxiaojian", 1) < 100)
                return notify_fail("你的呼啸皇剑剑法修为还不够，使用这一招会有困难！\n");

   message_vision(HIC"$N呼啸皇剑剑法的要旨「名可名 非常名」，连续几剑，浑无招式痕迹可循向$n刺去！\n"NOR,me,target, "");
            target->start_busy(1);
        me->set("dunnoname", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 11);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 13);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("dunnoname");
//        me->start_busy(2);
     message_vision(HIC"$N酣畅淋漓地使了这招，剑意舒展.\n"NOR,me,target, "");
        if (target->query("eff_kee")<0 || !living(target))  
        {
//        str=target->name()+"被"+me->name()+"用的绝招「名可名 非常名」杀死了。\n听说"+target->name()+"到死都不知道死在什么招式之下！";
//        message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
        }
        
        me->add("kee", -50);
        me->add("force", -150);
       me->add("sen",-50);
            me->set_temp("dunno_end",time());   

        return 1;
}

