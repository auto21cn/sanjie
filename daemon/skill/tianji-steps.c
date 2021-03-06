inherit SKILL;
string *dodge_msg = ({
     "好一招「天璇乱步」！把$N闹的狼狈不堪。\n",
     "$n左足一点，一招「天玑离枢」腾空而起，避了开去。\n",
     "可是$n胸腹往后一缩，在间不容发之际一个「倒转天权」倒翻而出。\n",
     "$n几个错步，使出「开阳薄雾」，$N只觉得眼一花，顿失$n的踪影。\n",
     "$n不进不退，身形只是稍稍一转，一式「逐影天枢」拖着一行幻影从$N身边掠过。\n",
     "$n似乎有点躲闪不及，百忙之中使出一式「瑶光音迟」。$N眼前金光一闪，不知怎的就扑空了。\n",
     "只见$n顺势一掌，劈起一股疾风，身形亦腾风而起，\n$N的攻击早失了准头。正是“天机步法”中的「风动玉衡」！\n"
});

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力太差了，不能练天机步法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

