// Created By Longer
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object ob;
        string pet_id, w_name, name, item;
        string *id_list, *t_list;       
        int t, color, w_lv;
        if (!me->query("weapon/make"))
          return notify_fail("你现在没有自制武器。\n");
        item = me->query("weapon/id");
        if(objectp(ob = present(item, me))) 
                     return notify_fail("不是在你身上吗?\n");
        if(t=(int)me->query_temp("soar/time_start")) 
          {
            if(t<=time() && time()< t+10)
                  return notify_fail("你的武器坏了，看来一时来不了。\n");
          }
      
        pet_id=me->query("weapon/id");
        id_list = ({ pet_id });
        t_list = explode( pet_id, " ");
        if( sizeof(t_list) > 1 )   {
                id_list += t_list;
        }
        ob=find_player(pet_id);
//    if( !ob ) ob=find_living(pet_id);
        if( !ob ) ob = LOGIN_D->find_body(pet_id);
        if( !ob ) {
              switch ( me->query("weapon/type") ) 
               {
                 case "剑": 
                 ob=new("/d/quest/m_weapon/weapon/m_sword");
                 break;
                 case "刀": 
                 ob=new("/d/quest/m_weapon/weapon/m_blade");
                 break;
                 case "杖": 
                 ob=new("/d/quest/m_weapon/weapon/m_staff");
                 break;
                 case "鞭": 
                 ob=new("/d/quest/m_weapon/weapon/m_whip");
                 break;
                 case "棍": 
                 ob=new("/d/quest/m_weapon/weapon/m_stick");
                 break;
                 case "枪": 
                 ob=new("/d/quest/m_weapon/weapon/m_spear");
                 break;
                 case "锏": 
                 ob=new("/d/quest/m_weapon/weapon/m_mace");
                 break;
                 case "锤": 
                 ob=new("/d/quest/m_weapon/weapon/m_hammer");
                 break;
                 case "叉": 
                 ob=new("/d/quest/m_weapon/weapon/m_fork");
                 break;
                 case "斧": 
                 ob=new("/d/quest/m_weapon/weapon/m_axe");
                 break;

               }
                ob->set("owner",getuid(me));
                  ob->restore();
                w_name=me->query("weapon/name");
                w_lv = me->query("weapon/lv");
                color = w_lv;
        switch(color){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                        name = HIB + w_name + NOR;
                        break;
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                        name = BLU + w_name + NOR;
                        break;
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                        name = CYN + w_name + NOR;
                        break;
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                        name = WHT + w_name + NOR;
                        break;
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                        name = HIY + w_name + NOR;
                        break;
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                        name = HIC + w_name + NOR;
                        break;
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                        name = HIR + w_name + NOR;
                        break;
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                        name = HIM + w_name + NOR;
                        break;
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                        name = MAG + w_name + NOR;
                        break;
                default:
                        name = HIW + w_name + NOR;
                        break;
        }

                ob->set_name(name,id_list);
                ob->setup();
        } else if (ob->query("owner") != me->query("id"))
                   return notify_fail("召唤武器失败！\n");
        ob->set("no_copy", 1);
        ob->move(me);
        message_vision(HIY"\n    只听半空中一声龙吟，$n"HIY"从天而降,落入$N的怀中。\n\n"NOR,me,ob);
        me->set_temp("soar/time_start", time());     
   return 1;
}

int help(object me)
{
        write(@HELP
指令格式： zhaohuan

这个指令让你可以召回你的武器。
HELP
 );
        return 1;
}

