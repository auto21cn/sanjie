//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

inherit ROOM;

void create()
{
  set ("short", "密室");
  set ("long", @LONG
密室中黑黑的，看不大清楚。
LONG);

          set("objects", ([ /* sizeof() == 1 */
// "/include/net/cao" : 1,
//  "/binaries/std/armor/ynxy" : 1,
]));

  set("no_clean_up", 1);

  setup();
}
