inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "山谷");
        set("long", HIG @LONG 此处有些稀疏的树木，眼前矗立着一座千层叠翠、万里点苍的
山峰，围成一处幽谷，中有一泓清潭，泉水从峰间奔流而下，喷珠
泄玉，直入清潭，还有几只小精灵正在潭边飞舞。此处空气清凉湿
润，沁人心肺，四周却看不见任何明显的出路，看来，你只好四处
转转(around)看了。
LONG
        ); 
        set("exits", ([
        ]) );

        set("objects", ([
          "/d/quest/tulong/npc/hunter": 1,           
          "/d/quest/tulong/npc/spirit1": 3,          
          "/d/quest/tulong/obj/kaolu": 1,        
        ]) );

        setup();
}
void init()
{
        add_action("do_west", "xifang");   
        add_action("do_around", "around");

}

int do_around(string arg)
{
   object me, room;

   me = this_player(); 
   if (random(20)<10)
   { 
   tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n");
   room = find_object(__DIR__"spirit0");
   if(!objectp(room)) room=load_object(__DIR__"spirit0");
   me->move(room);
   return 1;
   }
   else  
   tell_object(me, "你发现西边似乎有条路(xifang)。\n\n");   return 1;
}
 
int do_west(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$N往西边的树林走去 . \n", me);

        room = load_object(__DIR__"spirit3");
        if(room) me->move(room);

        return 1;
}



