// nietie-kuang.c ������ʯ  
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;  

void create() 
{
        set_name(WHT"������ʯ"NOR,({"nietie kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
                set("no_put",1);
                set("long", "����һ����ص�������ʯ��\n");
        }
        setup();
}
