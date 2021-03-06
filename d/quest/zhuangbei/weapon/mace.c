#include <weapon.h>
inherit MACE;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("mace");
        set_name(HIB+name["name"]+NOR, name["id"]);        
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("level_quest", 5);
                set("wield_msg", "只见一道蓝光闪过，$N手里已经多了一柄$n！\n");
                set("unwield_msg", "$N收起了$n，四周光芒为之一暗！\n");                
                if(random(20)>10)
                        set("weapon_prop/spells",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/parry",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/strength",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_mace(40+random(60));
        if(this_object()->query("inset_hole"))
                str += "一柄闪闪发光的锏，显然是被人擦了又擦，装备等级5。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一柄闪闪发光的锏，显然是被人擦了又擦，装备等级5。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/spells"))
                str += "装备它可增加"+this_object()->query("weapon_prop/spells")+"点法术有效等级。\n";
        if(this_object()->query("weapon_prop/parry"))
                str += "装备它可增加"+this_object()->query("weapon_prop/parry")+"点招架。\n";
        if(this_object()->query("weapon_prop/strength"))
                str += "装备它可增加"+this_object()->query("weapon_prop/strength")+"点臂力。\n";
        set("long",str);
        setup();
}

void init()
{
        add_action("do_wield","wield");
}

int do_wield(string arg) 
{  
        object ob = this_object();
        object me = this_player();
        if(arg == ob->query("id") || arg == "mace" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法装备这件兵器。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
