// 幽明神通
//玄缘古墓特殊法术
//by ivy 2002.2.9
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("moonshentong", 1) )
                return
notify_fail("你的法术修为还不够高深，无法学习幽明神通。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("gumu") + "/youming-spells/" + spell;
}

string type() { return "magic"; }

