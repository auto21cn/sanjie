//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIW "白字天书" NOR, ({"baizi tianshu", "tianshu"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "只有袁守诚看得懂的天书。\n");
                set("unit", "本");
                set("owner_name","袁守诚");
               set("owner_id","yuan shoucheng");
        }
}

