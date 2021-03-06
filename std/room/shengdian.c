#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
#define SHENGDIAN DATA_DIR + "shengdian/"
void reload(string savename)
{
SAVE_NAME=savename;
if(!restore())
log_file("shengdian_save",sprintf("Failed to restore(%s)     %d.\n",savename,time()));
}

string query_save_file()
{
        string file_names;
        file_names = base_name(this_object());
        if (sscanf(file_names, "/d/shengdian/%s", file_names) == 1)
                return sprintf(SHENGDIAN+"/shengdian_%s",file_names);
         else        
                return sprintf(DATA_DIR SHENGDIAN+this_object()->query("short"));
}

void get_fo_npc()
{
//      NPC_DATAS 在room 那里定义 
        object newob,ob; 
         int  j, k,n,ppl; 
        string id_name,*npc_list;
        
        ob=this_object();
        if(!ob->query("npc_list"))
           {
                newob=new("/d/shengdian/npc/fo_obj");
                newob->move(this_object());
                return;
            }
        
        npc_list=ob->query("npc_list");
        if ((j=sizeof(npc_list))==0) return;
        if (j>13) j=12;   
               for(k=0;k<j;k++)
               {
                if(sizeof(npc_list)==0) continue;
                n=random(sizeof(npc_list));
                newob=new("/d/shengdian/npc/fo_obj");
                newob->set("save_file",SHENGDIAN+"npc/"+SAVE_NAME+"_"+npc_list[n]);
                
                
               if(newob->restore())
                       {
                       npc_list -=({ npc_list[n]});
                       newob->move(ob);
                       ppl++;
                       }    else destruct(newob);
                }
        if(!ppl)
            {
 //               CHANNEL_D->do_channel(this_object(), "sys", "没调用NPC_LIST数据!\n");               
                newob=new("/d/shengdian/npc/fo_obj");
                newob->move(this_object());
                return;
            }
            return;
                
}

void init()
{

        add_action("do_ting", ({"ting chan","ting","zuochan",})); 
 
        set("no_clean_up", 1);
}

int do_ting()
{
        object me,ob,newob,*inv;
        string* npc_list;
        int i;
        
        ob=this_object();
        me=this_player();
        
        if(!metep(me))
           {tell_object(me,"哪来的妖怪，哪里来就哪里去吧！\n");
           return 1;}
           inv=all_inventory(ob); 
         for(i=0;i<sizeof(inv);i++){
      if(inv[i]->query("fo_id")==me->query("id"))
           {tell_object(me,"你的佛身不是在这里吗？！\n");
           return 1;}
                  }
        
        if(me->query("shouli_where")==ob->query("where_name"))
           {
                
               newob=new("/d/shengdian/npc/fo_obj");
                newob->set("save_file",SHENGDIAN+"npc/"+SAVE_NAME+"_"+me->query("id"));
               newob->record(me->query("id"),me);
               newob->save();
               newob->move(ob);
               message_vision("圣殿传来一阵佛乐，$N徐然显现在$n面前。\n",newob,me);
               
           
                if(!(npc_list=ob->query("npc_list")) && sizeof(npc_list)==0)
                              npc_list=({me->query("id"),});
                              else npc_list +=({me->query("id"),});
               me->delete("shouli_where");
               ob->set("npc_list",npc_list);
               ob->save();
               return 1;
            }
        
        if(!(npc_list=ob->query("npc_list")) 
               || sizeof(npc_list)==0 
              || member_array(me->query("id") ,npc_list)==-1)
          {
               tell_object(me,"此处没有你的佛位？！请到如来那里受佛礼！\n"); 
               return 1;
          }
          
             newob=new("/d/shengdian/npc/fo_obj");   
                newob->set("save_file",SHENGDIAN+"npc/"+SAVE_NAME+"_"+me->query("id"));
             if(newob->restore())
               {
                newob->move(ob);
                message_vision("禅堂传来一阵佛乐，$N徐然显现在$n面前。\n",newob,me);
                return 1;
                } 
                else{
                destruct(newob);
                tell_object(me,"佛身找不着了！\n"); 
                return 1;
                }
}               
