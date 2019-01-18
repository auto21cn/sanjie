// time.c
// rewritten by mudring

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int age;
    int exp;
    int dx;
    int time;
    object ob;
/*
    //Add By Aeddy 2004-1-9
    string season, weather;
    season=XYJTIME_D->check_weather_season();
    weather=NATURE_D->check_weather();
*/
    seteuid(getuid(me));

    if (!arg) ob = me;
    else if (wizardp(me))
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("您要察看谁的状态？\n");
    } 
    else return notify_fail("只有巫师才可以察看别人的状态。\n");

    age  = (ob->query("mud_age") - ob->query_temp("logon_mudage"));
    time = (time()-ob->query_temp("logon_time"));

    if (age < 60)  age = 60;

    exp = (ob->query("combat_exp") - ob->query_temp("logon_exp")) * 60 / age;
    dx  = (ob->query("daoxing") - ob->query_temp("logon_daoxing")) * 60 / age;


//    write("现在是"HIY"三界神话"HIG"「蛇口」站"NOR + NATURE_D->game_time() + "。\n");
    write("现在是" + CHINESE_D->chinese_date(time()) + "。\n");
// 43      write("现在是" + NATURE_D->game_time() +" "+season+weather+ " \n"NOR);
    write(ob->name(1) + "这次已经连续玩了" + CHINESE_D->chinese_time(time) + "。\n");
    if (wizardp(me))
        write(ob->name(1) + "这次增加年龄" + CHINESE_D->chinese_time(age) + "。\n");
if (age > 300)
{
    write(ob->name(1) + "上次经验：" + ob->query_temp("logon_exp") 
          + "，现在经验：" + ob->query("combat_exp") + "，平均每分钟" + exp + "点。\n" );
    write(ob->name(1) + "上次道行：" + ob->query_temp("logon_daoxing")
          + "，现在道行：" + ob->query("daoxing") + "，平均每分钟" + dx + "点。\n" );
}
    return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令让你(你)知道现在的时辰。

HELP
    );
    return 1;
}
