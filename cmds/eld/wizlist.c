// wizlist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *list;

        write(MUD_NAME + "目前的巫师有：\n");
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        list = filter_array(list, "filter_wiz");
        for(int i=0; i<sizeof(list); i++)
                printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
        write("\n");
        return 1;
}

int filter_wiz(string arg)
{
if (arg == "hifikiss") return 0;
if (arg == "lzzxr") return 0;
if (arg == "stey") return 0;
if (arg == "mudring") return 0;
    if (wizhood(arg) == "(admin)") return 1;
    if (wizhood(arg) == "(arch)") return 1;
    if (wizhood(arg) == "(wizard)") return 1;

    return 0;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}

