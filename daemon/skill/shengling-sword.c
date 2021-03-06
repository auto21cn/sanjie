// 圣灵剑法
//轩辕古墓特殊攻击技能
//by junhyun@sk
//

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N一招"+HIW"「新月」"NOR"手中$w划破天际，画出一轮弯月！",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N一招"+HIM"「双月」"NOR"手中$w剑芒吞吐，将$n围在其中！",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N一招"+HIG"「连月」"NOR"手中$w寒光一闪，无数剑影刺向$n！",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一招"+HIC"「神月」"NOR"手中的$w破空之声大作，的刺向$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一招"HIR"「鬼月」"NOR"手中$w带冷风从意想不到的角度划向$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N一招"HIM"「残月」"NOR"双手紧握$w带着逼人的杀气，刺向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 80 )
                return
notify_fail("你的内力不够，没有办法学魔皇刀法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("你必须先找一把剑才能学圣灵剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑，才能练剑法。\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("你的体力不够练这门剑法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/shengling-sword/" + func;
}

