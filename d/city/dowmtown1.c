inherit ROOM;
#include <ansi.h>
int do_drop(object me, object obj);
string money_str(int count);
void create()
{
 set("short","瓦砾场");
        set("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※※※ 据说下面就是传说中的异域入口了，没有一定的修为，最好还是不要乱闯哦 ※※※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG
        );
        set("exits", ([
                "up" : __DIR__"droproom",
               "down" :"/d/hellfire/gate",
        ]));
        set("objects", 
        ([ //sizeof() == 1
          "/d/city/npc/baobao" : 1,
           "/d/city/npc/nushen" : 1,
// 24            "/adm/npc/nushen" : 1,
           "/d/city/npc/shizhe" : 1,
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{
    add_action("do_stop", "bid");
    add_action("do_main", "drop");
}

int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(YEL"这里不准用这种命令。\n"NOR,who);
return 1;
}

int do_main(string arg)
{
   object me=this_player();
   object obj, *inv, obj2;
   int i, amount;
   string item;

        if(me->is_busy())
           return notify_fail("你正忙着呢．．．\n");
 
   if(!arg) return notify_fail("你要丢弃什么东西？\n");

   if(sscanf(arg, "%d %s", amount, item)==2) {
     if( !objectp(obj = present(item, me)) )
        return notify_fail("你身上没有这样东西。\n");
     if( !obj->query_amount() )
        return notify_fail( obj->name() + "不能被分开丢弃。\n");
     if( amount < 1 )
        return notify_fail("东西的数量至少是一个。\n");
     if( amount > obj->query_amount() )
        return notify_fail("你没有那么多的" + obj->name() + "。\n");
     else if( amount == (int)obj->query_amount() )
        return do_drop(me, obj);
     else {
        obj2 = new(base_name(obj));
        obj2->set_amount(amount);
        if(do_drop(me, obj2)) { // succeed to drop
            obj->set_amount( (int)obj->query_amount()-amount );
            return 1;
        }
        return 0;
     }
   }

   if(arg=="all") {
     inv = all_inventory(me);
     for(i=0; i<sizeof(inv); i++) {
        do_drop(me, inv[i]);
     }
     write("Ok.\n");
     return 1;
   }

   if(!objectp(obj = present(arg, me)))
     return notify_fail("你身上没有这样东西。\n");
   return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
   int count;
   object money;
   if(me->is_busy())
      return notify_fail("你正忙着呢．．．\n");
   if (obj->move(environment(me))) {
    if((obj->query_temp("d_mana"))>0) {
     if( obj->query_temp("is_living")==1 )
            message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
     else {
       message_vision( sprintf("$N丢下一%s$n。\n",   
         undefinedp(obj->query_temp("unit"))?
         "个":obj->query_temp("unit")
         ), me, obj );
     }
        } else {
     if( obj->is_character() )
            message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
     else {
  if (obj->query("id")=="thousand-cash" || obj->query("id")=="gold"
          || obj->query("id")=="silver" || obj->query("id")=="coin")
   { message_vision( sprintf("$N丢下一%s$n。\n",obj->query("unit")),me, obj );
 if(wizardp(me)) destruct(obj);}
else { message_vision( sprintf("$N将一%s$n扔进垃圾堆。\n",obj->query("unit")),me,obj);
     destruct(obj);
     }}
        }
       return 1;
       }
       return 0;
}
string money_str(int count)
{        
        string output;
        if (count / 10000) {
                output = chinese_number(count / 10000) + "两黄金";
                count %= 10000;
        }
        else
                output = "";
        if (count / 100) {
                output = output + chinese_number(count / 100) + "两白银";
                count %= 100;
        }
        if (count)
                return output + chinese_number(count) + "文铜板";
        return output;
}

// added by mudring valid pker.
int valid_leave(object me, string dir)
{
    if (pkerp(me) && dir == "down")
        return notify_fail("通缉期间不准进入寒冰地狱！\n");
    return ::valid_leave(me, dir);
}
