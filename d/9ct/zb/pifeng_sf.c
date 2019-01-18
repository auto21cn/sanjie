//飞羽披风 by koker
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
int do_wear(string arg);
void create()
{
  set_name(HIY"神风披风"NOR, ({"shenfeng pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "相传这件亮色的披风是精华台出的宝物。\n");
    set("material", "leather");
    set("unit", "件");
             set("value", 12000);
    set("armor_prop/armor", 10);
    set("armor_prop/spells", 5);//装备等级是1-10的，此处是5；11-20的，此处是10
    set ("armor_prop/force", 5);//20以上等级的装备可以是15-50
    set("armor_prop/parry", 10);
    set("level",10);
  }
  setup();
}

int init()
{
        add_action("do_wear","wear");
        return 1;
}

int do_wear (string arg)
{
   object me=this_object(),who=this_player();
  
     if(who->query("level") <20)
{
   message_vision("$n需要等级是20级以上的玩家才能佩带，$N还是先去升级你的等级吧。\n",who,me); 
   return 1;
}
   return 0;
}
