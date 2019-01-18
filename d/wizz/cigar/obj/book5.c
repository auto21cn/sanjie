// talk.c  书
// by cigar
// Write by cigar

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIY "【廢話連篇】" NOR , ({ "feihua lianpian","feihua", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long" ,HIG
        "你现在能不能读啊，别浪费了三千两黄金哦，否则气你气的没商量...\n"NOR);
                set("no_sell", "做梦哦，哈哈哈哈哈哈哈!\n");
          set("value", 7000000);
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_drop", "三千两黄金你不多留一会，嘿嘿!\n");
                set("no_give", "还想给人？说白了就是赚你的钱！！！\n");
                set("no_sell", "做梦哦，哈哈哈哈哈哈哈!\n");
                set("no_get", "天下没有白来的东西，除非...\n");
                set("no_put", "别想歪点子了，巫师早就测试过了，还是别费脑子了...气吧..\n");
}
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,feitianlev,exp;

  if( !book->id(arg) ) return notify_fail("你要读什么？\n");
  if(me->is_busy()) return notify_fail("你现在忙着呢，还是等静下心来再读书吧！\n");
  if(me->is_fighting()) return notify_fail("现在才想读书，太晚了吧，猪猪？\n");
  if( (int)me->query_skill("talk",1)>150 )
    return notify_fail("别读了，再读你的舌头都要打卷了。\n");
        if( (int)me->query_skill("talk",1)<101 )
     return notify_fail("你现在说话还结结巴巴怎么屁话连篇？否则骡子能生育，大象鼻子长大葱。\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("你在安全区读书你想死啊，让我知道，小心没收你的书，让你站在雪山顶上沉痛哀悼你那三千两黄金\n");

        if( environment(this_object())!=me ) return notify_fail("你奶奶的，书要拿起来读，你脑子小时候是不是被三轮车撞过?~\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("talk", 1);
  if(exp < 1000000)
    return notify_fail("你的武学不够，别做梦想学了。\n");
  sen_cost=30+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("别读了，再读你就要莫名其妙的死了，到时候找巫师，算你天灾人祸。\n");     
        me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/3;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("talk", gain);

        message_vision("$N手里拿着一本狂语，唧唧歪歪的不知道在说什么，烦啊。\n", me);
  tell_object(me, "你说话的技巧提高了，大功就要告成了，爽吧？！\n");

  return 1;
}
