inherit ROOM;
void create()
{
         set("short", "小学教育中心");
        set("long", @LONG
   　　这是三界神话蛇口站教育局直属机构小学，校长和辅导员们
 平时就是在这讨论事情的！ 
  墙上一张值日表你可以look biao看看现在是谁当值
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/kezhan",
]));
        set("objects", ([
//        __DIR__"npc/oldman": 1,
                        ]) );
        set("item_desc", ([
                 "biao": @TEXT
                  值日表：
TEXT
        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
  call_other("/obj/board/xiaoxue_b", "???"); 
set("no_magic", 1);  
               setup();
}

void init()   
{
object me=this_player();   
if(userp(me) && me->query("id")!="fay" && me->query("id")!="xhx" && me->query("id")!="bknight" && me->query("id")!="ywuqing" && me->query("id")!="yifei" && !wizardp(me) )   
{
message_vision("\n对不起，您不是小学工作人员，请不要擅自闯入！\n\n",me); 
me->move("/d/city/kezhan");   
}
}
