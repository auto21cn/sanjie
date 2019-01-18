//神天之巅
//by junhyun@SK

#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"神天之巅"NOR); 
set ("long",@LONG

空明，无念，去凡心，化红尘，身处着着世外桃源的最巅峰
你不由得痴了，你感觉灵台一片清澈。好似脱胎换骨一般。

LONG);

        set("objects", ([ /* sizeof() == 1 */ 
      ])); 


set("exits",([
//"west" : __DIR__"moon5",
]));


set("outdoors", "神天之巅"); 
set("no_clean_up", 0); 
set("chat_room",1);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}

void init()
{
object who=this_player();
if( (string)who->query("gender")=="男性" || (string)who->query("gender")=="女性" )
add_action("do_stop", "exert");
add_action("do_stop", "cast");
add_action("do_stop", "kill");
add_action("do_stop", "fight");
add_action("do_stop", "perform");
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
HIW"你被一层淡淡的云雾包围着……\n"NOR,

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
message_vision(HIW"云雾缥缈间，$N如同沐浴在云海中……\n"NOR, who);
write(WHT"你感觉好像精神了很多，神清气爽。\n"NOR);
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
message_vision(HIW"天上传来"NOR+HIG"天神"NOR+HIW"一声怒喝：“想在这里撒野？！”\n"NOR,who);
return 1;
}


