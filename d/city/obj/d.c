// bianshi dan.c 变尸丹
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();
void init()
{
    if(this_player()==environment())
      add_action("do_eat", "eat");
}
void create()
{
set_name("变尸丹", ({"bianshi dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "这是无天老魔潜心炼就的怪药,多食无益，能让你的gold不翼而飞!\n");
set("unit", "颗");
 set("value", 0);
              set("is_monitored",1); 
        }
}
int do_eat(string arg)
{
  object me = this_player();

           log_file("player/dcityobjd",
                   sprintf("%s(%s) eat dan on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) ); 
//me->add("combat_exp", 10000 );
me->add("potential", -50000 );
//me->add("daoxing", 30000 );
me->delete("balance");
// 34  me->add("MKS",10);
//me->add("mieyao/number",30);
//me->add("mud_age",3600);
message_vision("$N吃下了一颗变尸丹,时间久了可能会引变为腐尸。\n", me);
tell_object(me,HIR + BLINK+ "你既然知道这个有问题，还不举报巫师，暂时做一点小的惩罚。\n"NOR); 
tell_object(me,HIG+BLINK "你损失了所有存款，\n你丢失了五万潜能，\n并且记录在案等候巫师处理。\n"NOR); 
  destruct(this_object());
  return 1;
}
