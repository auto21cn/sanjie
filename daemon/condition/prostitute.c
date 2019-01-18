// Update by waiwai@2003/04/25

#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

   if (file_name(environment(me))!="/d/city/misc/lichunyuan2") {
   tell_object(me,HIY"丽春院龟公出现在你身边：你能跑哪里去！快回去接客！\n"NOR);
      message_vision(CYN"丽春院龟公突然出现，不由分说，拉了$N就走。\n"NOR,me);
      me->move("/d/city/misc/lichunyuan2");
   }

   me->apply_condition("prostitute", duration - 1);
	if((int)me->query_condition("prostitute")==0) {
   tell_object(me,HIW"你接客期满自由了。。。\n"NOR);

        me->set("title",me->query("family/family_name")+"第"+
                chinese_number(me->query("family/generation"))+
                "代弟子");
        me->delete("hooker");
        me->delete("nickname");
	me->clean_condition("prostitute");
	me->set("startroom","/d/city/kezhan");
	}

   return CND_CONTINUE;
}
