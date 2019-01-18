inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIC "翡翠兰" NOR, ({"hua", "feicui"}));
        set("unit", "朵");
    set("long", "这是一朵千年难得一见的翡翠兰,据说能解百毒。\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    this_player()->set_temp("nopoison", 1);
    this_player()->set("eff_sen",this_player()->query("max_sen"));
    this_player()->set("sen",this_player()->query("max_sen"));
    this_player()->set("eff_kee",this_player()->query("max_kee"));
    this_player()->set("kee",this_player()->query("max_kee"));
    message_vision(HIG "$N只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！\n" NOR,this_player() );
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}

