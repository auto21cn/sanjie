//兰陵

inherit ROOM;

void create ()
{
        set ("short", "装备店");
        set ("long", @LONG

刚一进门就看到兵器架上摆着各种兵器，从上百斤重的大刀到轻如芥
子的飞磺石，是应有尽有。女老板是老英雄萧振远的二女儿，也是振
远镖局大老板，巾帼不让须眉。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
//              "east" : "/u/calvin/兰陵/地区/兰陵大街6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                 "/d/obj/其他/装备老板" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
