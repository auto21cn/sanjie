//make.c

#include <ansi.h>

void done(object me);
int main(object me, string str)
{
/*
        object ob;
        int lv;
        lv=me->query_skill("medical",1);

        seteuid(getuid());

        if( me->is_busy() )
        return notify_fail("你正忙着呢。\n");

        if( !arg )
        return notify_fail("你要制什么药？\n");

        if( me->is_fighting() )
        return notify_fail("你正在战斗，制什么药啊？\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("你正忙着呢，没时间制药。\n");

     switch (arg)
      {
      case "jinchuang":
        if( ! present("tian qi", me) || ! present("gou gu", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 1 )
        return notify_fail("你的医术不足制出金疮药。\n");
done(me);
        ob=new("/obj/jineng/medical/jinchuang.c");
        ob->move(me);
        me->start_busy(3);
        break;

        default:   notify_fail("你没有能力制这种药。\n");
        
*/
object ob1,ob2,ob3;
string st1,st2;
if (!str || str=="")  
return notify_fail ("你想合并什么呀\n");
if (sscanf( str,"%s and %s",st1,st2)!=2 )
return notify_fail ("make <物品> and <物品>\n");
if( !objectp(ob1 = present(st1,this_player())) ) 
return notify_fail("你没有 "+st1+" 这样物品.\n");
if( !objectp(ob2 = present(st2,this_player())) ) 
return notify_fail("你没有 "+st2+" 这样物品.\n");
  if( (!ob1->query("food_remaining")) && (!ob2->query("armor_prop")))
return notify_fail("你的物品不能合并。\n"); 
if ((!ob1->query("armor_prop")) || (!ob2->query("food_remaining")))
return notify_fail("你的物品不能合并。\n"); 
if( ob3=new("/d/qujing/tianzhu/obj/fen.c")){
destruct(ob1); 
destruct(ob2); 
ob3->move(this_player());
message_vision(HIW "$N物品练成，一看是筋骨粉\n" NOR,this_player()); 

        }

        return 1;
}


void done(object me)
{
        int i;
        object *inv; 
               inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("done"))
                        destruct(inv[i]);
                }
message_vision( HIC "只见$N驱真气于药材之上，不多会药材便消失了。\n" NOR,me);
                me->start_busy(6);
return;
}

