/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Created by waiwai@2003/01/25 另类
//设定这个的意义在于可扩展装备的意义范围
//例如象护身符一类的东西可以在与装备不冲突属性的
//情况下又具有一定的特殊的属性。在实际的应用中
//其作用意义是很大的。在一般情况下请勿在此类
//物件上设任何的防御数值。

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	//没有任何参数的则默然为系统限制值
	if( !query("armor_prop/armor") )
		set("armor_prop/armor",PROP_OTHERS);

	//设定系统限制默认值有效
	if( !query("combine") && query("LIMIT")) {
	if( query("armor_prop/armor") > PROP_OTHERS)
		set("armor_prop/armor",PROP_OTHERS);
	}

	//设定最大破损默认值
	if( !query("armor/max_armor") )
		set("armor/max_armor",query("armor_prop/armor"));
	else
		set("armor_prop/armor",query("armor/max_armor"));

	set("armor_type", TYPE_OTHERS);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
