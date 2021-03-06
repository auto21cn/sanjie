// dragon-ring.c
// Modified By Longer

#include <armor.h>
#include <ansi.h>

inherit FINGER;
inherit F_UNIQUE;

void init();
void create()
{
        set_name(RED"盘龙"MAG"紫云戒" NOR, ({ "ziyun ring", "ring", "jiezhi" }) );
        set("long", "一枚用天山紫云石雕刻成盘龙形状的戒指。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/intelligence", 15);
                set("value", 200);
        }
        setup();
}
// 加上时间限制
void init()
{
        if( (int)this_object()->query("created") != 1 )
        {
                this_object()->set("created", 1);
                remove_call_out ("destroy_ring");
                call_out ("destroy_ring", 18000);//5 hours

        }
}

void destroy_ring()
{
        message_vision(HIC"天上传来阵阵雷声，"NOR + (string)this_object()->query("name") + HIY"化作一条金龙，直上云霄而去。\n"NOR, environment(this_object()));
        destruct(this_object());
}

