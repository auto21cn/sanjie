//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵大街");
        set ("long", @LONG

这是风景怡人的兰陵古城,一片繁荣的景象呈现出
这里热爱生活的人们真挚的心,大理石埔就的街道
两边都是一排排整整齐齐的各式店面,从人们的欢
笑声中可以看出,这里的商业很是发达 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/u/calvin/兰陵/地区/兰陵大街7",
                "south" : "/u/calvin/兰陵/地区/兰陵城心",
                "west" : "/u/calvin/room/星月酒楼",
                 "east" : "/u/calvin/room/兰陵当铺",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
