// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
十二生肖也被称为十二年兽。在中国的历法上有十二只年兽依次轮流当值，

这是走向亥宫的路上，只见前面可以看到奇特的亥宫耸立在佛陀山峰上！
LONG);


        set("exits", ([
 "westup"    :       __DIR__"baiyang",
            "northdown"  :       __DIR__"toby1",
        ]));

        set("outdoors", "12gong");
        setup();
}
