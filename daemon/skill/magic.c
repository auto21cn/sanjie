// magic.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s,temp;

                  temp=me->query_skill("magic",1);
             temp=temp*10;
                  me->set("max_atman",temp);
                  tell_object(me,"由于你勤学灵术，你的灵力进步啦！！！\n");
}
