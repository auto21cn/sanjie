#include <ansi.h>
#include <medical.h>

inherit F_VENDOR_SALE;

string ask_job();
int do_peiyao(string arg);
int working(object me);
int halt_working(object me);

void create()
{
        set_name("姚春", ({"yao chun", "yao", "chun"}));
        set("title", HIG "回春堂" NOR);
        set("nickname", HIR "跌打名医" NOR);
        set("long",
                "这便是长安回春堂药铺的跌打名医姚春，身材干\n"
                "瘦，其貌不扬。\n");
        set("gender", "男性");
        set("age", 65);
        set("int", 38);
        set("kee", 1000);
        set("max_kee", 1000);
        set("sen", 1000);
        set("max_sen", 1000);
        set("shen_type", 1);

        set("combat_exp", 500000);
        set("attitude", "heroism");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);
        set("inquiry", ([
                "配药"   : (: ask_job :),
                "工作"   : (: ask_job :),
                "job"    : (: ask_job :),
        ]));

        set("vendor_goods", ([
                "chaihu"   :HERB("chaihu"),         // 柴胡
                "chenpi"   :HERB("chenpi"),         // 陈皮
                "chongcao" :HERB("chongcao"),       // 虫草
                "chuanwu"  :HERB("chuanwu"),        // 川乌
                "dahuang"  :HERB("dahuang"),        // 大黄
                "dangui"   :HERB("dangui"),         // 当归
                "duhuo"    :HERB("duhuo"),          // 独活
                "fangfeng" :HERB("fangfeng"),       // 防风
                "fuzi"     :HERB("fuzi"),           // 附子
                "gsliu"    :HERB("gsliu"),          // 干石榴
                "guiwei"   :HERB("guiwei"),         // 归尾
                "hafen"    :HERB("hafen"),          // 蛤粉
                "heshouwu" :HERB("heshouwu"),       // 何首乌
                "honghua"  :HERB("honghua"),        // 红花
                "huangqi"  :HERB("huangqi"),        // 黄芪
                "juhua"    :HERB("juhua"),          // 菊花
                "lanhua"   :HERB("lanhua"),         // 兰花
                "lingxian" :HERB("lingxian"),       // 灵仙
                "lingzhi"  :HERB("lingzhi"),        // 灵芝
                "mahuang"  :HERB("mahuang"),        // 麻黄
                "moyao"    :HERB("moyao"),          // 没药
                "niuhuang" :HERB("niuhuang"),       // 牛黄
                "niuxi"    :HERB("niuxi"),          // 牛膝
                "qianjinzi":HERB("qianjinzi"),      // 千金子
                "renshen"  :HERB("renshen"),        // 人参
                "ruxiang"  :HERB("ruxiang"),        // 乳香
                "shadan"   :HERB("shadan"),         // 鲨胆
                "shancha"  :HERB("shancha"),        // 山茶花
                "shanjia"  :HERB("shanjia"),        // 山甲
                "shengdi"  :HERB("shengdi"),        // 生地
                "shenglg"  :HERB("shenglg"),        // 生龙骨
                "sumu"     :HERB("sumu"),           // 苏木
                "taoxian"  :HERB("taoxian"),        // 桃仙
                "tenghuang":HERB("tenghuang"),      // 藤黄
                "tianqi"   :HERB("tianqi"),         // 田七
                "tugou"    :HERB("tugou"),          // 土狗
                "wulingzhi":HERB("wulingzhi"),      // 五灵脂
                "xiefen"   :HERB("xiefen"),         // 蝎粉
                "xijiao"   :HERB("xijiao"),         // 犀角
                "xionghuang":HERB("xionghuang"),     // 雄黄
                "xuejie"   :HERB("xuejie"),         // 血竭
                "xuelian"  :HERB("xuelian"),        // 雪莲
                "yanwo"    :HERB("yanwo"),          // 燕窝
                "yjhua"    :HERB("yjhua"),          // 洋金花
                "yuanzhi"  :HERB("yuanzhi"),        // 远志
                "zihua"    :HERB("zihua"),          // 紫花
                "zzfen"    :HERB("zzfen"),          // 珍珠粉
                
                "yanbo"    :"/obj/misc/yanbo",      // 研钵
        ]) );
                        
        setup();
        add_money("gold", 1);
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob; 
        ::init(); 
        
        add_action("do_peiyao", "peiyao");
        add_action("do_vendor_list", "list");
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/peiyao"))
                return "让你干的活你干完了么？";

        if (me->query("combat_exp") > 200000)
                return "让你干这活，也太屈就你了吧。";

        if (me->query("combat_exp") < 100000)
                return "就凭你就这点能力，我看你来药臼都端不起来！";

        if (me->query("kee") < 5)
                return "你还是先歇歇吧，万一累出人命来我可负担不起。";

        if (! interactive(me))
                return "……";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/peiyao") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";

        me->set_temp("job/peiyao", 1);
        return "好，你就帮我配药(peiyao)吧！喏，就这几味。";
}

int do_peiyao(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("你正忙着呢，别着急。\n");

        if (! me->query_temp("job/peiyao"))
        {
                message_vision(CYN "$N" CYN "刚想抓几味药配制，就听见$n"
                               CYN "怒喝道：给我放下，别乱动。\n" NOR,
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));
        tell_object(me, HIY "你开始工作。\n" NOR);
        return 1;
}

int working(object me)
{
        object ob;
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("kee", 1);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N东挑西拣，选好了一些药材。";
                break;
        case 2:
                msg = "$N把药材放进药臼，使劲捣了起来。";
                break;
        case 3:
                msg = "药材渐渐化作粉屑，混在一起。";
                break;
        case 4:
                msg = "粉屑在$N的捣弄下越来越细，逐渐变成了粉末。";
                break;
        default:
                msg = "$N把药材包好，递给$n。";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                msg += CYN "$n" CYN "看了$N" CYN "配的药，点头道：不错，不错！"
                       "这是给你的报酬！\n" NOR;

                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");

                b = 20 + random(20);
                me->add("combat_exp", b);
                me->improve_potential(b);

                ob = new("/obj/money/silver");
                ob->set_amount(10);
                ob->move(me, 1);
        }

        msg = replace_string(msg, "$N", "你");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" + chinese_number(b) +
                                        "点经验和潜能。\n\n" NOR);
                }

                if (random(1000) == 1)
                {
                        msg = HIW "\n$n" HIW "对$N" HIW "嘿嘿一笑，道：干得不"
                              "赖，有点意思，这个丹玉磨就算是我送给你的礼物吧"
                              "。\n" NOR;

                        message_vision(msg, me, this_object());
                        ob = new("/obj/misc/dymo");
                        ob->move(me, 1);
                        tell_object(me, HIC "\n你获得了一个" + ob->name() +
                                        HIC "。\n" NOR);
                }

                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision(HIY "$N" HIY "把手中的活一甩，嚷嚷道：不干了，不干了！\n"
                       NOR, me);
        me->delete_temp("job/peiyao");
        me->delete_temp("job/step");
        return 1;
}

