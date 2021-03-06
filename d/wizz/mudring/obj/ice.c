// cigarette.c

inherit ITEM;

void init()
{
        add_action("do_smoke", "xiyan");
}

void create()
{
        string *order = ({"中华","大前门", "柔和七星", "红塔山", "万宝路", "希尔顿", 
"云烟", "圣罗兰", "骆驼", "三五", "玉溪", "骄子", "capri", "沙龙"});
        set_name( (order[random(sizeof(order))]), ({ "cigarette", "yan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盒香烟，可以(xiyan)。\n");
                set("unit", "盒");
                set("count",8);
                set("value", 50000);
        }
}


int do_smoke()
{
        object me = this_player();
        object obj = this_object();

        if(environment(me)->query("sleep_room"))
                return notify_fail("睡房里不准抽烟！\n");
        if(environment(obj) != me)
                return notify_fail("你是在看烟吧？\n");
        if(query("master") && query("master") != me->query("id"))
                return notify_fail("这烟已经点燃了，而且不是你的烟。\n");
        add("count",-1);
        me->start_busy(1);
        me->add("combat_exp", 5);
        switch(query("count")) {
                case 1: message_vision("$N猛吸了一口剩下的烟屁股，两根手指夹住一弹，扔掉了烟头。\n", me);
                        break; 
                case 2: message_vision("$N吐出一串烟圈，看着它悠闲地散开。\n", me);
                        break;
                case 3: message_vision("$N闭上眼睛，深深地吸了一口$n，又从鼻孔中喷出来：“爽啊！爽啊！”\n", me, obj);
                        break;
                case 4: message_vision("$N狠狠的吸了一口$n，大概是吸得太猛了，一张脸涨的通红。\n", me, obj);
                        break;
                case 5: message_vision("$N吸了一口$n，摇头晃脑地说道：“饭后一支烟，赛过活神仙。”\n", me, obj );
                        break;
                case 6: message_vision("$N翘起二郎腿，眯上眼睛，猛吸了一口$n，自言自语道：“这东西害人又害己，为啥我还那么喜欢？”\n", me, obj);
                        break;
                case 7: set("master", me->query("id"));
                        message_vision("$N抽出一支$n，点着了火，美滋滋地吸了起来。\n", me, obj);
                        break;
                default:
                        break;
        }        
        if(query("count") > 1) call_out("do_smoke", 10);
        else destruct(obj);
        return 1;
}

