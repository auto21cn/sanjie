// jijiu.c 这是用来急救玩家的
//player prison
//idea@yqyl

#include <ansi.h>
void takeout(object who);

inherit ROOM;

void wizchannel(string result);

void create()
{
        set("short",HIW"急救室"NOR);
        set("long", @LONG

这里是专门用来各式各样的玩家的，有很多大夫和护士走来走去，这里躺了几个呻吟病号，
还有一个漂亮的护士在旁边看护，有几个不怀好意的病号在色咪咪盯着护士。

LONG );
     set("objects", ([
                __DIR__"npc/hushi":1
        ]) );
        set("no_fight", 1);
        set("no_magic",1);
        set("no_kill",1);

        set("valid_startroom", 1);
        set("alternative_unc",1);
        set("channel_id", "急救室");
        setup();

//  call_other("/obj/board/jijiu_b", "???");

        remove_call_out("check_in");
        call_out("check_in",5);
}


void init()
{
        object me;
        int mudage;
        string ttime,temp;
        
        me = this_player();
        if (userp(me))
        if( !wizardp(me) )
        {
                if (me->query("startroom")!="/d/wiz/jijiu")
                {
                ttime=ctime(time())[8..strlen(ctime(time()))];

                me->add("jijiu/times",1);
                me->add("jijiu/totaltime",me->query("jijiu/howlong"));
                me->set("jijiu/inage",me->query("mud_age"));
                me->set("startroom","/d/wiz/jijiu");
                temp = me->query("jijiu/temp");
                me->delete("jijiu/temp");
                if (temp) {
                me->set("jijiu/note",ttime+"  "+temp);}
                else { me->set("jijiu/note",sprintf("%s  %s(%s)进入急救室，原因不详。\n",
                        ttime,me->query("name"),me->query("id")));
                        }
                
                me->save();
                
                wizchannel(me->query("jijiu/note"));
                log_file("jijiu",me->query("jijiu/note"));
                }
                add_action("block_cmd","",1);  

                message("vision",
                HIY "突然几个大力士把一个家伙抬进来！\n\n" NOR, environment(me), me);
                tell_object( me, HIR "你实在无奈呼叫了救护服务，，"
                        +"所以抬你来这里，让你好好彻底安全检查！\n\n" NOR);
        }
        
}

int block_cmd1()
{
        string verb = query_verb();
        if (verb=="quit") return 0;
        tell_object( this_player(),"\n\n你现在是个病号，你现在只能等着医护，或者退出" NOR);
        return 1;
}

int block_cmd()
{
        string verb = query_verb();
        if (verb=="say") return 0; 
        if (verb=="help") return 0;
        if (verb=="who") return 0;
        if (verb=="look") return 0;
        if (verb=="chat") return 0;        
        if (verb=="quit") return 0;
        if (verb=="skills") return 0;
        if (verb=="score") return 0;
        if (verb=="hp") return 0;
        tell_object( this_player(),"你现在是个病号，在这里是什么都做不了！\n\n" NOR);
        return 1;
}

void check_in()
{
        object *criminal = all_inventory(this_object()),yuzu;
        int i,howlong,inage,mudage;
        string cname,result,old,ttime;
        
        remove_call_out("check_in");

        for(i=0; i<sizeof(criminal); i++)
        {
                if (userp(criminal[i]) && !wizardp (criminal[i]))
                {       
                        if (criminal[i]->query("kee")<700 && criminal[i]->query("sen")<700)
                        {
                                tell_object(criminal[i],"总算等到护士给你检查，结果护士狠狠给你来了一针....，"+
                                        "你结果痛的死去活来，嗷叫不停。。。\n");
                                criminal[i]->set("kee",500);
                                criminal[i]->set("sen",500);
                              criminal[i]->set("eff_sen",500);
                                criminal[i]->set("eff_kee",500);
               if ( criminal[i]->query("max_sen")<500) criminal[i]->set("eff_sen",criminal[i]->query("max_sen"));
               if ( criminal[i]->query("max_kee")<500) criminal[i]->set("eff_kee",criminal[i]->query("max_kee"));
                        }
                        
                        howlong = criminal[i]->query("jijiu/howlong");
                        inage = criminal[i]->query("jijiu/inage");
                        mudage = criminal[i]->query("mud_age");
                        
                        if (howlong)
                        {
                                if( (inage+howlong*60)<mudage )
                                {
                                        ttime=ctime(time())[8..strlen(ctime(time()))];
                                        
                                        cname = criminal[i]->query("name") + "("+criminal[i]->query("id")+")";
                                        
                                        result = sprintf("%s  %s医护期满(%d分钟)，自动出院了。\n",
                                                        ttime,cname,howlong);
                                                        
                                        old=criminal[i]->query("jijiu/note")+result;
                                        criminal[i]->set("jijiu/note",old);
                                        log_file("player/jijiu",result);
                
                                        wizchannel(result);
                                        takeout(criminal[i]);
                                }
                        }
                }
        }
        
        call_out("check_in",5);
}

void takeout(object who)
{
        who->move("/d/city/kezhan");
        who->set("startroom", "/d/city/kezhan");
        who->save();
        message_vision("$N从医院里面放了出来，精神饱满的伸了个懒腰吸了口新鲜空气。\n",who);
            message("system",HIG"\n\n       "+who->name(1)+"出院了, GOOD LUCK! \n\n"NOR,users());

}


void wizchannel(string result)
{
        CHANNEL_D->do_channel(this_object(),"wiz",result);
}

void alternative_unc(object who)
{
        if (userp(who)) who->die();
}

