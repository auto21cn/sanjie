// tianheforce.c
// by Calvin and Leox 共同开发
// 版权所有 未经许可不得翻录

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("天河心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("tianpeng") + "/tianheforce/" + func;
}
