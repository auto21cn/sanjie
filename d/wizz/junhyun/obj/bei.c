//三界神话英雄纪念碑
//by junhyun@SK

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIW "三界神纪念碑" NOR , ({ "jinian bei","bei" }) );
   set_weight(200000);
   set("long", @LONG

三界英雄纪念碑 这上面记载着开创三界的人们的名字：

               ☆东方财神(helpler)☆
               ☆风    铃(mudring)☆
               ☆阿    修( cigar )☆
               ☆花    哥( koker )☆
               ☆江    安( sklll )☆

希望你也能成为着上面的一员，多加努力哦
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}


