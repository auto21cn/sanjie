//longma-spear 龙马枪法 by angell

/*
龙马枪法共九式分两部
上部为马部，共四式，轻灵飘逸，难以招架
下部为龙部，亦四式，气势磅礴，威力巨大
当将龙马枪法和步法彻底贯通的时候
还会有一式威力巨大的克敌奇招出现
*/

inherit SKILL;
mapping *action = ({
        ([      "action":
"$N手中$w向前一挺，人枪合一，一式「一马当先」向$n直冲过来。",
                "damage":               20,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N脚下不停，一阵飞奔，手中$w突然向出一递，这一式「驷马难追」真是快到了极点！",
                "damage":               15,
                "dodge":                -15,
                "parry":                -5,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一口气抖出五朵枪花，分指$n双手双脚和六阳魁首！这一招可有个名堂，叫「五马分尸」！",
                "damage":               30,
                "dodge":                0,
                "parry":                -5,
                "damage_type":  "割伤"
        ]),
         ([      "action":
"$N将手中$w舞的似泼风一样，四面八方不是枪花就是人影，好一招「万马奔腾」！",
                "damage":               15,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N手中$w忽地变得琢磨不定，颤动不已，这一式「龙游浅水」委实难以招架！",
                "damage":               30,
                "dodge":                10,
                "parry":                -15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N忽作龙吟，$w带着逼人的气势卷向$n，这招「龙在江湖」一现，日月无光，风云色变，着实令人刮目相看。",
                "damage":               35,
                "dodge":                20,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
 ([      "action":
"$N身形陡变，步若龙行，$w胡乱戳出，看似毫无章法，但这「龙战于野」的真蒂有几人能够猜透呀！",
                "damage":               40,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "戳伤"
        ]),
 ([      "action":
"$N忽然腾身而起，$w直上直下直指$n，这招「龙翔天际」实在不容小视。",
                "damage":               35,
                "dodge":                20,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
 ([      "action":
"$N倒提$w绕着$n越转越快，枪若龙行，人走马步，$n顿时为这招「龙行马步」所困。",
                "damage":               40,
                "dodge":                -20,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法练龙马枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");
if( (int)me->query_skill("longma-spear",1) < (int)me->query_skills("longma-steps",1) )
                return
notify_fail("你的龙马步法不够纯熟，无法学习更高的龙马枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon, int total)
{
    total=3;
    if (me->query_skill("longma-spear", 1) > 99)
        total=7;
  if (me->query_skill("longma-spear", 1) > 199 && me->query_skill("longma-steps",1) > 199)
        total=8;
    return action[random(total+1)];
}


int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");
if( (int)me->query_skill("longma-spear",1) < (int)me->query_skills("longma-steps",1) )
                return
notify_fail("你的龙马步法不够纯熟，无法领悟更高的龙马枪法。\n");
        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍龙马枪法。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/longma-spear/" + func;
}
