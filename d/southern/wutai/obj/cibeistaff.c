//慈悲法杖
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit STAFF;
#include <ansi.h>
void create()
{
        set_name(HIY"慈悲法杖"NOR, ({"cibei fazhang","staff","zhang"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","慈悲法杖发出耀眼的佛光,普照四周!\n");
                set("unit", "把");
                set("value", 12000);
                set("wield_msg",HIW "$N一声佛门狮子吼,手中光芒突现,赫然握着一把禅杖！\n"NOR);
                set("unwield_msg",HIW "$N双手一晃,慈悲法杖“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_staff(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "南海普陀山"
                && me->query_skill("lunhui-zhang",1) > 1)
    damage_bonus = me->query_skill("lunhui-zhang",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIY"慈悲法杖佛光普照！\n" NOR;

}

