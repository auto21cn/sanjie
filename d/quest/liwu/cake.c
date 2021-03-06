// cake.c
// idea from xo lib
// rewritten by mudring Sep/18/2002

#include <ansi.h>
#include <localtime.h>
#define REMON 8  // 月份，实际月份等于这个数字加1
#define REDAY 28 // 日期 从20到28为止
#define REEXP 200000 // 获得一般奖励最小需要的exp
inherit ITEM;

string *GetName = ({
"豆沙月饼",
"莲蓉月饼",
"椰蓉月饼",
"火腿月饼",
"芝麻月饼",
"桂花月饼",
"素月饼",
"冰皮月饼",
"果蔬月饼",
"海味月饼",
"纳凉月饼",
"椰奶月饼",
"茶叶月饼",
"保健月饼",
"像形月饼",
"迷你月饼",
});

varargs string GetColor(int flag)
{
    string color;

    if (flag)
        color = COLOR_D->random_color(4);
    else
    {
        if (random(2))
            color = COLOR_D->random_color(4);
        else
            color = COLOR_D->random_color(3);
    }

    return color;
}

string SetName()
{
    int i = random(sizeof(GetName));

    return (GetColor() + GetName[i] + NOR);

}

void create()
{
    string myName;

    myName=SetName();
    set_name( myName, ({ "cake"}) );
    set("long","一个小小的" + myName + "，香喷喷的，刚出炉，还是热的呢！\n");
    set_weight(50); // 一两
    if( clonep() ) 
        set_default_object(__FILE__);
    else 
    {
        set("unit", "个");
        set("value", 5000); // 50 silver one
        set("no_sell","风铃的东西我可不敢买。\n");
        set("no_get","检月饼吃？还是去找风铃吧！\n");
        set("no_put","想收藏啊？去找风铃要珍品！\n");
        set("no_drop","嘿嘿......风铃的东西土地老爷都不敢要哟！\n");
        set("no_give","月饼嘛，还是送（song）吧！！\n");
    }
    set("is_monitored",1);
    setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_give", "song");
        add_action("do_open", ({"bai", "open"}));
        add_action("do_write", "write");
}


int do_eat(string arg)
{
    object me, what;
    me = this_player();
    what = this_object();

    if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
    if (arg != "cake")
        return notify_fail("你想吃什么？cake？？？\n");

    if (what->query("mudring/have_gaven")) // 别人送的
    {
        tell_object(me,
            HIM"这是"+what->query("mudring/gaven_name")+"送给你的礼物，"+
            "仔细一看，上面有一条非常细的小缝，你不妨掰（OPEN）开来看看。\n"NOR);
            return 1;
    }
    tell_object(me,
    MAG"这是用来送礼的月饼，你可以在里面放（WRITE）\n上你的祝福给你最想送的人！\n"NOR);
    return 1;
}

int do_give(string arg)
{
    object me, who, what;
    string yourname;
        
    me = this_player();
    what = this_object();

    if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
    if (! arg)
        return notify_fail("你要把礼品月饼给谁啊？\n");
    if (! objectp(who = present(arg, environment(me))) )
        return notify_fail("这里没有这个人。\n");
    if (arg == me->query("id"))
        return notify_fail("送自己？自恋？！\n");
    if (! living(who))
        return notify_fail( who->name() + "现在可接受不了你的东西。\n" );
    if (who->query("env/no_accept"))
        return notify_fail( who->name() + "好象不大愿意接收你的物品。\n");

    if (what->query("mudring/have_gaven"))  
        return notify_fail("这个月饼是别人送给你的呀！！\n");

    what->set("mudring/have_gaven",me->query("id"));
    what->set("mudring/gaven_id",me->query("id"));
    what->set("mudring/gaven_name",me->query("name"));
    tell_object(me,"你把这个"+
        what->query("name") + "当礼品送给了" + who->query("name")+"\n"+
        "心里不禁一阵砰砰乱跳！\n");
    tell_object(who, me->query("name") + "（" + me->query("id") + "）"+
        "把一个" + what->query("name") + "送给你作为中秋的礼物，好幸福啊！\n");

    MONITOR_D->report_debug_object_msg(me, "俺送了个"+what->query("name")+"给 " + getuid(who));
    MONITOR_D->mudring_log("cake", me, " song "+what->query("name")+" to " + getuid(who));
    what->move(who);
    me->start_busy(5);
    return 1;
}

