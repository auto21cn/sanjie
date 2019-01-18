// cigarette.c

#include <ansi.h>

inherit ITEM;

void init()
{
//  9          add_action("do_drink", "hebei");
          add_action("do_drink", "he");
}

void create()
{
        string *order = ({MAG"玛格丽特"NOR,HIR"血腥玛丽"NOR, HIC"海角乐园"NOR, HIW"白夫人"NOR, HIY"长岛的日落"NOR, HIB"夏日骑士"NOR, 
HIG"十一月的海风"NOR, HIM"桃色的周末"NOR});
        set_name( (order[random(sizeof(order))]), ({ "booze", "wine" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一杯色彩诱人的鸡尾酒，你忍不住想喝下去(he)。\n");
                set("unit", "杯");
                set("count",8);
                set("value", 50000);
        }
}


int do_drink()
{
        object me = this_player();
        object obj = this_object();

/*
        if(environment(me)->query("sleep_room"))
                return notify_fail("别在睡房里喝酒！\n");
*/
        if(environment(obj) != me)
                return notify_fail("看着这杯酒很是心醉吧？\n");
        if(query("master") && query("master") != me->query("id"))
                return notify_fail("这可不是你的酒杯，别拿错了。\n");
        add("count",-1);
        me->start_busy(1);
        me->add("combat_exp", 5);
        switch(query("count")) {
                case 1: message_vision("$N喝完醉后一口酒，脸蛋儿变得通红。\n", me);
                        break; 
                case 2: message_vision("$N斜依在椅子上，望着杯子里剩下的一点酒开始想心事。\n", me);
                        break;
                case 3: message_vision("$N又喝了一口，突然感觉万般的心事从心底泛起。\n", me, obj);
                        break;
                case 4: message_vision("$N觉得身体里开始微微地发热，不由地吃吃笑了起来。\n", me, obj);
                        break;
                case 5: message_vision("$N把喝进口里的酒含在醉里，细细地品尝了一会才喝了下去。\n", me, obj );
                        break;
                case 6: message_vision("$N端着酒杯走到窗前，望着窗外的景色。\n", me, obj);
                        break;
                case 7: message_vision("$N端着酒杯走到窗前，望着窗外的成群的MM,不禁垂涎欲滴,哈喇子流了一地。\n", me, obj);
                        break;
                case 8: set("master", me->query("id"));
                        message_vision("$N拿着$n，不由地为那艳丽的色彩所吸引。\n", me, obj);
                        break;
                default:
                        break;
        }        
        if(query("count") > 1) call_out("do_drink", 10);
        else destruct(obj);
        return 1;
}

