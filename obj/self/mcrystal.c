/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIM "神之水晶" NOR, ({ "magic crystal" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "一块闪烁这奇异光芒的粉色水晶，"
                    "让人感到一阵阵的心悸。\n" NOR);
                set("value", 200000);
		set("unit", "块");
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 150);
	}
        setup();
}
