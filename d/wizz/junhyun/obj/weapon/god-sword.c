//剑尊-绝剑

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"剑尊-绝剑"NOR,({ "jue sword", "sword", "jian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 10);
                set("weapon_prop/parry", 10);
                set("treasure",1);              
                set("no_sell",1);              
                set("long", "一柄被称为剑尊的神剑。\n"); 
                set("wield_msg", "\n");
                set("unwield_msg", "\n$N将$n向天一直，顿时风起云涌，刹那间$n消失的无影无踪！\n");
        }
        init_sword(240);
        setup();
}

int wield()
{
        object ob = environment();
        object me = this_object();
        mapping weapon_prop;
        object *obj, *inv, weapon;
        int ret, i, j;
        if (ob->query("combat_exp") < 100000 
            || ob->query_str() < 20 || ob->query("max_force") < 1000 
            || ob->query("force") < 1000){
                message_vision(HIY"$N的手刚刚触摸到$n的剑柄，突然一股力量自剑中穿来，将$N击出丈远！$n也随之掉落地上。\n"NOR, ob, me);
                ob->receive_damage("qi", 100);
                ob->receive_wound("qi", 100);
                me->move(environment(ob));
                return 0;
                }
       else if (ret=::wield()){
           message_vision(HIW"\n随着$N一声轻叱，手中寒光闪动，长剑如划破天际的闪电，带出来的却是王霸的气势！\n\n"NOR, ob, me);
           ob->add("force", -200);
           obj = all_inventory(environment(ob));
           if(sizeof(obj) > 1)
               message_vision(HIC"忽然，众人身上所带之剑纷纷自动跃出，插在$N身前的地上，剑尖指天！\n"NOR, ob);
           for(i=0; i<sizeof(obj); i++) {
                if(obj[i]==ob ) continue;
                inv = all_inventory(obj[i]);
                for(j= 0;j< sizeof(inv);j++){
                       if(!mapp(weapon_prop = inv[j]->query("weapon_prop"))) continue;        
                       if(inv[j]->query("skill_type")!="sword") continue;
                       if(inv[j]->query("equipped")){
                          if(obj[i]->query("force") > 1000){
                             obj[i]->add("force", -100);
                             tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，幸而你双手紧握，才没有让它飞出！\n"NOR);
                             continue;  
                             }
                           else {
                                tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，你把握不住，竟然脱手飞出！\n"NOR);
                                tell_room(environment(ob), YEL+obj[i]->name()+"一个把握不住，手中"+inv[j]->name()+YEL"竟然脱手飞出！\n"NOR,({ obj[i] }));
                                }
                           }
                       inv[j]->move(environment(ob));
                       }
           }
           return ret;
       }
}

