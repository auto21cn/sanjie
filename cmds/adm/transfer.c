#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me,string arg)
{
        string mud, file, msg, *files;
        if ( me != this_player(1))
                return notify_fail(geteuid(this_player(1)) + "强迫你使用" + file_name(this_object()) +"命令失败!\n");
        if (!arg) 
                return help(me);
        if (sscanf(arg, "%s %s", mud, file)!= 2 )
                return help(me);
        file = resolve_path(me->query("cwd"), file);
        if (file_size(file) < 0 )
                return notify_fail("无此文件或为目录!\n");
        msg = read_file(file);
        if (!msg || msg == "")
                return notify_fail("不能传送空文件!\n");
        files = explode(file, "/");
        file = files[sizeof(files)-1];
        "/adm/daemons/network/services/transfer_q.c"->send_msg(me, mud, file, msg);
        write("信息已提交,请等待!\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : transfer MUD_NAME FILE_NAME

向其他名字为MUD_NAME 的mud传送一个名字为FILE_NAME的文件!
HELP
     );
     return 1;
}

