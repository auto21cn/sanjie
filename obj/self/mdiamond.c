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
	set_name(HIW "神之钻石" NOR, ({ "magic diamond" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "一颗焕发着奇异的光彩的钻石，"
                    "给人以不同寻常的感觉。\n" NOR);
                set("value", 200000);
		set("unit", "颗");
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 150);
	}
        setup();
}
