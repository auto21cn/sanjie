// wineskin.c  �ƴ�

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�ൺ"+YEL+"ơ��"NOR, ({"pijiu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ൺơ�ơ�\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "ơ��",
                "remaining": 15,
                "drunk_supply": 6,
        ]));
}


