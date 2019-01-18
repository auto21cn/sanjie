// yashi.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "天明香月楼");
  set ("long", @LONG

数码宝贝的的寝宫，这里四处飘散着淡淡的花香，让人身处
其中便欲昏昏入睡，寝宫中间有一张象牙床(bed)。
LONG);

set("item_desc",(["bed":"一张用无数象牙雕刻而成的床(gosleep,gobed,bed)。 \n", ]));
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"moon5",
]));

create_door("east", "象牙宫门", "west", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed" );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开丝帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"bed_qingong");
            message_vision(HIY "\n丝帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

