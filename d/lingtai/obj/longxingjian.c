

#include <weapon.h>

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"斜月龙星剑"NOR, ({"longxing jian","sword","jian"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","方寸山镇山之宝，相传为三星祖师的圣物。\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N双手一挥，天空中龙吟大作，一柄宝剑从天而降！\n"NOR);
                set("unwield_msg",HIW "$N手中宝剑突然化作一条青龙,飞向天空...\n");
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
        if( (string)me->query("family/family_name") == "方寸山三星洞"
          && me->query_skill("liangyi-sword",1) > 1)
        damage_bonus = me->query_skill("liangyi-sword",1);
        damage_bonus = (damage_bonus+random(damage_bonus))/2;
        
        victim->receive_wound("kee",damage_bonus);
        return HIR"斜月龙星剑上迸发出耀眼的火光。\n" NOR;

}

