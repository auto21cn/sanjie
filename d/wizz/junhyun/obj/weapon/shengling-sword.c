//zhaoyaojian.c 
#include <ansi.h> 
#include <weapon.h> 
        
       inherit SWORD; 
        
       void create() 
       { 
           set_name( WHT "圣灵宝剑" NOR, ({ "shengling jian", "jian","sword" }) ); 
          set_weight(4000); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("value", 100000); 
      //              set("no_drop", "1"); 
                      set("material", "iron"); 
                      set("long", "据说是女娲的神物，以五彩补天石铸造，锋利无比。\n"); 
                      set("wield_msg","$N默念心决，$n似有灵性般围绕在$N的身边。\n"); 
                      set("unwield_msg", "$N伸手一指，$n化作青光跳入鞘中。\n"); 
                                      set("no_sell",1); 
                                      set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 
                                      set("no_give","宝剑不能易主!\n"); 
                      } 
              init_sword(120); 
              setup(); 
      } 
