/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Last modified by waiwai@2001/04/19

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "的脸上五官挪位，捂着肚子到处找厕所，看来象是得了痢疾了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你得了痢疾肚子难受极了，直想上厕所。\n" NOR );
      message("vision", me->name() + "捂着肚子到处找厕所，看来是得了痢疾了。\n",
            environment(me), me);
   }
   me->set_temp("death_msg",HIY" 得了痢疾拉肚子死了！！！\n"NOR);

   me->add("kee", -100);
   me->add("sen", -100);

   me->apply_condition("ill_liji", duration - 1);

	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;
   return CND_CONTINUE;
}
