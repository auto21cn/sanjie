// Room: /d/wiz/wizroom.c
// 巫师连线房间，限制写的权限。。。

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","巫师会议厅");
set("long",
@LONG

这儿就是三界神话的最高会议中心，四下的灯散发着柔和的光，红木
长台的周围放了几个椅子。整个房间的布置是那么的和谐，你真的想
敞开你的心扉，痛痛快快地将所有的实情和大家分享。平时巫师们都
在这儿碰头，如果游戏里面有什么重大事情，通常也是在这儿解决的。
LONG
); 

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/wiz/system",
  "up" : "/d/wiz/wizroom1",
  "north" : "/d/wiz/jobroom",
  "sleeve": "/d/wiz/sleeveroom",
 "guest": "/d/wiz/guest",
  "jail":"/d/wiz/jail",
  "kz": "/d/city/kezhan",
  "south": "/u/aeddy/workroom",
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
          add_action("say_log",({ "say","'"}));
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 1;
       if (verb=="quit") return 1;
       if (verb=="look") return 1;
       return 1;
}

int say_log(string msg)
{
        object me;
        me = this_player();
        if( !msg ) return 0;
        else
        "/cmds/std/say.c"->main(me, msg);
        MONITOR_D->mudring_log("wizsay", me, msg);
        return 1;
}

