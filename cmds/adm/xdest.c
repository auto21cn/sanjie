// xdest.c
// by xiaofeng.

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object where, *list;
        int i, number;

        if ( me != this_player(1))
                return notify_fail(geteuid(this_player(1)) + "强迫你使用" + file_name(this_object()) +"命令失败!\n");
        if (!str) return notify_fail("Which file do you what to dest?\n");
 
        str = resolve_path(me->query("cwd"), str);
        if( sscanf(str, "%*s.c") != 1 ) str += ".c";
        me->set("cwf", str);
   
        if( file_size(str) < 0 )
                return notify_fail("没有这个文件：" + str + ")\n");

        list=children(str);
        number=sizeof(list);
        if(number)
                for(i=0;i<sizeof(list);i++) destruct(list[i]);
        write("ok!\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : xdest filename

dest all copies (master and cloned)
of a given file in the mud.

HELP
    );
    return 1;
}

