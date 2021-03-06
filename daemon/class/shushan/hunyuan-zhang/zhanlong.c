//fumozhang perform 斩龙诀
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int myexp, yourexp, myskill, yourskill;
        int ap, dp, damage, def;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIY"「斩龙诀」只能对战斗中的对手使用。\n"NOR);
        if (!PFM_D->valid_family(me, "蜀山剑派"))
                return notify_fail(HIW"你不是蜀山派弟子，领悟不了“斩龙诀”的精要！\n"NOR);
        if( (int)me->query_skill("hunyuan-zhang",1) < 100)
                return notify_fail(HIW"你的浑圆掌还不够纯熟!\n"NOR);
        if( (int)me->query("force") < 300)
                return notify_fail(HIW"你的内力不够了!\n"NOR);
        if( (int)me->query("max_force") < 800)
                return notify_fail(HIW"你的内力太弱,「斩龙诀」发出去也没有威力。\n"NOR);


        msg = HIR
"\n$N惨然一笑,一声长啸，骈指如剑，竟然是林家的绝技--“斩龙诀”，向着$n横腰攻去！\n" NOR;
        myexp= me->query("combat_exp") /900;
        yourexp=target->query("combat_exp")/1000;

        myskill=me->query_skill("hunyuan-zhang",1);
        yourskill=target->query_skill("dodge");
        ap=myexp*myskill;
        dp=yourexp*yourskill;
        if (random(ap+dp)>dp)
        {
                msg += HIW
"\n只见白光一闪，$n的腰际已经被一扫而断!\n" NOR;
                damage=(int) me->query("max_kee")/2;
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                if(me->query_temp("shushantop")) target->start_busy(2);
                //me->start_busy(random(2)+1); 
                me->start_busy(1); 
        }
        else 
        {
                msg += HIW "$n狂笑一声:“这点微末之技能奈我何？”\n" NOR;
                me->start_busy(random(2)+1);


        }
        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )
                tell_object(me, sprintf( GRN "AP：%d，DP：%d，伤害力：%d\n" NOR,
                                ap/100, dp/100, damage));

        message_vision(msg, me, target);
        return 1;
}


