#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int call_pet(object me);
int call_ling(object me);

int main(object me, string arg)
{
	if (!arg || arg == "pet")
	    return call_pet(me);
	if (arg == "ling")
	    return call_ling(me);
}
int call_ling(object me)
{
	object ob;
	string pname;
		
	if (!pname = me->query("party/party_name"))
	    return notify_fail("你必须先加入一个帮会！\n");
	if (present("ling pai", me))
        return notify_fail("你身上不是已经有令牌了么？！\n");
	ob = new("/obj/misc/ling.c");
	ob->set_name(pname + "令", ({"ling pai", "ling"}));
	ob->set("long", pname + "的帮派令牌");
	ob->move(me);
	message_vision("$N伸手在腰间一摸，掏出了$n。\n",me,ob);
	return 1;
}
int call_pet(object me)
{
        object ob;
        string pet_id;
        string *id_list, *t_list;       
             int tt;
        if (!me->query("pet/pet_id"))
          return notify_fail("你现在并没有养宠物。\n");
        if (environment(me)->query("short")=="擂台")
           return notify_fail("擂台上怎么能叫宠物帮忙。\n");
//
          if((tt=me->query_temp("recall_time")) && tt +4 > time()) 
           return notify_fail("等等再叫宠物帮忙,它都叫累了。\n");
              me->set_temp("recall_time",time());
        pet_id=me->query("pet/pet_id");
        id_list = ({ pet_id });
        t_list = explode( pet_id, " ");
        if( sizeof(t_list) > 1 )   {
                id_list += t_list;
        }
        ob=find_player(pet_id);
if( !ob ) ob=find_living(pet_id);
        if( !ob ) ob = LOGIN_D->find_body(pet_id);
        if( !ob ) {
                ob=new("/d/eastway/npc/pet");
//              ob->set("owner",getuid(me)); 
              ob->set("owner",me->query("id")); 
                  ob->restore();
        ob->clear_condition();
              ob->set("owner",me->query("id")); 
                ob->set_name(ob->query("name"),id_list);
                 ob->set("default_actions", (: call_other, "/adm/daemons/race/beast.c", "query_action" :));
                ob->setup();
        } else if (ob->query("owner") != me->query("id"))
                   return notify_fail("好象你的宠物不肯听你的话了，你还是自已去找找吧！\n");
        // nk. mudring Jan/03/2003
        if (!ob->query_temp("invoker") ||
            ob->query_temp("invoker") != me)
                ob->set_temp("invoker", me);
        ob->move(environment(me));
        message_vision("$N一个唿哨，$n兴奋地从远处向$N奔来。\n",me,ob);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式： recall

这个指令让你可以召回你走失的宠物。
HELP
 );
        return 1;
}

