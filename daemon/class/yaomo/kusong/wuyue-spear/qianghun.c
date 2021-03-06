//qianghun.c
//五岳枪魂
//Created by wuyou@sk_sjsh
//2003-8-12

#include <ansi.h>

inherit SSERVER;

void npc_attack( object invoker, object target, string npc, object where );

string npc_dir = "/obj/npc/shanshen";

int perform(object me, object target)
{
        string msg;
        object weapon, where; 
        int damage, ap, dp, i;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"你要对谁施展「五岳枪魂」？\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"「五岳枪魂」只能在战斗中使用！\n"NOR); 
        
        if( !PFM_D->valid_family(me, "火云洞"))
                return notify_fail(CYN"「五岳枪魂」是火云洞不传之绝艺！\n"NOR);
            
        if( (string)me->query_skill_mapped("force")!="huomoforce")
                return notify_fail(CYN"你必须运用火魔心法才能召唤「五岳枪魂」。\n"NOR);

        if( (int)me->query("force") < 250+(int)me->query("force_factor") )
                return notify_fail(CYN"你的内力不足，召唤不出「五岳枪魂」。\n"NOR);

        if( me->query("max_force") < 3000 )
                return notify_fail("你的内力修为甚浅，不足以用「五岳枪魂」。\n"NOR);
                
        if( (int)me->query("mana") < 250 )
                return notify_fail(CYN"你的法力不足，召唤不出「五岳枪魂」。\n"NOR);

        if( me->query("max_mana") < 3000 )
                return notify_fail("你的法力修为甚浅，不足以用「五岳枪魂」。\n"NOR);                   

        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(CYN"你身体太虚弱了，无法施展「五岳枪魂」！\n"NOR);

        if( time()-(int)me->query_temp("qianghun_end") < 4 ) 
                return notify_fail(CYN"你现在内息尚未平复，再用此绝技恐有损元气！\n"NOR); 
        if( time()-(int)me->query_temp("buhui_end") < 2)    
                return notify_fail(CYN"「不悔」与「五岳枪魂」无法连续使用！\n"NOR);                          
        if( (int)me->query_skill("wuyue-spear", 1) <400 )
                return notify_fail(CYN"你的五岳神枪不够纯熟，无法使出这招「五岳枪魂」！\n"NOR);
                
        if( (int)me->query_skill("spear", 1) <400 )
                return notify_fail(CYN"你的基本枪法不够纯熟，无法使出这招「五岳枪魂」！\n"NOR);           

        if( (int)me->query_skill("huomoforce", 1) <400 )
                return notify_fail(CYN"你对火魔心法领悟尚浅，不能使出「五岳枪魂」！\n"NOR);
                
        msg = HIY "\n$N手举"+ weapon->query("name")+ HIY"直指苍天，仰天长啸："HIW"“五岳山神，助我除魔。”\n"NOR;            
        msg += HIY "\n啸声刚罢，天上一道闪电直落枪尖，幻化出一道绚烂的光芒！\n\n" NOR;
        msg += HIR "          ┏━┓                          ┏━┓\n"NOR;
        msg += HIR "          ┃"HIW"縱"HIR"┃ ┏━┓┏━┓┏━┓┏━┓ ┃"HIW"神"HIR"┃\n"NOR;
        msg += HIR "          ┃"HIW"橫"HIR"┃ ┃"HIW"五"HIR"┃┃"HIW"嶽"HIR"┃┃"HIW"槍"HIR"┃┃"HIW"魂"HIR"┃ ┃"HIW"槍"HIR"┃\n"NOR;
        msg += HIR "          ┃"HIW"五"HIR"┃ ┗━┛┗━┛┗━┛┗━┛ ┃"HIW"無"HIR"┃\n"NOR;   
        msg += HIR "          ┃"HIW"嶽"HIR"┃                          ┃"HIW"敵"HIR"┃\n"NOR;
        msg += HIR "          ┗━┛                          ┗━┛ \n"NOR;
        
        ap = me->query_skill("wuyue-spear", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");      
        
        if( random((ap + dp)/200) >  dp/1000 )
        {
                msg += HIY "\n天上一道五彩神光将$n笼罩，$n立即不能动弹。\n"NOR;
                msg += HIY "$N手中的"+ weapon->query("name")+ HIY"化作一道闪电，洞穿$n的身体！\n"NOR;
                
                damage = (int)me->query_skill("spear",1) / 2 + (int)me->query_skill("wuyue-spear",1) / 2
                + random((int)me->query_skill("huomoforce",1) / 2) + random((int)me->query_skill("pingtian-dafa",1) / 2)
                + (int)me->query("str") + me->query("force_factor");
                
                if(!target->is_busy())
                        target->start_busy(2);
                        
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage, me, "pfm");   
                target->receive_damage("sen", damage/2, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm"); 
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);                                
                
                me->add("force", -100-(int)me->query("force_factor"));
                me->receive_damage("kee", 100);                
        }
        else 
        {
                if (random(2)==1)
                {
                        msg += HIY "\n瞬间，五岳山神屹立在$n的面前，对$n发动攻击！\n"NOR;
                        message_vision(msg, me, target); 
                        where=environment(target);
                        for(i=1;i<=5;i++)
                        {
                                call_out("npc_attack", 1, me, target, npc_dir+i, where);
                        }
                        me->add("mana", -200);
                        me->receive_damage("sen", 100);  
                }
                else
                {
                        msg += HIY "\n$n尚未等你召唤出"HIR"「五岳枪魂」"HIY",便向$N发动反击，$N不得不举枪相迎。\n"NOR;
                        message_vision(msg, me, target); 
                        me->receive_damage("kee", 20);  
                        me->receive_damage("sen", 20); 
                        me->add("force", -20);
                }
        }
        
        me->set_temp("qianghun_end",time());
        return 1;
       
}
                        
void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));

        COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
        
        // give the killing credit to the invoker.
        // so this would be counted as PK if the invoker is user.

        if(target->query_temp("last_damage_from")==attacker)
                target->set_temp("last_damage_from", invoker);
        
        if(target->query_temp("last_fainted_from")==attacker)
                target->set_temp("last_fainted_from", invoker->query("id"));
        
        destruct(attacker);
}
                             
