// 兰陵续 by Calvin

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "帮派申请处");
  set ("long", @LONG

这里是帮派申请处,你可以来到这里说明你已经具备了开帮立派的能力，首先为此
我们祝贺你。请在这里的申请版上填写上如下资料:

          1.帮派创始人                 2.帮派名称
          3.帮派各层次分级             4.各层次的工作分工
          5.帮派特有招数名称           6.招数攻击率,命中率,防御力率选择
          7.帮派原始人员名单           8.帮派会址
          9.其他补充                   10.其他要求

LONG);

  set("exits", ([ /* sizeof() == 2 */
                    "west" : "/d/calvin/lanling/xingyuejiulou2",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

   setup();
   call_other("/obj/board/clubroom_b","???");
        replace_program(ROOM);
}
