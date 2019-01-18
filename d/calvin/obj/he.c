#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name(HIG"月"HIY"光"HIW"宝"HIM"盒"NOR, ({"yueguang baohe","he", "ling" }) );
     set_weight(100);
     set("long","这就是传说中的山洞老人留下的月光宝盒，据说有瞬间移动(move)的作用。\n");
                                                                                                             set("value", 2000);
     set("material", "steel");
     set("no_sell", "这么难得的宝物还是留着吧。\n");
     set("no_drop", "这么难得的宝物还是留着吧。\n");
//     set("no_get","开玩笑,这种难得的宝物是你一个常人能拿得了的?\n");
     set("unit", "只");
}


void init()
{
   add_action("do_move", "move");
}


int do_move()
{
    object me=this_player(); 
        object env=environment(me); 

   if(me->query("kee")<10)
             return notify_fail("你现在的状态怎么差,无法使用宝盒。\n");
   if(me->query("sen")<10)
             return notify_fail("你现在的状态怎么差,无法使用宝盒。\n");
  if(me->query_temp("zuochan"))
             return notify_fail("你现在正在坐禅,禅无二心。\n");
  if(me->query_temp("no_move"))
             return notify_fail("你现在被定住了,无法使用宝盒。\n");
            if( me->is_busy() ) 
                    return notify_fail("( 你上一个动作还没有完成，不能使用月光宝盒。)\n"); 
  if(me->query_temp("in_hell"))
             return notify_fail("这样就走人了，你的真身呢？鬼魂可不能在阳间到处跑！\n");

        if(environment(this_object())!= me)
                  {
             destruct(this_object());
                 return 1;}
  if (me->is_fighting() || me->is_busy())
     return notify_fail("打架中你还有哪只手有空去拿月光宝盒呢？\n");
        if (env->query("no_move") || env->query("hellfireroom"))
                return notify_fail("这里不准移动。\n");

      if (!newbiep(me) && me->query("mana")<200)
        return notify_fail("你的法力不够。\n");
  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"你刚要念咒语，突然发觉手中的月光宝盒正在逐渐融化，只有眼睁睁
看着它化为一阵白烟消失在空气中。\n"NOR);   
        call_out("dest", 1, this_object());
        return 1;
       }


//  if( !query("mark_place") ) return notify_fail("先用 mark 在目的地做上记号。\n");

       tell_room(environment(me),me->query("name")+"双眼微闭，嘴中念起时空穿梭咒："
                        "「波若波罗密乾坤大法，走！」\n"
                        "等你张开眼时,"+me->query("name")+"的身影已经消失在漫天风沙之中.\n"NOR,me);
 
       tell_object(me,HIY"你双眼微闭，嘴中念起时空穿梭咒："
                        "「波若波罗密乾坤大法，走！」\n"
                        "你的身影已经消失在漫天风沙之中.\n"NOR);
        me->move("/d/changan/bridge");
                message_vision(HIY"$N的身影突然出现在一阵狂风之中。\n"NOR, me);

       return 1;
}
void dest(object ob)
{
        destruct(this_object());
}


int query_autoload() { return 1; } 
