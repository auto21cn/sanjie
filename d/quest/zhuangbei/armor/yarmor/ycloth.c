// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("cloth");
        set_name(HIY+name["name"]+NOR, name["id"]);                     
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 10000);
                set("armor_prop/armor", 110);
                if(random(20)>10)
                        set("armor_prop/spells", 30+random(25)); 
                        set("armor_prop/dodge", 30+random(25)); 
                if(random(10)>6)
                        add("armor_prop/karma",3);
                set("armor_prop/parry", -10);
                set("level_quest", 50);
        }
        set("inset_hole",2);
        if(this_object()->query("inset_hole"))
                str += "һ���������ۣ�װ���ȼ�50��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ���������ۣ�װ���ȼ�50��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("armor_prop/spells"))
                str += "װ����������"+this_object()->query("armor_prop/spells")+"�㷨����Ч�ȼ���\n";
        if(this_object()->query("armor_prop/dodge")) 
                str += "����"+this_object()->query("armor_prop/dodge")+"���ܡ�\n";
        if(this_object()->query("armor_prop/karma")) 
                str += "����"+this_object()->query("armor_prop/karma")+"�㸣Ե��\n";
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
        if(arg == ob->query("id") || arg == "cloth" ){
                if(me->query("level")<50){
                        write("��ĵȼ��������޷���������·���\n");
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
