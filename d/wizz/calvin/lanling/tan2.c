// ������ by Calvin

inherit ROOM;

void create ()
{
        set ("short", "��ԨС��");
        set ("long", @LONG

������һ��ʯͷ�̳�·��С��,��ȥ��Ԩ��ˮ̶Ψһ��·;��

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "southwest": "/d/calvin/lanling/tan1",
          "northeast": "/d/calvin/lanling/tan3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        set("outdoors", "lanling");
        setup();
        replace_program(ROOM);
}