// Created by aeddy@2002/12/05

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLINK HIW "月亮" NOR, ({ "moon", "yueliang" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "天空的月亮，有众多星星的光芒辉映而成。\n" NOR);
               set("value", 10000);
		set("can_auction", 1);
		 set("unit", "颗");
	}
        setup();
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, item;

	me=this_player();
	a=this_object();

	if( !wizardp(me) && userp(me) ) {
       if(!environment(me)->query("cold"))
             return notify_fail("此地灵气不够，无法合并物品。\n");

	if( (int)me->query("force") < (int)me->query("max_force") )
		return notify_fail("你的内力不足，很难将物品合并。\n");

	if( (int)me->query("mana") < (int)me->query("max_mana") )
		return notify_fail("你的法力不足以支持合并物品。\n");
       }

       if ( !(b=present("winter snow",me)))
                return notify_fail(CYN"你尚缺 "HIW"晶莹雪花 "NOR CYN"无法合成土灵珠。\n"NOR);

       if ( !(c=present("five-needle",me)))
                return notify_fail(CYN"你尚缺 "HIM"五行之针 "NOR CYN"无法合成土灵珠。\n"NOR);

	if( item=new("/obj/self/item/tuzhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("你的负重过高不能合并物品。\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N将手中的 "HIW"晶莹雪花 "HIM"五行之针"NOR WHT
	"与"HIW"月亮"NOR WHT"摆在一起，只见几道耀眼霞光掠过,竟然合并出一颗土灵珠。\n"NOR,me);

        message("channel:rumor",
	WHT"┋"HIR"小道消息"NOR WHT"┋听说："+log_id(me)+"合成了"HIY"土灵珠"NOR WHT"了！\n"NOR,users() );

	destruct(a);
	}
	return 1;
}


