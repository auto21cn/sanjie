#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY"金币"NOR, ({"jinbi", "jinbi_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "jinbi");
               set("long", HIY"一枚蛇口仙侣情缘的硬币，正面是阿修伟大的头像，反面是全体巫师的全家福。\n"NOR);
                set("unit", "堆");
               set("base_value", 200000);
                set("base_unit", "枚");
		set("base_weight", 3);
	}
	set_amount(1);
}

