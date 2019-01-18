// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"狼的战袍"NOR, ({"zhan pao", "cloth", "pao" }) );
        set("long", HIY"这是小蔓为她的丈夫亲手缝制的战袍，上面精心的刺绣着一只奔跑的野狼。\n"NOR);
	set_weight(0);
              if( clonep() ) 
                      set_default_object(__FILE__); 
        else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);

	}
	setup();
}
      int init () 
      { 
        add_action ("do_wear", "wear"); 
        add_action ("do_remove", "remove"); 
        return 1; 
      } 

      int do_wear (string arg) 
      { 
        object me = this_player(); 
        object cloth = this_object(); 
        string name = cloth->query("name"); 
        string msg; 

        if (arg != "pao" &&  arg != "cloth" ) 
          return 0; 
        msg = "$N披上一件"+name+"，不禁想起在家中等待他回去的妻子。\n";  
        cloth->set("wear_msg",msg); 
        return 0; 
      } 

      int do_remove (string arg) 
      { 
        object me = this_player(); 
        object cloth = this_object(); 
        string name = cloth->query("name"); 
        string msg; 

        if (arg != "cloth" && arg != "pao") 
          return 0; 

        msg = "$N将"+name+"解下，犀利的眼眸中露出一丝柔情。\n";  
        cloth->set("unequip_msg",msg); 
        return 0; 
      } 

int query_autoload() { return 1; } 
