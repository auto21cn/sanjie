#include <ansi.h>
#include <room.h>

inherit HELL_ROOM;//ע����MROOM

void create (int level,int num)
{
  set ("short", HIW "��������" NOR);
  set ("long", @LONG
�������������沼����ɫ�����������������亮�⡣
а��ĺڰ����磬һ�ۿ�������ͷ��
LONG);
     level=10; num=random(2)+1;
    set("exits", ([
              "east" : __DIR__"bing13",
               "west" : __DIR__"bing14",
               "north" : __DIR__"bing14",
               "south" : __DIR__"bing9",

                 ]));
        set("level",level);//�Լ������趨��
      set("alternative_die",1); 
       set("hellfireroom",1); 
        set("npc_npc",num);//�Լ������趨��
    set("objects",([
         "/d/hellfire/npc/guai" : num,
                  
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
 tell_object(this_object(), HIW "\n\n�㱻�����ö������á�\n\n" NOR);
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
