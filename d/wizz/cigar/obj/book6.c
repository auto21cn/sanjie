// talk.c  书
// by cigar
// Write by cigar

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIG "【知乎者也卷】" NOR , ({ "zhihu zheye","zhzy", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long" ,HIG
        "你现在能不能读啊，别浪费了三千两黄金哦，否则气你气的没商量...\n"NOR);
          set("value", 3000000);
                set("no_sell", "做梦哦，哈哈哈哈哈哈哈!\n");
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_drop", "你的钱不是钱啊，着本书可是金书啊，哈哈!\n");
                set("no_give", "还想给人？说白了就是赚你的钱！不服气？来打我啊。哈哈。\n");
                set("no_sell", "还想捞点回来，做梦哦，哈哈哈哈哈哈哈!\n");
                set("no_get", "别人花钱你来用，除非人类智商=0。\n");
                set("no_put", "你还要留着？省省吧，笨笨！\n");
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
  if( (int)me->query_skill("talk",1)>250 )
    return notify_fail("别读了，再读你的舌头都要打卷了。\n");
        if( (int)me->query_skill("talk",1)<151 )
     return notify_fail("你现在说话还结结巴巴怎么知乎者也？受不了，你去自杀吧。\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("你在安全区读书你想死啊，让巫师知道，小心没收你的书，让你站在雪山顶上沉痛哀悼你那三千两黄金\n");

        if( environment(this_object())!=me ) return notify_fail("你奶奶的，书要拿起来读，你脑子小时候是不是被三轮车撞过?~\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("talk", 1);
  if(exp < 1000000)
    return notify_fail("你的武学不够，别做梦想学了。\n");
  sen_cost=20+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("别读了，再读你就要莫名其妙的死了，到时候找巫师，算你天灾人祸。\n");     
        me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/3;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("talk", gain);

        message_vision("$N满嘴知乎者也，毫无情调。\n", me);
  tell_object(me, "你说话的技巧提高了！\n");

  return 1;
}
