//crack by stey

inherit ROOM;

void check_zuochan(object me);
void finish(object me);
void reward(object me);
string chinese_time(int timep);

string *str=({
                "你慢慢物我两忘。\n",
                "你觉得一切胜负荣辱都是过眼云烟。\n",
                "你觉得自己进入了一个前所未有的境界。\n",
                "你的心境渐渐清明。\n"
                "你慢慢地领悟到佛的精髓。\n",
                "你的思绪慢慢宁静下来。\n"
             });

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG
这里空荡荡的，只在靠近墙壁的地方整整齐齐地放着一些蒲团。
房里光线很暗，墙壁不知道是什么材料做的，会发出淡淡的黄
光。这里是坐禅(zuochan)参悟的好地方。你要是实在定不下心
也可以出去走走再回来(halt)。

LONG);

  set("exits", ([
          "south"   : __DIR__"baoge1",
      ]));

  set("no_fight", 1);
  set("no_time",1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_zuochan", "zuochan");
    add_action("do_halt", "halt");
}

int do_zuochan()
{       int zuochan_time;

        object me = this_player();

        if (me->query("rulaitask/get"))
             {tell_object(me,"你有任务在身，定不下神来参悟。\n");
              return 1;
             }

        if (me->query_temp("zuochan"))
             {tell_object(me,"你正在坐禅参悟。\n");
              return 1;
             }

        message_vision("$N盘膝坐在一个蒲团上，潜思入定，开始参悟自己的所作所为。\n",me);
        me->set_temp("no_move", 1);
        me->set_temp("zuochan", 1);
        if ( !me->query("rulaitask") )  finish(me);
        else {
                if (me->query("rulaitask/fail"))
                zuochan_time = 30+random(16);
                else zuochan_time = 10+random(16);
                me->set_temp("zuochan_time",zuochan_time);

                check_zuochan(me);
              }

        return 1;
}


void check_zuochan(object me)
{
        int zuochan_time = me->query_temp("zuochan_time");

           if (!me->query_temp("zuochan")) return;

        if ( zuochan_time <= 0 ) finish(me);

        else {
                if ( zuochan_time%6 == 0 )
                      tell_object(me,str[random(sizeof(str))]);
                me->add_temp("zuochan_time", -1);
             me->add_busy(1);
                call_out("check_zuochan",1,me);
              }
}


void finish(object me)
{
        tell_object(me,"你只觉灵台一片清明，似乎禅意已尽。\n");
        message_vision("$N深深地吸了口气，站了起来。\n",me);
        me->delete_temp("no_move");
        me->delete_temp("zuochan");
        if (me->query("rulaitask/accomplish")) reward(me);
        me->delete("rulaitask");
        me->set("rulaitaskjob/done",1);
        me->apply_condition("rulai_job",25+random(50));
}

void reward(object me)
{
        int wuxue,level,kind_bonus,level_bonus,timep,num;
        int extra_bonus,potential_bonus,combat_exp_bonus,daoxing_bonus;
        string str,kind,time,msg;
        string logpath = "rltask";

        wuxue = me->query("combat_exp");
        level = me->query("rulaitask/level");
        kind  = me->query("rulaitask/kind");
        timep = me->query("rulaitask/end_time")-me->query("rulaitask/start_time");
        time  = CHINESE_D->chinese_time(timep);

        if ( level == 1 ) level_bonus=300;
        else if ( level == 2 ) level_bonus=800;
        else level_bonus=1200;

        if ( kind == "杀" ) kind_bonus=300;
        else if ( kind == "擒" ) kind_bonus=500;
        else if ( kind == "劝" ) kind_bonus=900;
        else kind_bonus=1200;

        //if ( me->query("combat_exp") < 20000000)

        extra_bonus = (me->query("combat_exp")/2000)+kind_bonus;

        //if( extra_bonus > 8000) extra_bonus =8000;
        if ( me->query("combat_exp") < 30000000)
        {
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/4;
                daoxing_bonus = (extra_bonus*6 + (random(level_bonus) + random(kind_bonus))*2)/25;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*3/2)/4;
        }
        else
        {
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/10;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/9;
                daoxing_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/75;
        }
        if (  me->query("combat_exp") > 50000000 && me->query("combat_exp") < 150000000 )
        {
// 防止数据越来越大,数据溢出
                if (combat_exp_bonus>20000) combat_exp_bonus=20000;
                if (daoxing_bonus>10000) daoxing_bonus=10000;
        }
