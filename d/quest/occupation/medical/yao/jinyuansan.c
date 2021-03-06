// jinyuansan.c 金元散
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"金元散"NOR, ({ "jinyuan san","san" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","一小瓶灵药，可解奇毒。\n");
                set("unit", "瓶");
                set("value", 2000);
                set("drug_type", "补品");
        }
        set("is_monitored",1);
        setup();                        
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_drop","drop");
}

int do_eat(string arg)
{
        object ob;
        ob=this_player();       
        
        if (arg!="san" && arg!="jinyuan san")
                return 0;
        if (arg!="san" ) return 0;

        if((int)ob->query_condition("hot_poison"))
                ob->clear_condition("hot_poison");
        if((int)ob->query_condition("xx_poison"))
                ob->clear_condition("xx_poison");

        write(HIB+"你拿出一瓶金元散，倒入口中，不消片刻，身体里的奇毒就被祛除干净了。\n"NOR);

        message("vision", HIB + ob->name() + 
"拿出一瓶金元散，倒入口中，不消片刻，身体里的奇毒就被祛除干净了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "jinyun san" || arg == "san"){
                message_vision("好可惜呀，这么珍贵的药就这样被"+me->query("name")+"随手扔掉了，"+ob->query("name")+"转眼间就消失的无影无踪。\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
