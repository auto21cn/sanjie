// Room: /d/wiz/init.c
// mon 3/18/99
#include <ansi.h>
inherit ROOM;

void show_gift(object me);
string _show_gift(object me);
void do_finish(object me);
void get_start(object me);
void get_type(object me);
string start_room="/d/city/kezhan";
string *index=({
        "str","con","int","spi",
        "cps","per","cor","kar",
        });
mapping giftn=([
        "str":"体格",
        "con":"根骨",
        "int":"悟性",
        "spi":"灵性",
        "cps":"定力",
        "per":"容貌",
        "kar":"福缘",
        "cor":"胆识",
        ]);
mapping gift=([
        "str":20,
        "con":20,
        "int":25,
        "spi":25,
        "cps":20,
        "per":20,
        "kar":20,
        "cor":20,
        ]);

void create()
{
        set("short", "欢迎光临三界神话！\n");
        set("no_fight",1);
        set("no_magic",1);
        set("no_net_dead",1);
  set("exits", ([ 
  "down" : "/d/city/kezhan",
]));
        
        setup();
}

void init()
{
    object me=this_player();
    
    if(!userp(me)) return;
    if(!wizardp(me) && me->query("hell_type") &&
            ((int)me->query("combat_exp")>0 ||
             (int)me->query("daoxing")>0 ||
             (int)me->query("no_gift")==0 )) {
        me->move(start_room);
        return;
    }  
    add_action("do_block","",1);
    add_action("get_start1","start");
    if(me->query("no_gift")) {
      me->set_temp("gifts",copy(gift));
      me->set_temp("gift_left",0);
      call_out("get_start0",0,me);
     return ;
    }
    if(!me->query("hell_type"))
    {   call_out("get_type",0,me);  }
}
void get_type(object me)
{
    if(!me) return;
    write("\n\n          地狱火是三界神话另类主题，它来自外国神话，不同角色不同神话故事！\n");
    write("          请选择如下地狱火角色：（输入1-6数字）\n");
    write("          1：刀剑侠  2：魔法师 3：终结者 4：精灵族  5：野蛮人  6：暗黑地狱使者\n");
    input_to("get_helltype",me);
}
void get_helltype(string arg, object me)
{
    int ind;

    if(!me) return;
    if(!arg || sscanf(arg,"%d",ind)!=1 || ind<=0
            || ind>=7)
             {
             write("请选择如下地狱火角色：（输入1-6数字）\n");
             write("1：刀剑侠  2：魔法师 3：终结者 4：精灵族  5：野蛮人  6：暗黑地狱使者\n");
             input_to("get_helltype",me);
             return;
             }
    switch(ind) {
              case 1:
                       me->set("hell_type","刀剑侠");
                       break;
              case 2:
                       me->set("hell_type","魔法师");
                       break;         
              case 3:
                       me->set("hell_type","终结者");
                       break;
              case 4:
                       me->set("hell_type","精灵族");
                       break;
              case 5:
                       me->set("hell_type","野蛮人");
                       break;
              case 6:
                       me->set("hell_type","暗黑地狱使者");
                       break;
                  }   
        me->move("/d/city/kezhan");
        tell_object(me,"\n\n你选择的角色是"+me->query("hell_type")+"。祝你在三界神话玩的开心！\n");            
        me->save();
        return;
    
}
void get_start0(object me)
{
    if(!me) return;
    
    me->command("start");
}

int get_start1(string arg)
{
    object me=this_player();
    write("\n\n欢迎光临三界神话！\n");
    write(@LONG

在开始你的三界神话历程之前，首先要为自己所创造的人物选择一个
合适的天赋，因为这将对你今后的发展有重大的影响。三界神话中的
人物天赋共有四项（详见 help gifts ），每项由一个十到三十之
间的整数来表示，一般数值越大越好，但各项的总和是固定不变的。
LONG
        );
    get_start(me);
    return 1;
}

void get_start(object me)
{
    if(!me) return;
    show_gift(me);
    input_to("get_input",me);
}

void get_input(string arg, object me)
{
    int ind;

    if(!me) return;
    if(!arg || sscanf(arg,"%d",ind)!=1 || ind<0
            || (ind>3 && ind!=9)) {
        get_start(me);
        return;
    }
    if(ind<8) {
        write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
        input_to("get_number",me,ind);
        return;
    } else {
        write("你确定接受当前的天赋设置吗？[y/n]");
        input_to("get_finish",me);
        return;
    }
}

void get_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
        write("你确定接受当前的天赋设置吗？[y/n]");
        input_to("get_finish",me);
        return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
        do_finish(me);
        return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
        get_start(me);
        return;
    }
    write("你确定接受当前的天赋设置吗？[y/n]");
    input_to("get_finish",me);
    return;
}

void show_gift(object me)
{
    write(_show_gift(me));
}

string _show_gift(object me)
{
    mapping my;
    string result;
    int left;

    if(!me) return "";
    my=me->query_temp("gifts");
    left=me->query_temp("gift_left");
    if(!my) return "";
    
    result=("\n");
    result+="─────────────────────────\n";
    result+=sprintf(
//          " 0. 定力：[%d]        1. 容貌：[%d]\n"+
//            " 2. 胆识：[%d]        3. 福缘：[%d]\n"
//          +" 4. 体格：[%d]        5. 根骨：[%d]\n"+
//           " 6. 悟性：[%d]        7. 灵性：[%d]\n"
            " 0. 体格：[%d]        1. 根骨：[%d]\n"+
            " 2. 悟性：[%d]        3. 灵性：[%d]\n"
             ,
//          my["cps"],my["per"],my["cor"],my["kar"],
            my["str"],my["con"],my["int"],my["spi"]
            );
    result+="─────────────────────────\n";
    if(left)
      result+="你现有"+chinese_number(left)+"点天赋还没有分配。\n";
    result+="请选择你想重新设置哪一项天赋的取值[0-3]，\n"+
        "选择[9]则接受当前的设置：";
    return result;
}

