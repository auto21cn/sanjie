inherit ROOM;
#include <room.h> 
#include <ansi.h> 
void create()
{
set("short", HIG"大唐聚义厅"NOR);
        set("long", HIW@LONG
离开了大唐，很多英雄豪杰一时失去了自己的家，失去了自己的方向
，某年某月的某一天，他们发现了一个世外桃源，这就是深圳蛇口站。
　　蛇口站的巫师都十分热情，给他们建立了自己的聚会的总坛，还给他
们搞了一套时下很流行的小黑板，这下，英雄们可以尽情的抒发自己的情
怀了。
　　渐渐地，他们又发现了，蛇口站的玩家比那些笨蛋巫师还要热情，更
有热情的ＭＭ.............
　　慢慢地，一个新的家园又在大家的努力下建成了，这个新的家园就是
....................
LONG NOR
        );
        set("exits", ([ /* sizeof() == 4 */
"south" : "/d/wiz/entrance",
]));
        set("objects", ([
 __DIR__"npc/shizhe" : 1, 
                        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
  call_other("/obj/board/datang_b", "???"); 
set("no_magic", 1);  
               setup();
}

