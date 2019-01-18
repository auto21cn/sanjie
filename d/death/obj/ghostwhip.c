//情丝
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIB"鬼炎鞭"NOR, ({"ghost whip","whip","bian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","鬼物，生成在地狱的烈火中，蓝色的鬼火幽然飘动着。\n");
                set("unit", "条");
                set("value", 12000);
                set("wield_msg",HIW "$N左右鬼火阵阵，渐渐的变成一条长鞭。\n"NOR);
                set("unwield_msg",HIB "$N手中的长鞭骤然间成为鬼火,围绕着$N.\n");
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
    
    if( (string)me->query("family/family_name") == "阎罗地府"
                && me->query_skill("hellfire-whip",1) > 1)
    damage_bonus = me->query_skill("hellfire-whip",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"鬼炎鞭上鬼火阵阵。\n" NOR;

}

