//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(CYN"使书"NOR, ({"shi shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一封两国使节来往的书信。\n");
                set("unit", "封");
                 set("owner_name","大使");
               set("owner_id","da shi");
        }
}

