//Creat by aeddy@2001/03/22
//Last modified by aeddy@2001/04/18

#include <ansi.h>
inherit COMBINED_ITEM;
int do_eat(string);

void init()
{
      add_action("do_eat", "eat");
}

void create()
{
	set_name(HIM "花瓣" NOR, ({ "hua ban","hua", "ban" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
          set("long", HIM"一片带着樱花香气的粉色的花瓣！\n" NOR);
		set("base_unit", "片");
              set("unit", "些");
		set("value", 1);
		set("no_sell",1);
		set("no_put",1);
	       set("drug_type", "补品");
	}
       set_amount(1);
	setup();
}

int do_eat(string arg)
{
       object me = this_player();
	int howmany;

	howmany = (int)me->query("huaban_eaten");

	 if (!id(arg)) return notify_fail("你要吃什么？\n");

        if (arg!="hua" && arg!="ban")	return 0;

        message_vision("$N吃下了一片 "HIM"樱花花瓣 \n"NOR, me);
        tell_object(me, HIG "你觉得浑身一股清凉之意油然而起遍及全身。\n"NOR);
        me->set("huaban_eaten", howmany+1);

        if (me->query("per") >= 40) {
                message_vision(CYN"$N忽然“哇哇”觉得嘴里非常的苦，吐了一地。\n"NOR, me);
                     me->set("huaban_eaten", 0);
        } else 
        if( me->query("huaban_eaten") >= 200 ) {
                tell_object(me, HIR "你觉得浑身一股火热蓦然升起，面部好象年轻了许多。\n"NOR);
                me->add("per", 1);
                me->set("huaban_eaten", 0);
         }

        add_amount(-1);
        return 1;
}

