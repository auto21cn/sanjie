// jiudai.c  酒袋

inherit COMBINED_ITEM; 
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name("行军丹", ({"xingjun dan","dan"}));
set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
  set("long", "行军，长途征战之必备良药。\n");
 set("base_unit", "颗"); 
 set("unit", "些"); 
             set("value", 12000);
      set("no_put", 1);
      set("no_sell", 1);
      set("no_drop", 1);
	}
 set_amount(1); 
    setup(); 
}
int do_eat(string arg)
{
  object me = this_player();
 if (arg!="xingjun dan") return 0;
 me->set("eff_sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("mana", (int)me->query("max_mana")*2);
me->set("force", (int)me->query("max_force")*2);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
message_vision("$N吃下了一粒行军丹，顿感浑身筋骨舒展无比。\n", me);
 add_amount(-1); 
  return 1;
}
