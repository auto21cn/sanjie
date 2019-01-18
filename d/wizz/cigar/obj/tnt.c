#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "TNT炸弹" NOR , ({ "tnt"}) );
        set("long", "这是一颗烈性十足的炸弹，专门用于炸(zha)隐身中的巫师现形。\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 0);
              }
        setup();
}

void init()
{
 add_action("do_zha","zha");
}

int do_zha(string arg)
{
string old_status, new_status;
int my_level, ob_level, level;
 object ob,me=this_player();
 if(!arg) return notify_fail("你想炸谁。\n");
 if( wiz_level(me) < wiz_level(new_status) ) return notify_fail("竟然炸你上司。想抄尤鱼啊。\n");
 if(!ob=find_player(arg)) return notify_fail("你想炸谁。\n");
//  if( !wizardp(ob) ) return notify_fail("你只能炸巫师哦！\n");
//  if( !ob->query("env/invisibility") ) return notify_fail("难道你看不到吗？\n");

 message_vision(HIR"$N取出一颗TNT炸弹，往空中一抛，TNT炸弹象长了眼睛似的，往远处飞去...\n不一会儿，远处传来一声闷响。\n" NOR,  me );
 message("vision", HIR"忽然一颗TNT炸弹呼啸地往"+ob->name()+"这个方向飞来,轰的一声响，"+ob->name()+"被炸出了原形。\n"NOR,  environment(ob), ({ ob }) );

tell_object(ob,HIR "忽然一个TNT炸弹撞在你身上，爆炸了，逼得你现出了原形。\n原来是"+me->name()+"向你丢TNT炸弹:->。\n" NOR);
 ob->set("env/invisibility",0);
 destruct(this_object());
 return 1;
}
