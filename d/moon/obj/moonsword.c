//月轮剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIW"月轮剑"NOR, ({"moon sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","点点星光,明月如初,千年寒山雪,终成月轮剑,昆仑山玉女峰镇山之宝！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N左手虚空画出一轮明月,右手向前一探,手中已然多了一柄寒光四射的宝剑!！\n"NOR);
                set("unwield_msg",HIW "$N微微一笑,手中的月轮剑“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(120);
        setup();
}
/*
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "月宫"
                && me->query_skill("snowsword",1) > 1)
    damage_bonus = me->query_skill("snowsword",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/4;

    victim->receive_wound("kee",damage_bonus);
    return HIR"月轮剑上闪出点点星月之光！\n" NOR;

}
*/

