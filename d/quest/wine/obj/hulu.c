// created by kuku@sjsh  2002/12
// /d/quest/wine/obj/hulu.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"金刚葫芦"NOR, ({"jingang hulu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个金刚葫芦，看上去和普通的葫芦没什么两样。\n");
                set("unit", "个");
                set("unique", 1);
                set("value", 0);
                set("no_sell",1);
                set("no_put",1);
                set("no_give",1);
                set("no_get",1);
        }
        setup();
}

void init()
{
        object me = this_object();
        object who = this_player();
        object where = environment();
        if (! me->query("my_owner") && interactive (who))
                me->set("my_owner",who->query("id"));
        if (userp(where)){
                if (me->query("owned")){
                        if (me->query("owned")!=where->query("id")){
                                call_out("destruct_me",1,where,me);
                        }
                }
                else{
                        me->set("owned",where->query("id"));
                }
        }
        add_action("do_zuo","zuo");
}

int do_zuo(string arg)
{
        
        object me,a,b,c,d,e,jiuyin;
        me=this_player();
        a=present("xian jiu",me);
        b=present("mi jiu",me);
        c=present("gaoliang jiu",me);
        d=present("huang jiu",me);
        e=present("baihua wan",me);
 
        if(!arg) return 0;
        if(arg!="jiu yin") return 0;

        if(!me->query("wine/start")||!present("jiu pai",me) )
                return notify_fail("哪偷来这么多东西？这样可不好喔。");

        if( (int)me->query("force") < 2000)
                return notify_fail("你的内力不足，做不出酒引。\n");
        if( (int)me->query("mana") < 2000)
                return notify_fail("你的法力不足，做不出酒引。\n");
        if((int)me->query("level")<40)
                return notify_fail("你的等级不够，不能做出你想要的东西。\n");
        if(!me->query("wine/gaoliang")||!me->query("wine/mijiu")||!me->query("wine/huangjiu"))
                return notify_fail("这些酒是你自己得到的吗？\n");

         if ( !a)
                return notify_fail("做酒引的原料还没找齐吧？\n");
         if ( !b)
                return notify_fail("做酒引的原料还没找齐吧？\n");
         if ( !c)
                return notify_fail("做酒引的原料还没找齐吧？\n");
         if ( !d)
                return notify_fail("做酒引的原料还没找齐吧？\n");
         if ( !e)
                return notify_fail("做酒引的原料还没找齐吧？\n");
         
         if( jiuyin=new("/d/quest/wine/obj/jiuyin")){
                 jiuyin->move(me);
                 message_vision(HIW"$N"HIG"将身上的"+a->query("name")+"、"+b->query("name")+"、"+c->query("name")+"、"+d->query("name")+"和"+e->query("name")+"放到"+this_object()->query("name")+"里，摇了摇，待充分混合后，做成了一份酒引。\n"NOR,me);
         }
         destruct(b);
         destruct(c);
         destruct(d);
         destruct(e);
         destruct(a);
         destruct(this_object());
         return 1;
}

void destruct_me(object where, object me)
{
         message_vision("千面怪鬼鬼祟祟地拿起$n撒脚就跑,快追!\n",where,me);
         destruct (me);
}
