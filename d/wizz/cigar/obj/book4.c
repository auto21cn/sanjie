// talk.c  书
// by cigar
// Write by cigar

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIW "【亂 語】" NOR , ({ "luan yu","luanyu", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long" ,HIG
        "你的国语标准吗？请跟我一起念：万万望望，望旺万望，腕完望碗...好了，狗狗别叫了，吃骨头了。\n"NOR);
          set("value", 10000000);
                set("no_sell", "做梦哦，哈哈哈哈哈哈哈!\n");
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_sell", "做梦哦，哈哈哈哈哈哈哈!\n");
                set("no_drop", "三千两黄金你不多留一会，嘿嘿!\n");
                set("no_give", "给人？说白了就是赚你的钱！！！\n");
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
  if( (int)me->query_skill("talk",1)>100 )
    return notify_fail("赶快去买第二卷，<<废话连篇>>卷吧，再读也不会让你长进多少。\n");
//:        if( (int)me->query_skill("talk",1)<2 )
//:                return notify_fail("你现在还不会说话怎么狂语？否则母猪都能上树。\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("你在安全区读书你想死啊，让我知道，小心没收你的书，让你站在雪山顶上沉痛哀悼你那五千两黄金\n");

        if( environment(this_object())!=me ) return notify_fail("你奶奶的，书要拿起来读，你脑子小时候是不是被三轮车撞过?~\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("talk", 1);
  if(exp < 1000000)
    return notify_fail("你的武学不够，别做梦想学了。\n");
  sen_cost=30+(60-(int)me->query_int())+(50-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("别读了，再读你就要莫名其妙的死了，到时候找巫师，算你天灾人祸。\n");     
        me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/3;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("talk", gain);

        message_vision("$N手里拿着一本狂语，唧唧歪歪的不知道在说什么，烦啊。\n", me);
  tell_object(me, "你说话的技巧提高了，呀呀学语的时代过去了。\n");

  return 1;
}
