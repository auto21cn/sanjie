#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,myexp,yourexp,busy,extra;

        object weapon=me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「心禅」？\n");

        if(!me->is_fighting())
                return notify_fail("「心禅」只能在战斗中使用！\n");
        
        if (!PFM_D->valid_family(me, "南海普陀山"))
                return notify_fail("不是佛门弟子不能用「心禅」！\n");

        if( (int)me->query("bellicosity") > 500 )
                return notify_fail("你的杀气太重，无法施展佛门绝技。\n");
                
        if (me->query_skill_mapped("force")!="lotusforce")
                return notify_fail("「心禅」必须以莲台心法为底子！\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("buddhism", 1) < 120)
                return notify_fail("你的大乘佛法修为还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("lunhui-zhang", 1) < 120)
                return notify_fail("你的轮回杖修为还不够，使用这一招会有困难！\n");
     
        if( time()-(int)me->query_temp("cibei_end") < 4 )  
                return notify_fail("你的心禅说多了别人就烦了。\n");

        myexp = (int) me->query("combat_exp"); 
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/100; 
        extra = me->query_skill("lunhui-zhang",1);  

        message_vision(HIY"$N心如明镜，四大皆空，将大乘佛法发挥到极至，顿时佛光普照，$N将自己悟到的"HIR"“心禅”"HIY"喷薄而出！\n"NOR,me,target);
    
        if(random(myexp)>random(yourexp/6)) 
        {
        
                me->add_temp("apply/attack",extra);
                me->add_temp("apply/damage",extra);  
                if(!target->is_busy()) 
                        target->start_busy(busy);
              target->receive_wound("kee",extra + random(extra));

                message_vision(HIG"\n▆ ▆ ▆ 身是菩提树，心如明镜台。时时勤拂拭，勿使惹尘埃。▆ ▆ ▆ \n"NOR,me,target);
       
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIW"\n▆ ▆ ▆ 菩提本无树，明镜亦非台。本来无一物，何处惹尘埃。▆ ▆ ▆ \n"NOR,me,target);
   
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIR"\n▆ ▆ ▆ 开出无形面，示作十界身，悟在迷未了，入魔亦无碍！▆ ▆ ▆ \n"NOR,me,target);
     
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
                message_vision(HIC"\n▆ ▆ ▆ 要尽心花开，方明无情示，本来不迷悟，识智何出入！▆ ▆ ▆ \n"NOR,me,target);
       
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           
                me->add_temp("apply/attack",-extra);  
                me->add_temp("apply/damage",-extra);  
            
                message_vision(HIY"$N高吭“阿弥陀佛，佛祖慈悲！”随着佛光飘然而退。\n"NOR,me,target);
       
        }
        else
        {
                message_vision(HIY"$n嘿嘿一笑，大喝到：“佛法虽广，不及我法！” $N的心禅尚未说出便哑口无语了。\n"NOR,me,target);
        }

        me->add("force", -150);
        me->set_temp("cibei_end",time());
        return 1;
}

