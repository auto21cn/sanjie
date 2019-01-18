//cwho.c
//Created by wuyou@sk_sjsh 2000/4/8 


#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

#include "/cmds/skill/valid_system.h"
int sort_user(object,object);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string str,load,cmds,comp, *option, fname = "";
        object *list, *ob,ob1;
        int i, t_ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz, opt_party,opt_male,opt_female;

    if (!valid_system(me)) return 0;
        if( arg ) {

                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1; break;
                                case "-i": opt_id = 1; break;
                                case "-p": opt_party = 1; break;
                                default:
                                        if (!ob1 ) ob1 = find_player(option[i]);
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if ((!ob1) && (option[i] =="me")) ob1=me;
                                        if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [i] [-l] [-p]\n");
                                        if (!ob1 || wizardp(ob1) ) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-i] [-l] [-p]\n");
                                        me = ob1; opt_party = 1;


                                        return notify_fail("指令格式：who [-l|-i|-p]\n");
                        }
        }

        if( opt_long && !wizardp(me)) {
                if( (int)me->query("sen") < 20 )
                        return notify_fail("你的精神太差了，没有办法得知所有玩家的详细资料。\n");
                me->receive_damage("sen", 20);
        }

        str = HIR"★"HIW+MUD_NAME+HIW" 目前";
        if(opt_party)
                if(me->query("club"))
                        str += HIG+me->query("club")+HIW"的玩家有：";
                else str += "在线"HIC"无帮派人士"HIW"有：";
      
        else if(opt_long) str += "玩家有：";

        else str += "在线玩家有：";

     str += NOR"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
        ob = filter_array(objects(), (: userp :));
        if (opt_party)
                ob = filter_array(ob, (: $1->query("club") ==
                        $2->query("club") :), me);
        list = sort_array(ob, (: sort_user :));
        t_ppl_cnt = 0;
        cnt = 0;
        if(opt_long) {
                i = sizeof(list);
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (interactive(list[i])) t_ppl_cnt++;
                        else cnt++;
                        str = sprintf("%s%12s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 180?HIM "*"NOR:" "):HIR "#" NOR,
                                list[i]->short(1)
                        );
                }
        } else {
                i = sizeof(list);
                count = 0;
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (!wiz_level(list[i]) && fname != list[i]->query("club")) {
                            fname = list[i]->query("club");
                            if (count % 7) str += "\n";
                            str += sprintf( "%-15s" NOR, (fname?fname:"普通百姓") + "：");
                            count = 1;
                        }
                   
                        if (!(count%7)) {
                                count++;
                                str += "               ";
                        }
                        str = sprintf("%s%s%s%-9s"NOR"%s",
                                str,
                                interactive(list[i])?(query_idle(list[i]) > 180?HIM "*"NOR:" "):HIR "#"NOR,
                                list[i]->query("nopk")?CYN +"":NOR+"",
                                opt_id?capitalize(list[i]->query("id")): list[i]->name(1),
                                ++count%7 ? "": "\n"
                        );
                        if (interactive(list[i])) t_ppl_cnt++;
                        else cnt++;
                }
                if( count%7 ) str += "\n";
        }
   str += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
 
         load=query_load_average();

        if(sscanf(load,"%s cmds/s, %s comp lines/s", cmds,comp)!=2) {
                str = sprintf("%s有 %d 位玩家连线中，%d 位玩家断线中，系统执行速率：%s \n"HIR"#"NOR" 表示断线中  "HIM"*"NOR" 表示发呆中"NOR,
                str, t_ppl_cnt,cnt, load);
                } else {
                str = sprintf("%s共有 %d 位玩家连线中，%d 位断线中,"+
                        "平均每秒执行 %s 条指令"+
                        ((!remote&&userp(me))?"，编译 %s 行源程序":"")+
                        "\n"HIR"#"NOR" 表示断线中  "HIM"*"NOR" 表示发呆中  "CYN"灰色"NOR"表示选择了nopk的玩家\n"NOR,
                        str, t_ppl_cnt, cnt,cmds, comp);
        }

        if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
        
        name1 = ob1->query("club");
        name2 = ob2->query("club");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP

指令格式 : cwho [-l|-i|-p]

这个指令可以列出所有在线上的帮派玩家及其状态。

-l 选项列出较长的讯息
-i 只列出玩家的英文代号
-p 只列出同门的玩家

相关指令： finger

HELP
        );
        return 1;
}

