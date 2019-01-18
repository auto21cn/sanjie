//菩提杖


#include <weapon.h>
inherit STICK;
#include <ansi.h>

void create()
{
        set_name(HIG"菩提杖"NOR, ({"puti zhang","stick","bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","一把淡绿色的玉棒，入手滑腻，颇有些份量。\n");
                set("unit", "根");
                set("value", 12000);
                set("wield_msg",HIW "$N念动心决，菩提杖缓缓从背后升起。\n"NOR);
                set("unwield_msg",HIW "$N念动口诀,菩提杖化为一缕青烟,从手中消失了!\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 
                set("weapon_prop/courage", 20);
        }
        init_stick(120);
        setup();
}

mixed hit_ob(object me, object victim)
{
        int damage_bonus = 0;    
        if( (string)me->query("family/family_name") == "方寸山三星洞"
                 && me->query_skill("qianjun-bang",1) > 1)
        damage_bonus = me->query_skill("qianjun-bang",1);
        damage_bonus = (damage_bonus+random(damage_bonus))/2;
        victim->receive_wound("kee",damage_bonus);
        return HIB"菩提杖上闪出一丝幽幽绿光。\n" NOR;

}

