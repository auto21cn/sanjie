// 千色朝霞 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR"千色朝霞"NOR, ({"qianse whip", "qiansezhaoxia","whip","zhaoxia"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","这是一条由红霞仙子用无数朝霞染色织就的彩带。\n");
                set("unit", "条");
              set("value", 12000); 
                set("no_give", 1);
                set("wield_msg", "$N左手轻扬，一条彩色绸带忽地甩了出来\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
		set("weapon_prop/courage", 5);
        }
   init_whip(110);
        setup();
}

