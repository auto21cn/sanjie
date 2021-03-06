// Created by aeddy@2003/05/05

#include <armor.h>

inherit FLOWER;

void create ()
{
	set_name(HIY "格桑花" NOR, ({ "kelsang flower", "kelsang", "flower" }));
	set_weight(100);
	set("long","色彩艳丽的"+query("name")+"。一种黄色的小花，毛茸茸的叶子，
摸起来挺好玩的，薄薄的花瓣，很娇嫩的样子。你真的很
难想象，它居然生长在4000米以上的高寒地区。长在那梦
一般的香格里拉的巴郎山4000米以上的坡上，在那片冰雪
的世界，每到6，7月份，满山遍野的开满了这种坚强的格
桑花，很是漂亮。值得留念，但千万不要采摘，一来是保
护脆弱的高山环境，二来是即使你挖了一株也无法养活，
它必须在高原上才能生存。我相信你的家一定不是在4000
米以上的地方。花如丽人，需要用心欣赏呵护，只要有心，
那美丽的格桑花定会在你的心中绽放不枯，永远娇艳。。。\n");
	set("unit", "朵");
	set("value", 1);
	set("female_only", 1);
	set("no_break", 1);
	set("armor_type", "flower");
	set("material", "flower");
	set("Fmaterial", "wood");
	set("no_sell", "这么美丽的格桑花你也要换钱吗？\n");
	set("no_drop", "仍掉了格桑花，就象仍掉了一个梦想，还是好好珍惜它吧。\n");
	set("no_give", "送掉了格桑花就是忘记了曾经给你的人的那一份情义。\n");
	set("no_get", "大自然是格桑花的生命地，采撷只能使它枯萎。\n");
	set("no_put", "格桑花需要绽放在你的面前，不要把它萎缩起来。\n");
	set("armor_prop/armor", 10);
	set("armor_prop/personality", 10);
	set("unequip_msg","$N将美丽的"+query("name")+"轻轻地摘下来……。\n");
	set("wear_msg", "$N将一朵美丽的"+query("name")+
	"戴在胸前，花芯中映出了$P那美丽的身影。\n" );
	setup();
}

