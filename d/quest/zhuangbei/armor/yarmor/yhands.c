// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit HANDS;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("hands");
        set_name(HIY+name["name"]+NOR, name["id"]);                     
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("material", "gold");
                set("value", 10000);
                set("no_zm",1);
                set("armor_prop/armor", 50);
                if(random(20)>10)
                        set("armor_prop/dodge",20+random(20));
                if(random(10)>6)
                        add("armor_prop/composure",3);
                set("level_quest", 50);
        }
        set("inset_hole",2);
        if(this_object()->query("inset_hole"))
                str += "一对护掌，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一对护掌，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("armor_prop/dodge")) 
                str += "增加"+this_object()->query("armor_prop/dodge")+"点躲避。\n";
        if(this_object()->query("armor_prop/composure")) 
                str += "增加"+this_object()->query("armor_prop/composure")+"点定力。\n";
        set("long",str);
        setup();
}

void init()
{
        add_action("do_wear","wear");
}

int do_wear(string arg) 
{  
        object ob = this_object();
        object me = this_player();
        if(arg == ob->query("id") || arg == "hands" ){
                if(me->query("level")<50){
                        write("你的等级不够，无法戴上这对护掌。\n");
                        return 1;
                }  
        }   
        return 0;  
}   

int query_autoload() 
{ 
        object me = this_player();
        if(me->query("level") >= this_object()->query("level_quest"))
        return 1; 
}  

