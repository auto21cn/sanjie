// 兰陵续 by Calvin


#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create ()
{
        set ("short","兰陵钱庄" );
        set ("long", @LONG

这是一家特大的钱庄,里面的装修也极为考究,这里可以很方便的存取货币。
大堂的前面挂这一块牌子(paizi)

LONG);
        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：

account         查帐。
deposit         存款。
withdraw        取款。
convert         兑换钱币。

TEXT
        ]) );

        set("exits", 
        ([ //sizeof() == 4
              "west" : "/d/calvin/lanling/jie2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
               "d/calvin/npc/golder" : 1,
        ]));


	set("no_clean_up", 0);
        setup();
}

void init()
{
    reset_balance(this_player());
    ::init();
}

void reset_balance(object me)
{
    int myexp=(me->query("daoxing")+me->query("combat_exp"))/1000;
    int allowed, removed_gold;
    string myid=me->query("id");
    string NPCNAME="老板";

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
	me->set("balance_old", me->query("balance"));
	me->set("balance", allowed);
	removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
	log_file("MONEY_RESET", ctime( time() )+"：魏大人收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
		"，这、这真不知怎么说是好．．．\n"NOR);
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
		"昨日魏大人派人前来察案，发觉你老的黄金来路．．．\n"NOR);
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
		"若不是在下帮你老辩解，你老的钱就全都充公了．．．\n"NOR);
    }
    return;
}

