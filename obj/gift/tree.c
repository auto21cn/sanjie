#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
int do_zhai(string);
void init();
mapping idget = ([]);


void create()
{
        set_name(HIC "圣诞礼"HIR"物"HIG"树" NOR, ({ "liwu tree", "tree"}) );
        set_weight(6000);
        
                set("long", "星灯闪烁美丽灿烂的礼物树，上面有很多小礼物，你忍不住去摘（zhai liwu)。\n
                    @* .☆  ＊/ * . ☆/ ＊。   \n
                       ◢◣。       ◢◣。     \n
                      ◢★◣。     ◢★◣。    \n
                     ◢■■◣。   ◢■■◣。   \n
                    ◢■■■◣。 ◢■■■◣。  \n
                    ︸︸||︸︸ !!︸︸||︸︸    \n
                                                \n
  祝你万事如意，心想事成。           ▍ ★∴      \n
             　　　．．．．▍▍．..．█▍ ☆ ★∵ ....k \n
             　　　◥█▅▅██▅▅██▅▅▅▅▅███◤ \n
             　　　．◥███████████████◤  \n
             　～～～～◥█████████████◤～～～～ \n
                                                                �
                ");
      
         set("no_clean_up", 0);
       
         set("is_monitored",1);
         set("no_get",1);
         setup();
         restore();
         
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
        add_action("do_zhai", "zhai");
}

int do_zhai(string arg)
{
        object ob,me;
        string id,*objs;
        int tt;
        objs=({
               "/u/hanhan/meng/obj/lingzhi",
       
                     });
        me = this_player();

        if (arg!="liwu" )   return 0;

        me = this_player();
        if (!userp(me))     return notify_fail("什么东西!");
        if(me->query("sen")<100)   return notify_fail("你留点精神吧!");

        if (me->query("combat_exp") < 0 && (int)me->query("mud_age")<1800)
                            return notify_fail("你是大米吗?不是？我看挺象!");
         id=me->query("id");
        me->start_busy(3);
        me->add("sen",-50);
        if(!undefinedp(idget[id]) && (idget[id]+1) > time())
      return notify_fail("你刚拿了礼物，不可太贪哟，等等再来吧！\n"); 
        this_object()->restore();
        idget[id]=time();
        this_object()->save();
        ob=new(objs[random(sizeof(objs))]);

        if(ob->move(me))
         {
//       message_vision(HIY"新"+HIC"春"+HIR+"★"+HIB+"快"+HIW+"乐！\n"+me->query("name")+"从礼物树拿到了一"+ob->query("unit")+ob->query("name")+"。 \n"NOR, me); 
                             ob->set("owner",id);
                             ob->set("owner_id",id);
                             ob->set("ownerid",id);
                             ob->set("no_put",1);
                             ob->set("no_give",1);
                             ob->set("no_get",1);
                             ob->set("no_bag",1);
                             ob->set("no_sell",1);
                             ob->set("no_zm",1);
         }else if (ob){destruct(ob);}
        return 1;

}

string query_save_file()
{
        return DATA_DIR+"liwutree.o";
}

void set_save_file(string str)
{
        set("save_file",str);
}

