#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIR"熔岩洞"NOR);
set("long", @LONG
    
这洞内四处都是文武之火，只热的你喘不过气来。
 
LONG );
     set("exits/east", __DIR__"huomigong"+(string)random(8));
     set("exits/west", __DIR__"huomigong"+(string)random(8));
     set("exits/south", __DIR__"huomigong"+(string)random(8));
     set("exits/north", __DIR__"huomigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
       __DIR__"obj/fire" : 1,
]));
setup();
}
void init() 
{
  delete("exits/out");
   if(this_player()->query_temp("shendian/huomigong_kill") >= 2)
    {
        message_vision(HIY"\n刹那间一道路口出现在你的面前。\n\n"NOR,this_player());
     set("exits/out", __DIR__"dongwai");
    } 
if (!((this_player()->query_temp("shendian/huomigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n岂有此理，$N是怎么进来的？出去！\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }
 
   if (this_player()->query_temp("shendian/huomigong") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }
   add_action ("do_cast","cast");
}
int check_hp(object who)
  {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
  if (random(5)==1 && who->query("kee") > 100 )
    {
     who->add("kee",-(70+random(50)));
    message_vision(HIY"四周卷起一道火墙，烧得$N焦头烂额！\n"NOR,who);
    COMBAT_D->report_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N被烧得头晕眼花，再也支撑不住了。\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "在熔岩洞中被烧成了灰烬。\n");
     who->die();
     who->save();
     return 1;
    }
  remove_call_out ("check_hp");
  call_out ("check_hp", 3,who);
  return 1;
  }
int do_cast (string arg)
{
  object who = this_player();
  if (who->query_temp("shendian/huomigong")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"这里不能逃生！\n");
      return 1;
     }
  else return 0;
}
