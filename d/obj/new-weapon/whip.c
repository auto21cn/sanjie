#include <ansi.h>
#include <weapon.h>

inherit WHIP;
#include "/std/weapon/newwwd.c"; 

void create()
{
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","一条长约十尺，妖神之争神哭鬼嚎的神鞭。\n");
                set("unit", "条");
                set("value", 100000);
                set("wield_msg",
"只听「啪」的一闪电光，$N的手中闪出一条神哭鬼嚎的神鞭．\n");
                set("unwield_msg", "$N把手中$n缠回腰间．\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
        }
        init_whip(105);
       updatename("whip"); 
        setup();
}

