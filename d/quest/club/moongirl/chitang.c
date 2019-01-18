//静月香莲池
//by junhyun@SK

#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","静月香莲池");
set ("long",@LONG

天山冰雪融化汇聚的清水，加上朵朵雪莲造就了着座[静月
香莲池]听说沐浴在这池水中，不但能医治伤病，还能返老
还童。

LONG);

        set("objects", ([ /* sizeof() == 1 */ 
        "/d/moon/obj/xuelian" : 2, 
      ])); 


set("exits",([
"west" : __DIR__"moon5",
]));

set("chat_room",1);
set("no_clean_up", 1);
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
add_action("do_stop", "exercise");
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
HIW"你被池面淡淡水雾包围着……\n"NOR,
HIW"你将池水慢慢的淋在身上……\n"NOR,
HIW"你掬起一捧池水洒在脸上……\n"NOR,
HIW"你轻轻拂拭着自己的臂膀……\n"NOR,
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
message_vision(HIW"一朵雪莲掉入池中，慢慢的融化了，$N一脸舒畅的感觉……\n"NOR, who);
write(WHT"你发现自己的体力似乎恢复了。\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIW"天上传来"NOR+HIG"数码宝贝"NOR+HIW"一声娇喝：“想干什么？冷月宫不是你撒野的地方！”\n"NOR,who);
return 1;
}

