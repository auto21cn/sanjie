#include <ansi.h>
#include <room.h>

inherit HELL_ROOM;//注意是MROOM

void create (int level,int num)
{
  set ("short", HIR "魔龙洞" NOR);
  set ("long", @LONG
巨大而凶猛的怪兽游走在你的身边，你恐惧而无助地望着这一切！
到处都是血腥的屠杀场面，使人不寒而栗。
LONG);
     level=10; num=random(2)+1;
    set("exits", ([
              "east" : __DIR__"dong9",
              "south" : __DIR__"dong11",

                 ]));
        set("level",level);//自己可以设定！
      set("alternative_die",1); 
       set("hellfireroom",1); 
        set("npc_npc",num);//自己可以设定！
    set("objects",([
         "/d/hellfire/npc/guai3" : num,
                  
                 ]));

  setup();
  setup2();
   
}
void init2()
{
}
/*
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIW "\n\n你被冰冻得动弹不得。\n\n" NOR);
 ob->start_busy(3);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
*/
void reset()
{
        object guai;
        int i,level;
 
        this_object()->add_temp("npc_times",1);
       if (this_object()->query_temp("npc_times")>10)
       {
        this_object()->set_temp("npc_times",1);
       if(this_object()->qurey("npc_number")> 1){
          for(i=0;this_object()->query("npc_number");i++) { 

                guai=new("/d/hellfire/npc/guai");
                level=this_object()->query("level");
                 guai->create(level,level);
                guai->move(this_object());
                                           }
                                              }
         }
        ::reset();
}


int valid_leave (object who, string dir)
{
  object where = this_object ();
  object obj = present ("monsters",where);



  if (obj)
    return notify_fail ( obj->name()+"露出两眼凶光要吃了你。\n");

  return ::valid_leave (who, dir);
}

