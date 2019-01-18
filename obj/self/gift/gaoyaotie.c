// Modified by aeddy@2003/01/19

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_tie","tie");
        add_action("do_remove","remove");
        add_action("do_remove","drop");
        add_action("do_remove","give");

	if(environment()->query_temp("banned_talk")) {
      add_action("do_commu","say");
      add_action("do_commu","whisper");
      add_action("do_commu","chat");
      add_action("do_commu","tell");
      add_action("do_commu","xyj");
      add_action("do_commu","party");
      add_action("do_commu","reply");
      add_action("do_commu","rumor");
      add_action("do_commu","sldh");
	}
}

void create()
{
	set_name(HIM"膏药"NOR, ({ "gaoyao" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 100000);
		set("no_sell",1);
		set("long", HIC"这是一张膏药，专门对付乱说话的人 "HIR"(tie 某人) \n"NOR);
	}
	setup();
}

int do_tie(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你想贴谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

        if (userp(me) && wizardp(obj))
                return notify_fail(HIW"贴巫师？你好傻耶。\n"NOR);

	if(obj == me)
		return notify_fail("just shutup.\n");

	if(me->query_temp("banned_talk"))
		return notify_fail("you shutup!!!\n");

	message_vision(HIM "\n$N拿出一张膏药，轻轻托住$n的下巴，叭地贴了上去。\n\n" NOR, 
			me, obj);
	obj->set_temp("banned_talk",1);
	this_object()->move(obj);
	return 1;
}

int do_commu(string arg)
{
	object me=this_player();

	message_vision(HIB"$N张大了嘴巴，却什麽话也说不出来。\n"NOR,me);
	return 1;
}

int do_remove(string arg)
{
	object me=this_player();

	if(!me->query_temp("banned_talk")) return 0;

	if(!arg||arg!=HIM"膏药"NOR) {
		message_vision(HIC"$N用力想撕开膏药，但是没成功。\n"NOR,me);
		return 1; }
	message_vision(HIR"$N把膏药从嘴上撕了下来，鲜血流了一地。\n"NOR,me);
	return 1;
}