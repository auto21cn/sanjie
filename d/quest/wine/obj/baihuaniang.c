//created by kuku@sjsh 2002/12

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIM"百花酿"NOR , ({"baihua niang", "wine"}));
        set_weight(500);
        if (clonep())
           set_default_object(__FILE__);
         else {
           set("unit", "瓶");
           set("long","这就是酒谷那位著名的制酒师“酒鬼”做的酒。\n");
           set("value", 0);
           set("no_sell", 1);
       }
  setup();
}

void init()
{
    call_out("destruct_me",2);
}

void destruct_me()
{
         destruct(this_object());
}

