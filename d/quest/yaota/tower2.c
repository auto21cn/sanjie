#include <ansi.h>
#include <room.h>

inherit MAGIC_ROOM;    //注意是MAGIC_ROOM 不ROOM     
string *list=({
        "yg-moon1","yg-moon2","yg-fangcun","yg-longgong","yg-jjf1","yg-jjf2","yg-hyd1","yg-hyd2","yg-hell","yg-gumu1","yg-gumu2","yg-sanjie1","yg-sanjie2","yg-wzg1","yg-wzg2","yg-wdd2","yg-putuo","yg-pansi","yg-shushan","yg-xueshan",
});

void create (int level,int num)
{
        object obj,wang; 
        int i,value; 
        set ("short", HIB "妖塔二层" NOR);
        set ("long", @LONG
这里妖气弥漫，阴森恐怖，随处可见蓝色的鬼火一闪一闪。
LONG);
        level=15;num=random(3)+1;
//level 是怪的级别，10-30, num 是怪的数目
        set("exits", ([ 
                "up" : __DIR__"tower3",
                "west" : __DIR__"baoku1",
        ]));
        set("level",level);//自己可以设定！
// 房间以后怪的的等级
        set("alternative_die",1); 
        set("magicroom",1); 
//妖塔房间标志，cmds npc 判断所需！
        set("npc_num",num);//自己可以设定！
        set_heart_beat(240);
// 房间以后怪的数目
        set("objects",([       
                __DIR__"npc/yg-moon1" : 1,
                __DIR__"npc/yg-sanjie2" : 1, 
                __DIR__"npc/yg-pansi" : 1,    
        ]));
        setup();
        setup2();
// setup2();不能少
   
}
void init2()
{
}

/* 以下是更新时间、 内容的设定*/
void reset()
{
        object guai;
        int i,level,value;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;i<=this_object()->query("npc_num");i++) { 
                                guai = new("/d/quest/yaota/npc/"+list[random(sizeof(list))]);
                                level=this_object()->query("level");
                                guai->set("level",level);
                                guai->create(value,level);
                                guai->set_skills(level);
                                guai->move(this_object());
                        }
                }
        }
        ::reset();
}

int valid_leave (object who, string dir) 
{ 
        object where = this_object (); 
        object obj = present ("moguai",where);
     
        if (obj) 
                return notify_fail ( obj->name()+"说到：进来这里就别想出去啦，嘿嘿...\n"); 

        return ::valid_leave (who, dir); 
} 
