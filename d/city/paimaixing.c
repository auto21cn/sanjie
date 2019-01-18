//changan city

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short","天下第一牙" );
        set ("long", @LONG

这是一家有百年历史的老字号牙行，相传曾经为当今皇上拍卖过宫廷
珍宝，皇上亲笔为此行题下“天下第一牙”，从此来牙行拍卖金玉珠
宝的人络绎不绝。牙行的门口挂有一块牌子(paizi)。
LONG);
        set("item_desc", ([
                "paizi": @TEXT
关于拍卖的命令，牙行将收取拍卖价钱5%的手续费。

paimai 物品 with 钱数（银子为单位） 
paimailist         ：查询当前的拍卖物品
yao                ： 取回自己的东西

bidd 钱数     ：  参加竞拍

TEXT
        ]) );

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"bank",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/paimaishi" : 1,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
}
