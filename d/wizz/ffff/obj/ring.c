#include <ansi.h>
inherit F_UNIQUE;
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(RED"魔"+YEL"戒"NOR, ({ "mo jie", "jie", "ring" }));
        set("weight", 10); 
        set("long",HIM"这是一枚注满神奇的力量的信物，上面刻着"+HIR"星●雪"+HIM"2个字。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚"); 
                set("no_drop", "这么难得的戒指还是留着吧。\n"); 
                set("no_give","怎么着，想干什么啊你？？？\n"); 
                set("no_get","当了？小心索荣杀了你啊！\n");
                set("value", 100000);
                set("material", "gold");
                set("no_sell", 1);
                set("monitord", 1);
       if(!wizardp(this_player())) set("no_give", 1);
                set("armor_prop/armor", 20);
                set("armor_prop/intelligence", 15);
                set("armor_prop/personality", 25);
        }
        setup();
}

int query_autoload() { return 1; }


