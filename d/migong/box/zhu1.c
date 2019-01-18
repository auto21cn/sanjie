#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"力量珠"NOR, ({ "jobzhu1" }) );
    set_weight(1);
    set("no_put", 1);
    set("value", 0);
    if( clonep() )
    set_default_object(__FILE__);
    else {
               
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 0);
            set("unit", "颗");
            set("material", "paper");
            set("long", "龙窟神珠之一,若是能找到所有神珠就能(hebing)。\n");
          }

    setup();
}

void init()
{
    add_action("do_eat", "eat");
    add_action("do_hebing","hebing");
}

int do_hebing()
{
        object me,ob;
        me = this_player();
    if (!(ob = present("jobzhu2", me)) 
    || !(ob = present("jobzhu3", me))
    || !(ob = present("jobzhu4", me))
    || !(ob = present("jobzhu5", me))
    || !(ob = present("jobzhu6", me))
    )
        tell_object(me,"神珠好象没有凑齐。\n");
  else{
        if( ob->query("ownmake"))
        return notify_fail("这里面似乎有假货吧。\n");
        if(userp(ob))
        return notify_fail("这里面似乎有假货吧。\n");
        if( ob->is_character() || ob->is_corpse() )
        return notify_fail("这里面似乎有假货吧。\n");
        message_vision(MAG"$N把从怀中拿出的别的几颗神珠,和手中的力量珠合成了一颗无敌珠并吃了下去。\n", me);
        me->add("combat_exp", 10000);
        me->add("daoxing",10000);
        me->add("potential",1000);        
        
        destruct(present("jobzhu2",me));
        destruct(present("jobzhu3",me));
        destruct(present("jobzhu4",me));
        destruct(present("jobzhu5",me));
        destruct(present("jobzhu6",me));
        destruct(this_object());}
        return 1;
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        me->add("combat_exp", 800);
        me->add("daoxing",800);
        me->add("potential",150);        
        
        message_vision(HIG "$N把力量珠吃了下去，只觉得全身舒服了不少！\n" NOR, me);
        
        destruct(this_object());
        return 1;
}

