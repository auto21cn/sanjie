 // combine.c  
  
#include <ansi.h>  
  
inherit F_CLEAN_UP;  
#define BAOSHI "/d/quest/baoshi/baoshi" 
  
 
 
int main(object me, string arg)  
{  
                        
        object *ob_list, *ilist;                // 合并的所有物品  
                        
        object obj,base;                     // 生成的物品  
        int i,k,j;  
  
        if (! arg )  
                return notify_fail("你要合并什么物品？\n");  
 
        if ( arg=="baoshi" )  
                return notify_fail("你要合并什么宝石？\n");   
        if (me->is_busy())  
                return notify_fail("先忙完了你的事情再做这件事情吧！\n");  
  
        if (me->is_fighting())  
                return notify_fail("你现在正在打架，没时间做这些事情。\n"); 
        if (!( base=present (arg,me))) 
                return notify_fail("你身上没有这个物品。\n"); 
        if (!base->query("b_lvl")) 
                return notify_fail("你身上这个物品不能融合。\n"); 
      i=base->query("b_lvl");
        if ( i > 28) 
                return notify_fail("你身上这个物品已经不能融合。\n"); 
        if (me->query("max_sen") < 1000)  
                return notify_fail("你现在的精力修为有限，无"  
                                   "法施展如此艰深的法力。\n");  
           
        if (me->query("sen") < 1000)  
                return notify_fail("你现在精神不济，无法施展法力。\n");  
       if(arg=="hong baoshi")
           i=1;
       ilist = all_inventory(me); 
        if (!ilist) 
                return notify_fail("你身上没有任何物品。\n"); 
       k=0; 
// 
//       i=base->query("b_lvl"); 
       j = sizeof(ilist); 
        while (j--) { 
        //      object ob =; 
                if( ilist[j]->query("b_lvl")!=i) 
                { 
                          continue; 
                        } 
             
              k++; 
        } 
        if(k <=2) 
         return notify_fail("你要合并的宝石不够三个！。\n");  
        obj=new(BAOSHI); 
       i=i+7;
        BAOSHI->changename(obj,i);  
        k=3; 
        ilist = all_inventory(me); 
         for (j = 0; j<3; j++) {
             base=present (arg,me);
                      destruct(base);
                        } 
             
               
         
        message_vision(HIM "$N" HIM "将一些物品摆"  
                       "在一起，默运神通使它们变化。\n" NOR, me);  
        if(obj->move(me)){ 
        message_vision(HIW "数道光芒闪过，似乎发生了"  
                                       "不同寻常的事情。\n" NOR, me);  
        tell_object(me, HIC "你利用手头的物品创造了" + obj->name() +  
                                        HIC "！\n" NOR);  
                                }else 
                                { 
                    message_vision(HIG "过了半天，似乎没有任何变化，$N"  
                       HIG "一脸悻悻。\n", me);    }             
        me->start_busy(4);  
        me->add("sen", -500);  
          return 1;  
        
}  
  
int help(object me)  
{  
write(@HELP  
指令格式 : combins <特殊物品>  
  
这个指令可以让你将某些特殊物品合并成一种新的物品，哪些才能合  
并？这就要靠你去发掘了。每次合并都会损失一些精力的上限。如果  
要合并的几个物品名字相同，则需要指明他们的序号，比如有三个钻  
石碎片，如果要合一，则需要输入：  
  
combins xxx baoshi 
  
HELP  
    );  
    return 1;  
}  
  
  

