//Cracked by Roath

// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
                set("value", 4000);
		set("drug_type", "补品");
            set("fake",1);
	}
  
        set("no_sell",1);
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要吃什么？\n");

    if( me->query("sen")<100) return notify_fail("你无精打采的想干什么？\n");
         me->add("sen",50);
	if(environment(me)->query("alternative_die"))
	    return notify_fail("你不能在这儿吃"+name()+"。\n");

	message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快跳了起来。\n" NOR, me);  	

//吃完了应该消失，否则会一直加"sen",这样就出现 bug了   modified by seng@2005-1-26
      destruct(this_object()); 
         return 1;
}

