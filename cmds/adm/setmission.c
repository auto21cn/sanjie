//***************************************
//MUDLIB：Biographies         〓悟空传〓   
//VERSION：Test 1.6.28   
//ENCODING：GB  
//Created Admin：By Waiwai           
//Admin Email：wkzstory@21cn.com         
//***************************************
//CMDS ADM setmission.c
// Last modified by zeus@刀剑笑 Dec.30 1999
//Last modified by waiwai@2001/06/05

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i, flag = 0;
        object ob;
        string mission, wname, wmin, file;
        string *wmission;

//    if( me->query("id") != "waiwai")
//         return notify_fail(CYN"你没有权利使用这个指令！\n"NOR); //By waiwai@2001/06/05

        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s %s", arg, mission)!=2 )
                return notify_fail("指令格式：setmission <使用者> (目前工作动向)\n");

        if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
                return notify_fail(WHT"你只能改变当前在线使用者的任务。\n"NOR);

//        if( jobhood(arg)=="none" )
//                return notify_fail(WHT"你只能改变当前有任务等级巫师的工作动向。\n"NOR);

                mission = COLOR_D->replace_color( mission, 1);
        wmission = explode(read_file("/adm/etc/wizmission"), "\n");
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                if( wname==ob->query("id") ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for( file = "", i=0; i<sizeof(wmission); i++) file += wmission[i] + "\n";
        if(!flag) write_file("/adm/etc/wizmission", ob->query("id") + " " + mission + "\n", 0);
        else      write_file("/adm/etc/wizmission", file, 1);
        message_vision(WHT"$N将$n的工作动向设置为：" NOR+ mission + "  \n"NOR, me, ob);
       //By waiwai@2001/06/05 增加监控以及log.
       CHANNEL_D->do_channel(me, "adm","将"+ob->name()+"("+ob->query("id")+")""的工作动向设置为："NOR+mission+"\n"NOR);  
        log_file( "static/setmission", me->query("name")+"("+me->query("id")+")将" +
                ob->query("name") + "(" + ob->query("id") + ")的工作动向设置为：" + mission + " 时间在：("+ COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()) )) + ") \n" );

        return 1;
}
        
int help(object me)
{
        write(@HELP

指令格式 : setmission <某人> (目前工作动向)

用来改变巫师当前工作任务的说明，配套 wizlist 使用。

HELP
        );
        return 1;
}

