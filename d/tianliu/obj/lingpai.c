
#include <ansi.h>

inherit ITEM;

void create()
{
set_name(HIW"天流令"NOR, ({ "tianliu ling" }));
  set_weight(1000);
set("long", "这是可以让你进入天流山的令牌。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

