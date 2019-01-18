// ring.c 订婚戒指

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC "订婚戒指" NOR, ({ "diamand ring", "diamand", "ring" }));
       	set("long", "这是作乐送给雪儿的订婚戒指，衬着她纤纤柔荑，益发光彩照人。\n");
	set("weight", 20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("value", 10000);
		set("material", "钻石");
		set("armor_prop/unarmed", 2);
                set("armor_prop/armor", 1);
                set("armor_prop/spells", 2);
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
		//set("no_get", "嘿嘿，做梦吧! \n");
		set("no_sell", "这个东西不能卖。\n");
		set("wear_msg", "$N轻轻地把一个$n戴在右手无名指上。\n");
		set("unwield_msg", "$N轻轻地把$n从右手无名指上除了下来。\n");

	}
	setup();
}	
