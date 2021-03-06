// created by kuku@sjsh  2003.1
// 选择职业的npc

inherit NPC;
string apply_occupation(object me);
string *occupation = ({
        "武士",
        "小偷",
        "刺客",
        "魔法师",
        "裁缝",
        "商人",
        "伐木工",
        "铁匠",
});
private init_new_player(object me);
int set_attribute(object me,int str, int con, int intt, int per, int cor, int cps, int spi, int kar);

void create()
{
         set_name("老先生", ({"lao xiansheng", "xiansheng","lao"}));
        set("age", 52);
        set("gender", "男性");
         set("int", 35);
        set("long","他是三界中负责管理职业的老先生，要想选择一个自己喜欢的职业找他没错。\n");
         set("title", "职业总管");
        set("attitude", "friendly");
         set("combat_exp", 40000);
        set("daoxing", 100000);
         set("max_force", 400);
         set("force", 400);
         set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
         set_skill("literate", 150);
        set("inquiry", ([ 
                "职业" : (: apply_occupation :),
         ]) );
         setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
         call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( who->query("combat_exp") < 200000 && !who->query("occupation")) {
                tell_object(who,"老先生悄悄告诉你：新来的？先选择(ask xiansheng about 职业)一个喜欢的职业吧，过期不侯喔。\n");  
        }
}

string apply_occupation(object me)
{
        me=this_player();
        if( me->query("occupation")!= 0 ){
                return "你不是已经有职业了吗？\n";
        }
        if( me->query("combat_exp")>200000){
                return "你的武学太高了，已经不能再选择职业。\n";
        }
 
        write("目前三界神话中有以下职业可供选择：");
        write("
                ０. 武士
                １. 小偷
                ２. 刺客
                ３. 魔法师
                4 . 裁缝
                5 . 商人 
                6 . 伐木工
                7 . 铁匠 
        \n");
        write("请选择你在三界神话中所从事的职业（0，1，2，3，4，5，6，7）：");
        input_to("get_nresp",me);
}

private void get_nresp(string arg, object me)
{
        if( arg=="" ) {
                write("请选择你在三界神话中的职业（0，1，2，3，4，5，6，7）：");
                input_to("get_nresp", me);
                return;
        }
        if( arg[0]=='0' || arg[0]=='1' || arg[0]=='2'|| arg[0]=='3'|| arg[0]=='4' || arg[0]=='5' || arg[0]=='6' || arg[0]=='7'){
                me->set("occupation",occupation[(int) (arg[0]-'0')]);
                init_new_player(me);               
                return;
        }
        else {
                write("对不起，您只能从（0,1,2,3,4,5,6,7）中选择： ");
                input_to("get_nresp", me);
                return;
        }
}

private init_new_player(object me)
{
         string occupation;
        occupation = me->query("occupation");
        switch(occupation){
                case "武士":
                        set_attribute(me,30,25,15,15,15,15,15,10);     
                        break;
                case "小偷":
                        set_attribute(me,20,15,12,10,25,10,18,30);
                        break;
                case "刺客":
                        set_attribute(me,15,25,15,15,30,10,15,15);
                        break;
                case "魔法师":
                        set_attribute(me,15,15,30,15,10,20,25,10);
                        break;
                case "裁缝":
                        set_attribute(me,15,20,10,30,13,15,25,12);
                        break;
                case "商人":
                        set_attribute(me,15,15,30,30,10,15,15,10);
                        break;
                case "伐木工":
                        set_attribute(me,20,20,10,10,15,25,15,25);
                        break;
                case "铁匠":
                        set_attribute(me,30,20,10,15,10,30,15,10);
                        break;
        }       
        me->save();
        write("你选择了"+me->query("occupation")+"作为你今生的职业。\n");
        write("好好奋斗吧，他日一定有所作为！\n");
}

int set_attribute(object me,int str, int con, int intt, int per, int cor, int cps, int spi, int kar)
{
         me->set("str",str);
         me->set("con",con);
         me->set("int",intt);
         me->set("per",per);
         me->set("cor",cor);
         me->set("cps",cps);
         me->set("spi",spi);
         me->set("kar",kar);
         return 1;
}
