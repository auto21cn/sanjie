// by cigar 
// quduwan.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "去毒丸" NOR, ({"qudu wan", "wan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 500000);
                set("no_sell", "这种罕见的药丸不是随便可以买卖的!\n");
                set("unit", "颗");
                       set("long", HIG"这是一颗太上老君炼制的解毒极品药丸。\n"NOR);
                set("drug_type", "补品");
//                        set ("ymdh",1);
        }
  
        set("is_monitored",1);
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 
        if (!id(arg)) return notify_fail("你要吃什么？\n");

        me->set("food", (int)me->max_food_capacity());
            me->set("water",   (int)me->max_water_capacity());
           me->set("eff_sen", (int)me->query("max_sen"));
           me->set("eff_kee", (int)me->query("max_kee"));

        if((int)me->query("max_force")<10*(int)me->query_skill("force"))

                  me->add("max_force",10);
        if((int)me->query("max_mana")<10*(int)me->query_skill("spells"))
                   me->add("max_mana",10);

          me->clear_condition();
        message_vision(HIW"$N把去毒丸往嘴里一丢，忽然一阵战栗，脚底冒出丝丝白气。\n" NOR, me);  

        destruct(this_object());
        return 1;
}

