//测试一下，不知道效果如何 by seng@2005-1-21
//参考了moon的pfm tian;gumu的pfm jiujian;daya的pfm qijian;和combat.h

#include <ansi.h>
#include "/daemon/class/xuanyuan/daya-jian/eff_msg.h"; 
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string dodskill,msg;
    int extra,i,j,tmp,strength,howlong,str,damage,targetforce;
    object weapon = me->query_temp("weapon");
    mapping action;
    extra = me->query_skill("daya-jian",1);
    j = me->query("opinion/mete");

    // howlong=me->query_skill("daya-jian")/(300+j*2);
    // mudring change arithmetic Feb/04/2005
    howlong = 1 + j/3;
    
    damage = extra + j*60;
    if(damage > 700) damage = 700;

    if(me->query("mark/dayagett") <1)
      return notify_fail("［大雅剑法］只有解过才可以使用！\n");
    if ( me->query_skill("sword",1) < 300) return notify_fail("你的基本剑法还不够纯熟，舞出来的剑法怎么能雅？！\n");  
    if ( extra < 300) return notify_fail("你的大雅剑法还不够纯熟！\n");  
       
        if( (int)me->query("force") < 800 )      
                return notify_fail("你的内力不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                 return notify_fail("［大雅剑法］只能对战斗中的对手使用。\n");

		// mudring change 3 to 4 Feb/04/2005
		// and moved here....
       if( time()-(int)me->query_temp("daya_end") < 4 ) 
               return notify_fail(HIR "绝招用多就不灵了！\n" NOR); 
               
               
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);


        me->add("force", -300);

         call_out("remove_ansi",howlong,me,str); 
         me->set("actions",action); 
         me->reset_action();


        if(!target->is_busy()) target->start_busy(2);


        message_vision(HIW  "\n\n$N将手中的"+ weapon->name() +RED"抛向天际，手指不受控制的对着$n凌空划来划去 ！\n\n" NOR, me, target);



// modify by mudring Feb/04/2005
    message_combatd(HIY  "\n「大雅古剑削肉式」，$N手中"+ weapon->name() +HIM"化为万千幻影朝$n的身上疯狂划去！" NOR, me, target);
    message_combatd(RED  "\n\n$N伸手朝空中"+ weapon->name() +RED"一召，鲜血顺着"+ weapon->name() +RED"的剑锋滴滴答答流了下来。$N肃穆而立，心中默念："+HIW"“俺把你来蒙”！" NOR, me, target);
    message_combatd(HIR  "\n$N将手中的"+ weapon->name() +HIM"捏来捏去，忽然变出了个"+HIW"「▄︻┳═一」"+HIM"对着$n的的脑袋瓜子疯狂扫射！" NOR, me, target);
    target->receive_damage("kee", damage, me, "pfm"); 


	j=j+3;
	if (j > 8) j=8;
	for(i=0;i<j;i++) 
	{
        message_combatd(HIR  "\n$N将手中的"+ weapon->name() +HIM"捏来捏去，忽然变出了个"+HIW"「▄︻┳═一」"+HIM"对着$n的的脑袋瓜子疯狂扫射！" NOR, me, target);
        if (i/3==0)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        else
        if (i/3==1)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_SUPER,msg);
        else
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg);       
   }

// end 

           targetforce = target->query("force");
           
// mudring change Feb/04/2004
           //if(targetforce < 0 ) targetforce = 0;
           //target->add("force",-targetforce/2);         

           target->add("force",-targetforce/2);
           if(targetforce < 0 ) targetforce = 0;
// end

         me->set_temp("daya_end",time()); 
         
        return 1;
}


int remove_ansi(object me,int extra) 
    {        
           object here; 
           extra = me->query_skill("daya-jian",1);  
           if(me->query_temp("apply/attack")) 
           me->add_temp("apply/attack",-extra); 
           if(me->query_temp("apply/damage")) 
           me->add_temp("apply/damage",-extra); 
           message_vision(HIW"$N发觉手中宝剑恢复原样！\n"NOR,me); 
           return 1; 
    } 