void do_finish(object me)
{
    mapping gt;
    int i, left, ok;
    string *key;
    object env;
    
    if(!me) return;
    left=me->query_temp("gift_left");
    if(left>0) {
        write("你总共可有 90 点天赋，现在还有剩余"+chinese_number(left)
            +"点天赋没有分配。\n");
        write("你是否想继续分配这些剩余点数？[y/n]");
        input_to("continue_finish",me);    
        get_start(me);
        return;
    } else if(left<0) {
        write("Sth wrong, let wiz know.\n");
        return;
    }   

    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
        write("Something wrong.\n");
        return;
    }
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
        write("你的"+giftn["str"]+"、"+
                giftn["con"]+"、"+
                giftn["int"]+"及"+
                giftn["spi"]+"之和不能多于 90 。\n");
        get_start(me);
        return;
    }

    /*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
        write("你的"+giftn["cps"]+"、"+
                giftn["per"]+"、"+
                giftn["kar"]+"及"+
                giftn["cor"]+"之和不能多于 80 。\n");
        get_start(me);
        return;
    }
    */
    
    ok=0;
    while(!ok) {
        gt["cps"]=10+random(21);
        if(me->query("gender")=="男性")
          gt["per"]=10+random(21);
        else
          gt["per"]=15+random(16);  
        gt["kar"]=10+random(21);
        gt["cor"]=80-gt["cps"]-gt["per"]-gt["kar"];
        if(gt["cor"]>=10 && gt["cor"]<=30) ok=1;
    }
    
    key=keys(giftn);
    i=sizeof(key);
    while(i--) {
        if(undefinedp(gt[key[i]])) {
            write("Sth wrong, tell wizard.\n");
            return;
        }
        me->set(key[i],gt[key[i]]);
    }
    me->delete("no_gift");
    me->flush_buffer(); // clear receive message buffer.
    //add by mudring@sjsh
    me->set("env/prompt", "time");
    me->set("env/wimpy", 60);
    tell_object(me,"\n\n\n好！愿您在三界神话玩的愉快！\n\n\n");
    tell_object(me,
        "只见眼前霞光一闪，你已经来到了一个陌生的世界（ｌｏｏｋ）．．．\n\n");

    if (("/adm/daemons/band"
       ->create_char_banned(query_ip_number(me)) == 1 ||
       "/adm/daemons/band"->is_banned(query_ip_number(me)) == 1) 
            && !wizardp(me)) {
            me->move("/d/wiz/guest");
            log_file( "ALLCONT", sprintf("from banned site\n"));
            return;
    }
    env=load_object(start_room);
    tell_object(env,({"\n朵朵祥云忽然涌现在天际。\n\n",
                "\n天边一颗流星倏地划过．．．\n\n",
                "忽听远处惊天动地一声巨响，随即一道金光闪过．．．\n"})
            [random(3)]);
    me->move(env,1);
    me->save();
/*
   me->add("combat_exp",19900);
   me->add("daoxing",20000);
   me->add("maximum_force",600);
   me->add("maximum_mana",600);
   me->add("potential",10000);
*/
    return;
}
    
void continue_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
        write("你是否想继续分配这些剩余点数？[y/n]");
        input_to("continue_finish",me);    
        return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
        get_start(me);
        return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
        me->set_temp("gift_left",0);
        do_finish(me);
        return;
    }
        write("你是否想继续分配这些剩余点数？[y/n]");
        input_to("continue_finish",me);    
    return;
}
void get_number(string arg, object me, int ind)
{
    mapping gt;
    int value, old_value;
    string name;
    
    if(!me) return;
    if(!arg || sscanf(arg,"%d",value)!=1) {
        write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
        input_to("get_number",me,ind);
        return;
    }
    if(value<10 || value>30) {
        write("数值应介于 10 和 30 之间。\n");
        write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
        input_to("get_number",me,ind);
        return;
    }
   
    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
        write("Something wrong.\n");
        return;
    }
    
    name=index[ind];
    old_value=gt[name];
    gt[name]=value;
    
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
        gt[name]=old_value;
        write("你的"+giftn["str"]+"、"+
                giftn["con"]+"、"+
                giftn["int"]+"及"+
                giftn["spi"]+"之和不能多于 90 。\n");
        write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
        input_to("get_number",me,ind);
        return;
    }
/*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
        gt[name]=old_value;
        write("你的"+giftn["cps"]+"、"+
                giftn["per"]+"、"+
                giftn["kar"]+"及"+
                giftn["cor"]+"之和不能多于 80 。\n");
        write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
        input_to("get_number",me,ind);
        return;
    }
 */   
    me->add_temp("gift_left",old_value-value);
    me->set_temp("gifts",gt);
    write("你将"+giftn[name]+"设为"+chinese_number(value)+"。\n");

    get_start(me);
}


int do_block(string arg)
{
    object me=this_player();
    string verb=query_verb();

    if(!userp(me) || wizardp(me)) return 0;
    if(verb=="look" ||
       verb=="help" ||
       verb=="story" ||
       verb=="say") return 0;
       
    return 1;
}


