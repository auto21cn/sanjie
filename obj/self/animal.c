// animal.c 独门坐骑

#include <ansi.h>

inherit ITEM;

void set_up();

void create()
{
        set_name("我的坐骑", ({ "my animal", "animal" }) );
        set( "no_get", 1 );
        set( "no_put", 1 );
        set( "no_drop", 1 );
        set("horse_prop/max_life", 1);
        set("horse_prop/life", 1);
        set_max_encumbrance(10000);
        set("prep", "on");
        set_weight( 0 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹独门坐骑。\n");
                set("value", 0);
        };
		set_up();
}

void set_up()
{
        object me;
        int n;

        me = this_player();

        // 临时加入对付小康的东东，以后删除。
        if( stringp(me->query("animal/name")) )
                me->set("animal/name", replace_string( me->query("animal/name"),
                        "张三丰", me->query("name") ) );

        if( stringp(me->query("animal/name")) )
                set("name", me->query("animal/name"));
        if( stringp(me->query("animal/unit")) )
                set("unit", me->query("animal/unit"));
        if( stringp(me->query("animal/ride_msg")) )
                set("ride_msg", me->query("animal/ride_msg") );
        else    delete("ride_msg");
        if( stringp(me->query("animal/unride_msg")) )
                set("unride_msg", me->query("animal/unride_msg") );
        else delete("unride_msg");
        if( n = me->query("animal/max_life") ) {        // 重新设置最大生命值及当前生命值，要小心。
                set("horse_prop/max_life", n);
                set("horse_prop/life", me->query("animal/life"));
                set_max_encumbrance(10000 * n);
                // set_weight(-10000 * n);
        }
        set( "long", "「" + this_object()->name() + "」。\n" );
}

int is_container() { return 1; }

void dest() { destruct(this_object()); }

void owner_is_killed() { call_out("dest",1); }
