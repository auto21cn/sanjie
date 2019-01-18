//Last modified by waiwai@2001/04/19

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) me->delete_temp("shit");

	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

   if( !living(me) ) {
      message("vision", me->name() + "脸憋的通红，看来得方便一下了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你的脸憋的通红，看来得方便一下了。\n" NOR );
      message("vision", me->name() + "脸憋的通红，看来得方便一下了。\n",
            environment(me), me);
   }
	me->set_temp("death_msg",HIY" 没来得及得以方便而憋死了！！！\n"NOR);
	me->set_temp("killbyname","没来得及方便");
	me->set_temp("killbyid","shit");
	me->set_temp("killbyB","被憋");

   me->add("kee", -20);
   me->add("sen", -20);
   me->apply_condition("full", duration - 1);


   return CND_CONTINUE;
}
