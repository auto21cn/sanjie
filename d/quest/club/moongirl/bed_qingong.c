// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "床上");
        set ("long", @LONG

你身处在一张铺着蚕丝软被的象牙床上。
LONG);
        
        set("exits", ([
                "out": __DIR__"sleep",
            ]));
        set("sleep_room",1);
        set("if_bed",1);                             
                 
        setup();
}