/*        if(!me->query_temp("rulai_task"))
        {
                daoxing_bonus /=2;
                combat_exp_bonus /=2;
                potential_bonus /=2;
         }
// mudring moved num to quizd for a big bug.
         else {me->delete_temp("rulai_task");}
         if(me->query("quiz_combat_exp"))
        {
                me->add("combat_exp",me->query("quiz_combat_exp"));
                me->add("daoxing",me->query("quiz_daoxing"));
                me->add("balance",me->query("quiz_balance"));
                me->add("potential",me->query("quiz_potential"));
                me->delete("quiz_balance");
                me->delete("quiz_combat_exp");
                me->delete("quiz_daoxing");
                me->delete("quiz_potential");
                me->save();
                tell_object(me,"你得到了额外的问题奖励。\n");
        }

*/
        me->add("potential", potential_bonus);
        me->add("combat_exp", combat_exp_bonus);
        me->add("daoxing", daoxing_bonus);
        str = "得到了"+potential_bonus+"点潜能，";
        str +=combat_exp_bonus+"武学经验，";
        str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"道行。";
        tell_object(me,"你得到了"+potential_bonus+"点潜能，"+combat_exp_bonus+"武学经验，"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"道行。\n");

        str = me->name()+"完成了一个难度"+chinese_number(level)+"的"+kind+"妖任务，" + str;
        if ( level > 1 ) CHANNEL_D->do_channel(me, "rumor",str);

        str = str + "用时"+time+"。";
        MONITOR_D->report_system_msg (str);
        log_file("taskreward",sprintf("[%s]%s\n",ctime(time()),str));

        switch (kind)
          {case "杀": {
                        me->add("rulaitask_log/kill_potential",potential_bonus);
                        me->add("rulaitask_log/kill_combat",combat_exp_bonus);
                        me->add("rulaitask_log/kill_daoxing",daoxing_bonus);

                        switch (level)
                            {case 1:{me->add("rulaitask_log/kill1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/kill2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/kill3",1);
                             }
                         break;
                      }
          case "擒": {
                        me->add("rulaitask_log/arrest_potential",potential_bonus);
                        me->add("rulaitask_log/arrest_combat",combat_exp_bonus);
                        me->add("rulaitask_log/arrest_daoxing",daoxing_bonus);

                        switch (level)
                            {case 1:{me->add("rulaitask_log/arrest1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/arrest2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/arrest3",1);
                             }
                         break;
                      }
          case "劝": {
                        me->add("rulaitask_log/persuade_potential",potential_bonus);
                        me->add("rulaitask_log/persuade_combat",combat_exp_bonus);
                        me->add("rulaitask_log/persuade_daoxing",daoxing_bonus);

                        switch (level)
                            {case 1:{me->add("rulaitask_log/persuade1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/persuade2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/persuade3",1);
                             }
                         break;
                      }
          case "降": {
                        me->add("rulaitask_log/fight_potential",potential_bonus);
                        me->add("rulaitask_log/fight_combat",combat_exp_bonus);
                        me->add("rulaitask_log/fight_daoxing",daoxing_bonus);

                        switch (level)
                            {case 1:{me->add("rulaitask_log/fight1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/fight2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/fight3",1);
                             }
                     }
          }
}





int do_halt()
{
        object me = this_player();

          me->add_busy(3);
        if(me->query_temp("last_halt_time") && !wizardp(me) && (me->query_temp("last_halt_time")+20)>time())
        {
                tell_object(me,"等等......\n");
                return 1;
        }
        me->add("sen",-10);
        me->set_temp("last_halt_time",time());
        if (me->query_temp("zuochan"))
        {
//274                  remove_call_out("check_zuochan");
                me->delete_temp("zuochan_time");
                message_vision("$N深深地吸了口气，站了起来。\n",me);
                me->delete_temp("no_move");
                me->delete_temp("zuochan");
                return 1;
        }
        else return 0;
}



string chinese_time(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        return time;
}


