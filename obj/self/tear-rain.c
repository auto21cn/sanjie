//Created by waiwai@2001/03/23
//��ɫ����(tear-rain)
// [1;31m���ļ���ֹ���ĺ��ƶ�[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "��ɫ����" NOR, ({ "tear rain", "tear", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɬ�Ļ�ɫ���ꡣ\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropʱ��ʧ��־
		set("material", "water");//ˮ�������־
    };
	// dropʱ���ض������Ϣ
	set_temp("drop_msg", this_object()->query("name")+CYN" �����ţ���ʧ�ڿ����в����ˡ�����\n"NOR);

	setup();
}
