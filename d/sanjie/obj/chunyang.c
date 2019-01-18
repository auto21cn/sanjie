//混天朝阳剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"混天纯阳剑"NOR, ({"chunyang jian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一柄沾满神佛鲜血与灵气的宝剑。散发着令人生畏的寒邪之光！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N右手一晃，手中已多了一柄混天纯阳剑！\n"NOR);
                set("unwield_msg", "$N放下手中的混天朝阳剑。\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "三界山"
                && me->query_skill("huxiaojian",1) > 1)
    damage_bonus = me->query_skill("huxiaojian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIR"混天纯阳剑"+HIW"上闪出丝丝寒邪之光！\n" NOR;

}

