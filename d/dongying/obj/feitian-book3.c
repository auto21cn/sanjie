// feitian-jian.c  飞天剑
// Modified by Cody May.2001
// Write by Cody

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIG "飞天御剑术" NOR , ({ "feitian book3","book3", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
             set("long" ,HIG
        "这是一本飞天剑派的书, 由绯村剑心所写的。
       上面写着飞天剑法---终级篇。\n "NOR,
        );
                set("value", 0);
                set("material", "paper");
         }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能给人。\n");
                set("no_get", "这样东西捡不起来。\n");
                set("no_put", "这样东西不能乱放。\n");
}
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,feitianlev,exp;

  if( !book->id(arg) ) return notify_fail("你要读什么？\n");
  if(me->is_busy()) return notify_fail("你现在忙着呢，还是等静下心来再读书吧！\n");
  if(me->is_fighting()) return notify_fail("临阵磨枪可来不及啦！\n");
  if( (int)me->query_skill("feitian-jian",1)<100 )
    return notify_fail("你拿起书仔细读了半天，但怎么也读不懂。\n");
  if( (int)me->query_skill("feitian-jian",1)>150 )
    return notify_fail("你已经把飞天剑的终级篇完全掌握了，再读也不会让你长进多少。\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("feitian-jian", 1);
  if(exp*10 < feitianlev*feitianlev*feitianlev)
    return notify_fail("你的武学不够，再怎么读也没用。\n");
  sen_cost=20+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("你觉得头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/6;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("feitian-jian", gain);

  message_vision("$N正专心地研读"+book->query("name")+"。\n", me);
  tell_object(me, "你研读飞天剑(终级篇)的技巧，似乎有点心得。\n");

  return 1;
}
