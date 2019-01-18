//leaveclub.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(string arg)
{
    string club_name;
    object me;
    me=this_player();

    if (!me->query("club"))
        return notify_fail("你还没有入帮派怎么退帮？\n");

    if (me->query("club_master",1)==1)
        return notify_fail("你必须先将帮派大权转移给他人才能离开帮会。\n");
  
    if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着呢！\n");
    
    club_name=me->query("club");

    me->delete("club");
    if (me->query("new_title"))
        me->delete("new_title"); 
    me->delete("newtitle");
    if (me->query("club_master,1")==1) 
        me->delete("club_master");

    message_vision("$N主动退出了"+club_name+"。\n",me);

    me->save();
    return 1;
}


int help(object me)
{
write(@HELP
指令格式 : leaveclub  

主动离开一个帮派。
HELP
    );
    return 1;
}