int do_write(string arg)
{
        object me, what;
        me = this_player();
        what = this_object();

    if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
        if (! arg)
            return notify_fail("你要写下什么样的祝福呢？\n");
/*
        if (me->query("mudring/mooncake"))
            return notify_fail("你已经送过月饼给别人了！\n");
*/
/*
        if (strlen(arg) > 60)
            return notify_fail("祝福最多只能写三十个汉字，注意言简意赅哦！\n");
*/
        what->set("mudring/wishes", arg);
/*
        what->set("mudring/gaven_id", me->query("id"));
        what->set("mudring/gaven_name", me->query("name"));
*/
        tell_object(me, "你将心中的祝福写在一张纸条上，卷成一个小卷。\n");
        tell_object(me, "你将"+what->query("name")+"轻轻掰开一条小缝，把纸卷塞了进去。\n");
        tell_object(me, "你把"+what->query("name")+"轻轻捏拢了一些，好了，礼物做好了！\n");
        tell_object(me, "你现在可以把这个礼品"+what->query("name")+"送给（song）\n你最想送的人了！\n");
                
        me->start_busy(5);
        return 1;
}

int do_open(string arg)
{
    object me, what;
    string color, bless, whoId, whoName;
    mixed lt = localtime(time());

    what = this_object();
    me = this_player();

    if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
    if (! arg || arg != "cake")
        return notify_fail("你要掰什么？\n");

    whoId = what->query("mudring/gaven_id");
    whoName = what->query("mudring/gaven_name");
    if (! whoId || ! whoName)
        return notify_fail("自己买的月饼掰开有什么意思呢？\n");
    bless = RING_DIR"test/format.c"->format_string(what->query("mudring/wishes"), 70, 1);

    color = GetColor(1);
    if (bless)
    {
        tell_object(me,"你轻轻地把这个"+what->query("name")+"掰开，发现里面有一个小纸卷。\n");
        tell_object(me,"你展开小纸卷，发现上面有一行字，于是展开阅读了起来......\n");
        tell_object(me,"\n");
        tell_object(me, color +
"◤☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆◥\n" + NOR + GetColor(1)+
"\t"+me->query("name")+"\n"+
NOR+GetColor() +"\n"+bless+"\n"NOR+
"                                                 " + GetColor(1) + whoName + "（" + whoId + "）\n"+
color +"◣☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉☉◢\n"+
"\n"NOR);
/*
        me->delete("mudring/gaven_name");
        me->delete("mudring/gaven_id");
*/
    if (me->query("combat_exp") > REEXP && me->query("mudring/moon_cake") < 5)
    {
        me->add("potential", 2000);
        me->add("mudring/moon_cake", 1);
        tell_object(me,"你的潜力好象变大啦！。\n");
        MONITOR_D->report_debug_object_msg(me, "俺吃了个"+what->query("name")+"加了2000潜能！");
        MONITOR_D->mudring_log("recake", me, " eat "+what->query("name")+" add pot 2000 ");
    }
    if (lt[LT_MON] == REMON && lt[LT_MDAY] <= REDAY &&
    me->query("mudring/moon_got") < 1 && me->query("combat_exp") > REEXP)
    {
// 在这儿添加中秋奖励。。。
// 100n dx多吗?
        me->add("daoxing", 100000);
        me->add("combat_exp", 20000);
        me->add("mudring/moon_got", 1);
        tell_object(me,"你的修为好象变强啦！。\n");
        MONITOR_D->report_debug_object_msg(me, "俺得到了中秋奖励！");
        MONITOR_D->mudring_log("remoon", me, " got moon reward.");
    }
    }
    else
        tell_object(me,"你掰开了这个"+what->query("name")+"，结果里面什么都没有。\n");
    what->move("/obj/empty");
    call_out("dest",3);
    me->start_busy(5);
    return 1;
}


void dest()
{
    if (this_object())
        destruct(this_object());
}

