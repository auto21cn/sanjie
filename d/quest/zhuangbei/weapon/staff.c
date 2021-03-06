#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("staff");
        set_name(HIB+name["name"]+NOR, name["id"]);         
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰后。\n");                
                if(random(20)>10)
                        set("weapon_prop/sen", 200+random(500));                
                if(random(10)<2)
                        add("weapon_prop/intelligence",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_staff(40+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "这是一根沉重的钢制的杖，打造的相当坚实，装备等级5。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "这是一根沉重的钢制的杖，打造的相当坚实，装备等级5。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/sen"))
                str += "装备它可增加"+this_object()->query("weapon_prop/sen")+"点精神。\n";
        if(this_object()->query("weapon_prop/intelligence"))
                str += "装备它可增加"+this_object()->query("weapon_prop/intelligence")+"点悟性。\n";
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
        if(arg == ob->query("id") || arg == "staff" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法装备这件兵器。\n");
                        return 1;
                }  
        }   
        return 0;  
}
