// Room: /d/wiz/wizroom.c

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","巫师会议厅");
  set ("long", 


HIY"              %%%  - -  %%%
"+HIG"我偷偷的翻墙进来"+HIY"    (  "+HIB"@ @"+HIY"  )   "+HIG" 偷看来了，嘿嘿~！！
"+HIY"━━━━━━━━━oOOo-(_)-oOOo━━━━━━━━━━━━"+HIR"


                   严禁在此处删除"+HIW"POST
"+HIR"                   严禁在此处"+HIM"谈情说爱\n"NOR);
  


  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "up" : __DIR__"wizroom1",
  "north" : __DIR__"jobroom",
  "down" : __DIR__"wizroom2",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"punish",
  "int":__DIR__"init",
  "kz": "/d/city/kezhan",
  "south": "/u/aeddy/workroom",
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
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


