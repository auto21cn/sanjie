// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
����һ������ֲ���С·,�������˻�������,һ·��ֻ��������������.
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/1",   
       "north" : "/d/milin/qy/2",   
       "northwest" : "/d/milin/qy/1",   
       "northeast" : "/d/milin/qy/1",   
       "southeast" : "/d/milin/qy/scc",   
       "southwest" : "/d/milin/qy/2",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}