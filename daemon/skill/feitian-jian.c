// feitian-jian.c  飞天剑
// Modified by Cody May.2001
// Write by Cody


#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "突然之间，白影急幌，$n刹那间已远去数丈之外，$N顿时扑了个空。\n",
        "$n身行如鬼魅般一晃，突然向后滑出丈余，立时又回到了原地，躲过了$N这一招。\n",
        "$N只觉眼前一花，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
        "$n身行忽的加快，身行忽的变得朦胧不清，$N的凌厉招式竟然透体而过，原来竟是一具幻影。\n",
        "只见$n身子向后一翻，随着$N的招式左右摆动，竟使得$N招招落空。\n",
});


mapping *action = ({
	([	"name":			"龙巢闪",
		"action":
"只见$N的一招「"HIC"龙巢闪"NOR"」在$n的身上施展连环斩击",
                "dodge":                -5,
                "parry":                 -5,
		"damage":		35,
		"damage_type":		"斩伤"
	]),
	([	"name":			"土龙闪",
		"action":
"$N使出「"HIY"土龙闪"NOR"」，手中的$w向地面猛烈斩击，打碎地面石块溅向$n的$l",
                "dodge":                0,
                "parry":                 0,
		"damage":		45,
		"damage_type":		"刺伤"
	]),
        ([      "name":                 "龙椎闪",
                "action":
"$N飞身跃起，使一招「"HIB"龙椎闪"NOR"」，手中$w剑光暴长，向$n淩空大力劈下",
                "dodge":                5,
                "parry":                 10,
                "damage":               50,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "双龙闪",
                "action":
"只见$N迅速拔出$w，一招「"HIG"双龙闪"NOR"」跟着无数剑光刺向$n的$l，\n"
"但是$N利用拔刀后空隙，利用刀鞘做全无缝隙的攻击，只见刀鞘以重重的打向$n的$l",
                "dodge":                10,
                "parry":                 10,
                "damage":               55,
                "damage_type":          "打伤"
        ]),
        ([      "name":                 "飞龙闪",
                "action":
"$N假装高速拔刀，实则利用腕力推出刀身，一招「"CYN"飞龙闪"NOR"」刀柄已往$n$l飞去",
                "dodge":                10,
                "parry":                 0,
                "damage":               45,
                "damage_type":          "打伤"
        ]),
        ([      "name":                 "龙翔闪",
                "action":
"$N一手按刀身，一招「"HIW"龙翔闪"NOR"」由下而上直抽向$n的$l",
                "dodge":                -5,
		"parry":		 5,
		"damage":		40,
		"damage_type":		"刺伤"
	]),
	([	"name":			"龙卷闪",
		"action":
"只见$N反身避过攻击的同时，一招「"MAG"龙卷闪"NOR"」利用旋转的离心力出刀攻击直射$n的$l",
                "dodge":                -5,
                "parry":                 -5,
		"damage":		40,
		"damage_type":		"刺伤"
	]),
	([	"name":			"龙鸣闪",
		"action":
"$N神速的收刀，由急速的收刀而发出超声波，一式「"HIR"龙鸣闪"NOR"」，扰乱$n半规管的平衡能力",
                "dodge":                0,
                "parry":                 -5,
		"damage":		50,
		"damage_type":		"震伤"
	]),
});
int valid_learn(object me)
{
	if (me->carry_object("/obj/feitian/feitian-book1") || me->carry_object("/obj/feitian/feitian-book2")
              || me->carry_object("/obj/feitian/feitian-book3") || me->carry_object("/obj/feitian/feitian-book4"))
		return notify_fail("飞天剑是飞天御剑流的剑法。没有他们的同意你怎么能乱学呀。\n");

	return 1;
}

int practice_skill(object me)
{
	int skill;
	skill = me->query_skill("feitian-jian",1);
	if( me->is_fighting() )
        	return notify_fail("你不能在战斗中练习。\n");
    	if (me->query_skill("feitian-jian", 1) < 200)
        	return notify_fail("你的修为还不足以练飞天御剑流。\n");
	if ((int)me->query("kee") < 100)
		return notify_fail("你体质欠佳，强练飞天御剑流有害无益。\n");
	if ((int)me->query("force") < 100)
		return notify_fail("你内力不足，强练飞天御剑流有走火入魔的危险。\n");
	if (me->query_skill("sword",1)<= skill)
        	return notify_fail("你的基本剑法不够，无法练习飞天御剑流的技巧！\n");
	me->add("kee", -50);
        me->add("force", -50);
//        message_vision("$N随意挥舞击刺，然后练了一遍飞天御剑流。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage == "sword" || usage == "dodge" || usage == "parry";
}

string query_dodge_msg(string limb,object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
    return CLASS_D("quest") + "/feitian-jian/"+func;
}
