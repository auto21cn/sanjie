//shulin ����

inherit ROOM;

void create ()

{
        set ("short", "��������");
        set ("long", @LONG

����������������ǵ�����,����һ·�Ͼ�������,�ò�����!

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/calvin/lanling/lanlingxi3",
                "east" : "/d/calvin/lanling/lanlingxi1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}