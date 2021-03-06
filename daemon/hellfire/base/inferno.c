
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "地狱火";}//法术名称
string get_help()                  //法术说明,以后直接help,方便修改
{
        return "这个法术可以施展地狱之火海，攻击所有生物，每个角色攻击力不同\n
,攻击是固定的。此法术初期所用，需要一定的法力和魔法点！\n 
攻击效率由高至低排列：魔法师 终结者 精灵族 暗黑地狱使者 剑侠 野蛮人。";

}

int do_cast(object me,object target)
{
        object *ob;
        string helltype,msg;
        int damage,i;
        
        
        if(!me->is_fight())
        {
                tell_object(me,"你没在战斗中！\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"你的法力太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        if(me->is_busy())
        {
                tell_object(me,"你正忙着呢!\n");
                return 1;
        }
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"你的魔法点太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="野蛮人";
        if(!userp(me)) return 1;
        me->add("mana",-2* (120-magic_power[helltype]));
        me->add("magic_pointed",-(120-magic_power[helltype])/2);
        msg=HIC "\n"+me->query("name")+"" NOR;
        msg += CYN "使出"+HIR+"<地狱之火>"+CYN+"，双手挥出一阵阵的火焰向四方打去！\n\n" NOR;
        tell_room(environment(me),msg);
        damage=100-magic_power[helltype];
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
           {
                if(ob[i]==me ) continue;                                                   
                if(!living(ob[i]))  continue;
                if(random((100-magic_power[helltype])*6) > (50+ob[i]->query("level"))/2 )
                {
                        ob[i]->receive_damage("kee", damage*6+random(damage),me);
                        ob[i]->receive_wound("kee", damage*2+random(damage),me);
                        message_vision(HIC "$n被$N的火海烧的浑身是伤，嗷嗷直叫！！\n" NOR,me,ob[i]);
                        COMBAT_D->report_status(ob[i]);             
                
                }
                else
                {
                         message_vision(CYN "$n对$N的火芒闹的黑糊糊狼狈像，$n顿时手忙脚乱扑灭了身上的火！\n" NOR,me,ob[i]);
                
                }
                if(!userp(ob[i])) ob[i]->kill_ob(me);
            }     
            
        me->start_busy(random(3)+1);                   
        return 1;
}


