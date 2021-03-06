// jiuhua.c 九花玉露丸
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"九花玉露丸"NOR, ({ "jiuhua","wan" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","此药用珍异药材，以清晨九种花瓣上的露水调制而成，外呈朱红色，清香袭人，服后补神健体，延年益寿。\n");
                set("unit", "粒");
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
        
        if (arg!="wan" && arg!="jiuhua wan")
                return 0;
        if (arg!="wan" ) return 0;
              
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("food",(int)ob->max_food_capacity());
        ob->set("water",(int)ob->max_water_capacity());

        write(RED+"你拿出一粒九花玉露丸，放入口中，吞了下去，顿时有一种飘飘欲仙的感觉，身上病痛、疲劳似乎一下子都消失了。\n"NOR);

        message("vision", RED + ob->name() + 
"拿出一粒九花玉露丸，放入口中，吞了下去，顿时有一种飘飘欲仙
的感觉，身上病痛、疲劳似乎一下子都消失了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "jiuhua wan" || arg == "wan"){
                message_vision("好可惜呀，这么珍贵的药就这样被"+me->query("name")+"随手扔掉了，"+ob->query("name")+"转眼间就消失的无影无踪。\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
