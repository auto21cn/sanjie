//【降魔杖】xiangmo-zhang.c by angell
inherit SKILL;

/*
降魔杖    dodge  5    parry  -5    damage  30
沙僧所创，似拙实巧，威力颇强
*/

mapping *action = ({
   ([   "action":     "$N运足力气，抡起$w，呼！地一声向$n当头拍了下来！",
     "dodge":     15,
     "parry":     -5,
     "damage":     35,
     "damage_type":   "砸伤"
   ]),
   ([   "action":     "只听$N将手中的$w象柳絮般舞将起来，耗不着力，一式「弱水三千」扫向$n$l",
     "dodge":     -5,
     "parry":     -10,
     "damage":     15,
     "damage_type":   "砸伤"
   ]),
   ([   "action":     "$N使出一招「斩妖除魔」，手中的$w拦腰横斩$n",
     "dodge":     10,
     "parry":     -10,
     "damage":     40,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "只见$N手中$w划出一道弧光向$n身形迎去，好一个「浪遏飞舟」",
     "dodge":     5,
     "parry":     0,
     "damage":     30,
     "damage_type":   "瘀伤"
   ]),
   ([   "action":     "$N横持$w，运力丹田，一招「中流击水」直捅$n的$l",
     "dodge":     0,
     "parry":     0,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N的$w望上一挑，直悼$n$l，这式「挑帘望月」的威力可非同一般",
     "dodge":     -10,
     "parry":     -10,
     "damage":     100,
     "damage_type":   "砸伤"
   ]),
});
int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 100 )
     return notify_fail("你的内力不够，没有办法学降魔杖。\n");

   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
     return notify_fail("你必须先找一条禅杖才能学降魔杖。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="staff"||usage="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("TP_perform");
        if( !me->query_temp("TP_perform") ) {
        return action[random(5)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
     return notify_fail("你现在太累了，强练无益。\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   write("你按着所学练了一遍降魔杖。\n");
   return 1;
}
/*
int valid_effect(object me, object weapon, string name, int skill)
{
}
*/
string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/xiangmo-zhang/" + func;
}
