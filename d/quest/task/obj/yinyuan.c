//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIW "姻缘簿" NOR, ({"yinyuan bo", "book"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本记载天上地下所有姻缘的书。\n");
                set("unit", "本");
                set("owner_name","月下老人");
               set("owner_id","yuexia laoren");
        }
}

