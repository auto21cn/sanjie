//巫师公告厅
//by Calvin

inherit ROOM;

void create ()
{
        set ("short", "巫师公告厅");
        set ("long", @LONG

〖 仙侣奇缘门派介绍〗- 目前门派
1.南海普陀山 2.花果山盘丝洞  3.昆仑山月宫 4.灵台方寸山 5.阴曹地府 
6. 东海龙宫 7.枯松涧火云洞 8.陷空山无底洞 9.三界山天一宫 10.万寿山
五庄观 11.大雪山万兽谷 12.大唐将军府 13.万剑之尊蜀山 14.天蓬府(开发中)

LONG);

        set("exits", 
        ([ //sizeof() == 4
      "up" : __DIR__"wizroom",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
