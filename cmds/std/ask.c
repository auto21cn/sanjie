// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;
string query_inquiry(object ob);

string *msg_dunno = ({
        "$n摇摇头，说道：没听说过。\n",
        "$n疑惑地看着$N，摇了摇头。\n",
        "$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
        "$n耸了耸肩，很抱歉地说：无可奉告。\n",
        "$n说道：嗯．．．这我可不清楚，你最好问问别人吧。\n",
        "$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
        string dest, topic, msg;
        object ob;
        mapping inquiry;

        seteuid(getuid());

        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("你要问谁什么事？\n");

          if(me->is_busy())
                return notify_fail("你正忙着呢!\n");
        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("这里没有这个人。\n");

        if( !ob->is_character() ) {
                message_vision("$N对着$n自言自语．．．\n", me, ob);
                return 1;
        }

        if( !ob->query("can_speak") ) {
                message_vision("$N向$n打听有关『" + topic
                        + "』的消息，但是$p显然听不懂人话。\n", me, ob);
                return 1;
        }

 

        if( userp(ob) ) return 1;
        if(topic=="all")
                        {
                        message_vision( CYN "$N对$n悄声说道:"+query_inquiry(ob)+"!\n" NOR, ob,me);
                        me->start_busy(2);
                        return 1;
                        }
        if( !living(ob) ) {
                message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
                        me, ob);
                return 1;
                          }
        if(topic == "question")
        {
                if(!ob->query("questguai")
                      && !ob->query("taskguai")
                      && ! ob->query("questnpc")
                      && me!=ob->owner())
                      {
                      message_vision("$N对着$n自言自语．．．\n", me, ob);
                        return 1;}
                        
                        {
                        if(!ob->query("question"))
                                {
                                        QUIZ_D->random_quiz(ob,me);
                                        return 1;
                                 }
                         if(ob->query("question")=="on")
                                 {
                                 message_vision( CYN +ob->query("quiz/str")+ NOR,me);
                                 return 1;
                                 }
                         if(ob->query("question")=="done")
                                 {
                             message_vision( CYN "$N说道：我的问题已经解决了\n" NOR, ob); 
                                 return 1;
                                } 
                                else
                                {ob->command("heng "+me->query("id")); return 1;}
                         }
                      
           }
       if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

        // by snowcat jan 23 1998
        if ( msg = QUEST->quest_ask (me, ob, topic) ) {
                if( stringp(msg) ) {
                        message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
                        return 1;
                }
        }

        if( msg = ob->query("inquiry/" + topic) ) {

                if( stringp(msg) ) {
                        message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
                        return 1;
              }          
        } else
                message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

        return 1;
}
//从npc身上读取inquiry
string query_inquiry(object ob)
{
        int i=0;
        mapping inq;
        string str="", *indexs;

        if(mapp(inq=ob->query("inquiry")))
                {
                indexs=keys(inq);
                for(i=0;i<sizeof(indexs);i++)
                        {
                                str=indexs[i]+" "+str;
                                }
                str="有关于 "NOR+HIR+str+NOR CYN"的事情,我很高兴告诉你!";
                return str;
                }
        return "实在是对不起,我什么也不知道呀!";
}
int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}



