#include <room.h>
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "云楼台");
  set ("long", @LONG

此乃宫上一小台，远望仙境，见金光万道滚红霞，瑞气千条喷紫
烟。远上长桥碧雾蒙，天宫宝殿映云光。当真是天上自来有仙境，
不堕人间点污泥。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
/*
   __DIR__"npc/litianwang":1,
*/
"/d/quest/li/litianwang":1,
]));

  set("outdoors", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_drop", 1);
  set("no_get", 1);
  set("no_put", 1);
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
  if (verb == "bian") return 1;  
  if (verb == "exert") return 1; 
  if (verb == "cast") return 1; 
  if (verb == "drop") return 1; 
  return 0;  
}

