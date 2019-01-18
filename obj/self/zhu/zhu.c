#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
       set_name(HIR "夜明珠" NOR, ({"ye mingzhu", "zhu"}));
       set_weight(100);
	  if( clonep() )
	    set_default_object(__FILE__);
	  else {
       set("unit", "颗");
       set("long", "一颗" HIR "夜明珠" NOR "，黑夜变白天的宝贝。\n");
       set("value", 10000);
       set("no_steal",1);
       set("no_drop", "如此宝物再世难求啊。\n");
       set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
       set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
       set("wear_msg","$N戴上一颗夜明珠，周围的景色顿时一亮。\n");
       set("unequip_msg", "$N将夜明珠取了下来，四周也暗了下来。\n");
       set("armor_prop/armor", 4);
       set("armor_prop/courage", 4);
       }
       setup();
} 


