//Last modified by waiwai@2002/12/05

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLINK HIY "星星" NOR, ({ "star", "xingxing" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "从天空上摘下来一颗星星，这可不是用金钱来"
                            "衡量的，怎么也算是一番心意阿。\n" NOR);
               set("value", 1);
		set("can_auction", 1);
		 set("unit", "颗");
	}
        setup();
}
