
inherit ROOM;
int block_cmd(string);
void create ()
{
  set ("short", "鸾凤殿");
  set ("long", @LONG

鸾凤大殿里金光闪烁瑞霭如云，紫气环绕，殿中是雕龙绘凤祥云
朵朵，殿心有一白玉台阶，正中是金色彩凤宝座，一代女皇武则
天怡然高坐。两边各有一个侍女肃然伫立，神态端庄。

LONG);

  set("exits", ([
        "south"   : __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/shinv" : 2,
        __DIR__"npc/wuzetian" : 1,
     "/d/quest/feizei/feizei":1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}


void init()
{
  add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
 string verb;
verb = query_verb();
if (verb == "xiudao") return 1;
 if (verb == "exert") return 1;
 return 0;
}

