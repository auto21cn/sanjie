//龙虎天师袍
//by junhyun
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string setcolor();

void create()
{
        set_name(HIW"龙虎天师袍"NOR, ({ "longhu tianshipao" ,"cloth", "tianshipao", "pao" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("text" , "这是中国道教创始人张道陵的道袍，长年累月被太极真气所包围，
似乎有了储存内力的功效，你可以试试向天师袍中注入太极(tianji)内力\n"NOR);
                set("long",HIW+query("text") );
                set("material", "silk");
                set("unit", "件");
                set("unique", 1);
                set("value", 10000000);
                set("treasure", 1);
                set("wear_msg", HIW"只见$N"HIW"双手一抖，便把一件隐隐透着紫色光彩的天师袍穿在了身上。\n" NOR);
                set("armor_prop/armor", 180);

                set("owner","no owner");
        }
        setup();
}

void init()
{
        add_action("do_taiji","taiji");
}

int do_taiji(string arg)
{
        int cost;
        object me = this_player();

        if( query("force") >= 13990 )
                return notify_fail("天师袍中已经充满了太极真力，你再也无法注入了！\n");

        if( me->query_skill("force") < 160 )
                return notify_fail("你的内功等级不够，无法注入内力！\n");

        if( me->query_skill("yinyun-ziqi",1)>100 && me->query_skill_mapped("force")=="yinyun-ziqi" )
                cost = 1000;
        else
                cost = 1200;

        if( cost > me->query("force") )
                return notify_fail("你的内力不足，无法注入足够的内力！\n");

        if( query("owner")!=me->query("id") && query("owner")!="no owner" ) {
                set("force" , query("force")/2);
                message_vision(MAG"$N发现自己的内力与天师袍中原有的内力相冲突，虽然最终还是注入了你的内力，但已经损失了不少。\n",me);
        }
        set("owner" , me->query("id"));

        add("force" ,  1000);
        if (query("force") > 13990) set("force" , 13990);
        me->add("force" , -cost);

        if( cost<=1000 )
                message_vision(MAG"$N"MAG"脸上泛起一层隐隐的紫气，双手虚按龙虎天师袍，把太极真力注入天师袍之中。\n"NOR,me);
        else
                message_vision(HIC"$N"HIC"潜运内功，努力把内力注入龙虎天师袍，最后虽然成功但因为不是太极真力而多花了点力气。\n"NOR,me);
        
        setcolor();

        return 1;
}

mixed ob_hit(object target, object me, int damage)
{
        int times , kee , cost , charge = 16;
        string color;
        
        if(query("force")<= 0 || damage<250)
                return 0;

        if(query("owner") == me->query("id"))
                times = 10;
        else 
                times = 15;

        cost = (damage / 2)*charge/10*times/10;
        kee = damage/2;
        if( cost > query("force") ) {
                kee = kee * query("force") / cost ;
                cost = query("force");
        }               
        add("force" , -cost);

        if(wizardp(me) && me->query("env/test")) 
                tell_object(me,sprintf("kee:%d , force:%d   ",kee,cost));

        color = setcolor();     
        if( times<=10 )
                message_vision(query("name")+color+"突然发出耀眼的光芒，抵挡了$N"+color+"的部分攻势！\n"NOR,target);
        else
                message_vision(query("name")+color+"突然发出耀眼的光芒，抵挡了$N"+color+
                                        "的部分攻势！但因为内功冲突而浪费了不少储存的真气。\n"NOR,target);

        return -kee;
}

string setcolor()
{
        int lvl;
        string color , s;

        if ( query("force") != 0 )
                lvl = query("force") / 1000;
        else
                lvl = 0;
        switch (lvl)  {
                case  0:
                case  1:
                case  2: color = HIW;break;
                case  3:
                case  4: color = HIC;break;
                case  5:
                case  6: color = CYN;break;
                case  7:
                case  8: color = HIB;break;
                case  9:
                case 10: color = BLU;break;
                case 11:
                case 12: color = HIM;break;
                case 13: color = MAG;break;
                default: color = HIW;
        }
        set("name" , color+"龙虎天师袍"NOR );
        
        if( lvl > 0 )
                s = color+"天师袍之上已经注有"+CHINESE_D->chinese_number(lvl)+"道太极真力！\n"NOR;
        else
                s = "";
        set("long" , color+query("text")+s);

        return color;
}

