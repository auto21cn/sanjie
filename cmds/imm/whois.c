//whois.c

int main(object me, string arg)
{
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
	if( ! arg )
		return notify_fail("whois <中文名字>\n");

printf("%s", NAME_D->who_is(arg));
	return 1;
	
}


int help(object me)
{
    write(@HELP
指令格式：whois <中文名字> 
 
这个指令可以根据玩家的中文名字查出相应的英文ｉｄ。 
HELP
    );
	return 1;
}

