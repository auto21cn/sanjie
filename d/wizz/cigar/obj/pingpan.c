// 巧克力 by Cigar

#include <ansi.h>

inherit ITEM;

void init();
void eat();
void create()
{
  set_name(HIY"桔子"+HIR"荔枝"+HIG"小拼盘"NOR , ({"pin pan","pan"}));
        set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "盘");
    set("long", "以昆仑山玉女峰顶的香桔、雪莲和昆仑山的千年冰荔枝制成，对精神大有裨益。\n");
    set("value", 10000);
set("no_sell",1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
        set("remaining", 5);
        set("food_supply", 100);
    set("drug_type", "补品");
  }
  setup();
}

void init()
{
        add_action("do_chi", "eat");
}


int do_chi(string arg)
{

        int heal, recover, sen, e_sen, m_sen,remaining;
        
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("慢慢吃，馋猫猫。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("都吃饱了还吃啊？小馋猫...\n");

    this_player()->add("food", (int)query("food_supply"));

    m_sen = (int)this_player()->query("max_sen");
        heal = (int)this_player()->query_con();
    e_sen = (int)this_player()->query("eff_sen");
        
    if ( e_sen < m_sen )
        {       
                if ( (e_sen + heal) >= m_sen )
                {
                        this_player()->set("eff_sen", m_sen);
                } else
                {       
                        this_player()->add("eff_sen", heal);
                }       
        } 

    e_sen = (int)this_player()->query("eff_sen");
    sen = (int)this_player()->query("sen");
        recover = 30+heal;
        if (sen < e_sen )
        {
        if ( (sen + recover) >= e_sen )
        {
            this_player()->set("sen", e_sen);
        } else
        {   
            this_player()->add("sen", recover);
        }   
        }

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
        if ( query("remaining") )
        {


         message_vision(HIG"$N拿起一把小叉子，叉了一块"+HIY"桔子"+HIR"荔枝"+HIW"雪莲"+HIG"羹吃了几口。一股清香直入心脾，$N觉得精神好多了。\n"NOR, this_player());



        } else 
        { 


message_vision("$N把盘子里的桔子荔枝雪莲羹吃得干乾净净，仍是意尤未尽。\n", this_player());

                
                destruct(this_object());
        }

        return 1;
}
