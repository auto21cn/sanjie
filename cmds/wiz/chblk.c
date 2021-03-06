// channel block command..
// have a bug that is if one have chblk, will chblk go on
// consider......
// modify by mudring

#include <getconfig.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string who, verb;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! arg)
                return notify_fail("指令格式: chblk <player id>\n");

        if (sscanf(arg, "%s %s", arg, verb) != 2)
                verb = "all";

verb = "all";
        ob = UPDATE_D->global_find_player(arg);
        if (! ob)
                return notify_fail(LOCAL_MUD_NAME() + "并没有这个人！\n");

        if (wiz_level(ob) > 0 && ! is_root(me))
        {
                UPDATE_D->global_destruct_player(ob);
                return notify_fail("你不能关闭巫师的频道。\n");
        }

        if (ob->query("chblk_" + verb))
        {
                UPDATE_D->global_destruct_player(ob);
                return notify_fail("这个人的" + verb + "频道已经被关闭了。\n");
        }

//        ob->delete("channel", 1);
        ob->set("channel/chblk_" + verb, geteuid(me));
//        ob->set("chblk_by", geteuid(me));
        write("你关闭了" + ob->name(1) + "的" + verb + "频道。\n");
        tell_object(ob, me->name() + "关闭了你的" + verb + "频道。\n");
        log_file("cmds/chblk",
            sprintf("%s chblk %s %s at %s.\n",getuid(me), getuid(ob),
            verb, log_time() ));

        UPDATE_D->global_destruct_player(ob, 1);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : chblk <玩家> <频道名>

此命令将关闭某个玩家的频道。

HELP );
        return 1;
}


