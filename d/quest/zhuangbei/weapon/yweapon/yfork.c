#include <weapon.h>
inherit FORK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("fork");
        set_name(HIY+name["name"]+NOR, name["id"]);                  
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
                if(random(20)>10)
                        set("weapon_prop/force",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/parry",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/strength",3);
                if(random(20)>15)
                        set("weapon_prop/spells", 10+random(10));
                if(random(10)>7)
                        add("weapon_prop/dodge",10+random(10));
                set("level_quest",50);
        }
        set("inset_hole",2);
        init_fork(100+random(60));
        if(this_object()->query("inset_hole"))
                str += "一柄锋利的钢叉，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一柄锋利的钢叉，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/force"))
                str += "装备它可增加"+this_object()->query("weapon_prop/force")+"点内功有效等级。\n";
        if(this_object()->query("weapon_prop/parry")) 
                str += "增加"+this_object()->query("weapon_prop/parry")+"点防御。\n";
        if(this_object()->query("weapon_prop/strength")) 
                str += "增加"+this_object()->query("weapon_prop/strength")+"点臂力。\n";
        if(this_object()->query("weapon_prop/spells")) 
                str += "增加"+this_object()->query("weapon_prop/spells")+"点法术有效等级。\n";
        if(this_object()->query("weapon_prop/dodge")) 
                str += "增加"+this_object()->query("weapon_prop/dodge")+"点躲避。\n";
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
        if(arg == ob->query("id") || arg == "fork" ){
                if(me->query("level")<50){
                        write("你的等级不够，无法装备这件兵器。\n");
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
