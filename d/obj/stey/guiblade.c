// blade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name( HIC "��������" NOR, ({ "gui dao", "dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("value", 100000);
		set("material", "iron");
                set("long", "���Ǳ������ظ��õĹ���������һ����������ɭɭ������ˡ�\n");
                set("wield_msg", "$N���һ����ɭɭ��$n�������У���Цһ�����٣���\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
//                                set("no_get","�ֲ�����ģ���ʲôѽ��\n");
}
        init_blade(105);
        setup();
}
