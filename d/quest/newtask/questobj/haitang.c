#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���Ǻ���", ({ "qixing haitang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("long", "һ�����Ǻ���\n");
          }

    setup();
}
