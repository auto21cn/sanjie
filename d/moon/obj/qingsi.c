//情丝
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIB"情丝"NOR, ({"qing si","whip","bian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一条无数细丝编成的白纱，如天上银河般的美丽！\n");
                set("unit", "条");
                set("value", 12000);
                set("wield_msg",HIW "$N轻轻一抖，一条白沙飘然而出！\n"NOR);
                set("unwield_msg",HIW "$N微微一笑,手中的月轮剑“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_whip(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "月宫"
                && me->query_skill("jueqingbian",1) > 1)
    damage_bonus = me->query_skill("jueqingbian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"情丝忽隐忽现飘忽不定。\n" NOR;

}

