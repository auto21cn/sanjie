//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "金陵门");
        set ("long", @LONG

这里是通往兰陵皇宫的第二道大门,大门两边站着许多士兵
威严的陵宫大门好不威风,这里是老百姓的禁区,很是威严
LONG);

  set("objects", ([ /* sizeof() == 2 */
      "/d/huanggong/npc/weishi" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
      "north" : "/u/calvin/兰陵/地区/陵宫大门",
                 "southup" : "/u/calvin/兰陵/地区/乾宫",
        ]));

  setup();
}

int valid_leave(object me, string dir)
{
    if(me->query("office_number")) return 1;
        if (dir == "southup" ) {
        return notify_fail("你都不是当官的,还是往回走吧．\n");
}
 return 1;
}
