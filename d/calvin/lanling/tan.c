// 兰陵续 by Calvin

#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","清渊净水潭");
set ("long",@LONG

这里便是清渊净水潭了,你可以看到正冒着白气的潭水是那么的洁净,
不过更神气的是这里的水所具有的特殊复舒功能的功效了。

LONG);

set("exits",([
"west" : __DIR__"tan3",
]));

set("chat_room",1);
set ("no_pk", 1);
set("valid_startroom", 1);
setup();
}

void init()
{
object who=this_player();
if( (string)who->query("gender")=="男性" || (string)who->query("gender")=="女性" )
// add_action("do_stop", "exert");
// add_action("do_stop", "cast");
// add_action("do_stop", "kill");
// add_action("do_stop", "fight");
// add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", ({"exercise","cast chunqiao","cast","kill","perform,"}));
add_action("do_stop", "meditate");
{
call_out("heal_up", 9, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}

int sounding(object where)
{
string *msgs=({
HIG"一阵淡淡的白气从池面浮起。\n"NOR,
"白气笼罩了你整个的身体。\n"NOR,
HIW"你忽然感觉舒服多了!\n"NOR,
HIC"你随之产生了一种奇妙的感觉。\n"NOR,
});

tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}

who->set("eff_gin", (int)who->query("max_gin"));
who->set("eff_kee", (int)who->query("max_kee"));
who->set("eff_sen", (int)who->query("max_sen"));
message_vision(HIW"咕咕~~~~池面泛起了一朵水花,溅出了一些打在了$N身上，$N一下子软了许多。\n"NOR, who);
write(YEL"你发现自己似乎更舒服了。\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
who->delete_temp("rent_paid");//added by stey 不许再修改！
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"天上传来"NOR+HIC"净衣女神"NOR+HIR"一声怒嚎：“谁让$N来我这宝池的,还不给我滚出去！”\n"NOR,who);
return 1;
}
