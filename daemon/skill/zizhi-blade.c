// 紫雉刀法
//轩辕古墓特殊攻击技能
//by ivy 2002.2.9
//五月天山雪

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N一招"+HIW"「五月天山雪」"NOR"，手中$w卷起一股狂风，挥向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N手中$w一晃，由下至上撩向$n的$l，一招"+HIM"「无花只有寒」"NOR"使得恰到好处",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N眼神恍惚，手中$w飘摇不定，一招"HIG"「笛中闻折柳」"NOR"斜斜的砍向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "砍伤"
        ]),
        ([      "action":
"$N左手执着$w，右手扶着刀背用力推出，一招"HIC"「春色未曾看」"NOR"扫向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "砍伤"
        ]),
        ([      "action":
"$N冷笑一声，一招"HIR"「晓战随金鼓」"NOR"，手中$w带者丝丝冷风由下至上划向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N狂喝一声，使出一招"HIM"「宵眠抱玉鞍」"NOR"，双手紧握$w
带着逼人的杀气，刺向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N狂喝一声，使出一招"HIB"「愿将腰下剑」"NOR"，双手紧握$w
带着逼人的杀气，刺向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),        ([      "action":
"$N狂喝一声，使出一招"RED"「直为斩楼兰」"NOR"，双手紧握$w
带着逼人的杀气，刺向$n的$l",
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
notify_fail("你的内力不够，没有办法学紫稚刀法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("你必须先找一把刀才能学紫稚刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/zizhi-blade/" + func;
}

