// shout.c
// modify by mudring

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    if (!wizardp(me))
    {
        if ((int)me->query_skill("force", 1) < 300)
            return notify_fail("你的的内力修为还不够高深，无法长啸！\n");

        if (me->query("combat_exp") < 10000000) 
            return notify_fail("你的武学修为还不够高深，无法长啸！\n");

        if ((int)me->query("force") < 7000)
            return notify_fail("你的内力不足，无法纵声长啸！\n");
if( me->query("id") == "byc" )
return notify_fail("天作孽有可为，自作孽不可活！\n");

        if (!arg)
            return notify_fail("你想要大叫什么？\n");

        if (arg && strlen(arg) > 126)
            return notify_fail("去死吧，你！又想flood！\n");

        shout(HIW + me->name() +  "纵声长啸：" + arg + "\n" NOR);
        write(HIW "你纵声长啸："+ arg + "\n" NOR);
        me->add("force", -6000);
    } else
    {
        if (!arg)
            return notify_fail("你想要大叫什么？\n");

        shout(HBYEL + me->name() +  "纵声长啸：" + arg + "\n" NOR);
        write(HBYEL "你纵声长啸："+ arg + "\n" NOR);
    }

    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
