// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
        民间一直流传着这麽一个故事：
 话说当年，佛陀召集了所有的动物出席群兽大会，最早到的十二头野兽将作为十二个年号 。 
 群兽大会当天，老鼠最早到，所以兽年中它排行最大，接着是牛，虎，兔，龙，蛇，马，羊，猴，鸡和狗。
 猪最后一个才到，因此十二年兽中它排行最后.   

这是走向亥宫的路上，只见前面可以看到奇特的亥宫耸立在佛陀山峰上！
LONG);


        set("exits", ([
        "southup"    :       __DIR__"toby2",
"southwest" : "/d/kaifeng/wutaishan/wutx",
        ]));

        set("outdoors", "12gong");
        setup();
}
