// quiz_d.c
// writed for sanjie-lib 10-22-2002,stey


#include <ansi.h>

#define QUESTION DATA_DIR + "static/question"
inherit F_DBASE;
inherit F_SAVE;



string random_add(string strn)
{
        string *ran_s,str;
        int i,j,k;
        str="";
        ran_s=({"■","●","▲","★","◆","〓",});

        k=random(sizeof(ran_s));
         j=strlen(strn);

         if(j<8) return strn;
         for(i=0;i<j;i+=2){

        if (strn[i] < 176 || strn[i] > 247)  { str +=strn[i..i+1];continue;}
        if (strn[i+1] < 161 || strn[i] > 254) { str +=strn[i..i+1];continue;}
        if (strn[i] == 215 && strn[i+1] > 249) {str +=strn[i..i+1];continue;}
           if(random(100)<20)
           str +=ran_s[k]+strn[i..i+1];
           else str +=strn[i..i+1];

        }

        return str;
}
mapping *quiz = ({});

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
        seteuid(ROOT_UID);
        restore();
}

void remove() { save(); }

string query_save_file() { return QUESTION; }



int sizeof_quiz()
{
        return sizeof(quiz);

}
void add_quiz(mapping pattern )
{
        quiz += ({pattern});
        save();
}


void set_quiz( int i,mapping pattern)
{         quiz -=({quiz[i]}); quiz +=({pattern});
        save();
}
void delete_quiz( int i)
{
        quiz -=({ quiz[i]});
        save();
}
void dump_quiz()
{
        string  str;
        mapping q;
        int i;

        str = "";

        for(i=0; i<sizeof(quiz); i++)
                {
                        q=quiz[i];
                        str +="QUIZ NO."+i+" :"+"type: "+q["type"]+"answer: "+q["answer"]+"\n";
                        str +="QUIZ NO."+i+" :"+"Data: "+q["data"]+"\n";
                }
        write_file("/QUIZ_DUMP", str);
}



mapping query_quiz(int i)
{

        mapping def;

        if (i<0 || i > sizeof(quiz))
        return 0;
        def=quiz[i];
        if (mapp(def)) return def;
        return def;

}

/**start to ask question**/

string comfirm_answers(object obj,object victim,string answers)
{
        string str,qqn,name;
        int i;

        if(obj->query("question")!="on")
                return obj->name()+"现在没什么疑问！？\n";

// add by mudring.
        if(obj->query("question")=="done")
                return obj->name()+"的疑问已经解决了！？\n";

        name=obj->query("quiz/q_name");

        if(victim->query("id")!=obj->query("quiz/id"))
           return name+"说道：该来的不来，不该来却来了！\n";

         if((int)obj->query("quiz/time")+900 < time())
           return name+"已经消失了。\n";

         if(answers==obj->query("quiz/answer"))
         {
                i=victim->query("quiz_num")+1;
                str=name+"恭喜你答对了！你目前已经正确回答了"+i+"道题！不过你必须到禅房领悟！\n";
                if (i % 35 == 0)
                 {
                      i = i % 35 + 1;
                        i=200000+i*50;
                  victim->add("quiz_combat_exp",i);
                  victim->add("quiz_daoxing",i);
                  victim->add("quiz_potential",i/9);
                  victim->add("quiz_balance",1000000);
                  str +=name+"奖励你"+i+"点武学和"+i+"点道行和"+i/9+"点潜能 和100两黄金（已帮你存入银行）。\n";
                  str +=name+"告诉你：你必须到禅房那里领悟才领的到。\n";
                }
                str +=name+"拍拍"+obj->name()+"的头，消失了!"+obj->name()+"终于解除疑惑了!\n";
                obj->set("question","done");
// added by mudring
                return str;
          }else
          {
                str=obj->query("quiz/str");
                str+="\n"+name+"笑着摇了摇头说：继续努力哟！\n";
                return str;
          }
}
//随机计算部分
mapping random_jisuan()
{
        int j,l,k,m,n;
        mapping question,jisuan;
        string *fff;
        string name,str,strddd,strcc,ans;

        
jisuan=([
"加":({"加以","加","加上","再加",}),
"减":({"减去","减掉",}),
"乘":({"的结果乘以","的计算结果乘以",}),
"平方":({"的计算结果的平方","的结果的二次方",}),
"结果":({"，最后结果是什么？","等于什么","，你算的出来吗？","的最后结果等于？","是多少？","就是？","为多少？",}),
"位数":({"个位数","十位数","百位数","千位数","万位数","十万位数","百万位数","千十万位数","亿位数","十亿位数",}),
]);     
        
        
        j=random(2)+2;
        l=random(50)+1;
        strcc=chinese_number(l);
       
        for(k=0;k<j;k++)
        {
                switch(random(15))
                    {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                               m=random(20)+1;
                               l +=m;
                               fff=jisuan["加"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                                m=random(20)+1;
                                l -=m;
                                fff=jisuan["减"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 9:
                        case 10:
                        case 11:
                        case 12:
                                m=random(12)+1;
                                l *=m;
                                fff=jisuan["乘"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 13:
                        case 14:

                                l =l*l;
                                fff=jisuan["平方"];
                                strcc +=fff[random(sizeof(fff))];
                               break;
                        }
                }

/*
       if(random(20)>5 && l >2)
                {
                  n=random(4)+1;
                  ans=""+l;
                  n=random(strlen(ans));
                  if (n>8) n=8;
                  ans=ans[n..n];
                  fff=jisuan["位数"];
                  strcc +="计算后的结果的"+fff[n];
          
                  }else ans=""+l;
*/
                 ans=""+l;
        

        fff=jisuan["结果"];
        strcc +=fff[random(sizeof(fff))];
         
//        strddd=random_add(strcc);
        question=([]);
        
                  question["type"]="随机计算题";
                  question["data"]= strcc;
                  question["answer"]=ans;
                  
                  return question;

}

//随机题库部分

mapping random_ask_question()
{
        int i,j,k,m,n,rs;
        mapping question,quesss;
        string *ran_s,*breaks_str;
        string strddd,ans,ge,type;
        
        i=random(sizeof(quiz));
        question = quiz[i];
        
        ran_s=({"■","●","▲","★","◆","〓",});
        breaks_str=({"分开","间隔","分隔",});
        if(random(100)<3)
         {

                strddd=question["data"];
                ans=question["answer"];

          }else{
                n=random(4)+1;
                rs=random(sizeof(ran_s));
                

                switch(random(4))
                        {
                        case 0:
                             strddd=question["data"]+"！注意！请把答案用一个空格间隔连续输入"+chinese_number(n+1)+"次！";
                             ge=" ";
                             break;
                        case 1:
                             rs=random(sizeof(ran_s));
                             if(random(2)==0)
                             {strddd=question["data"]+"！呵呵！请你将答案连续粘贴一起"+chinese_number(n+1)+"次并用一个空格间隔！";
                             ge=" ";}
                             else {
                                strddd=question["data"]+"！呵呵！请你将答案连续粘贴一起"+chinese_number(n+1)+"次并用"+ran_s[rs]+breaks_str[random(3)]+"！";
                                ge=ran_s[rs];}
                                
                             break;                     
                        case 2:
                             strddd=question["data"]+"！呵呵！粘贴答案连续输入"+chinese_number(n+1)+"次！不要间隔。";
                             ge="";
                             break;                       
                        case 3:
                             strddd=question["data"]+"！呵呵！请你使用一个"+ran_s[rs]+breaks_str[random(3)]+",连续输入"+chinese_number(n+1)+"次！";
                             ge=ran_s[rs];
                             break;
                          }
                          
                          
                ans=question["answer"];
                for(k=0;k<n;k++) ans +=ge+question["answer"];

                }
                 quesss=([]);
        
                  quesss["type"]  = question["type"];
                  quesss["data"]  = strddd;
                  quesss["answer"]= ans;
             
             return quesss;

}
void random_quiz(object obj,object victim)
{
        string *s_name,*f_name,*h_name,*run,*speetch,*askk;
        string name,str,strddd,ans,type;

        mapping questions;

        int i,j,k,l,m,n;
s_name=({
        "伶俐的","可爱的","美丽的","活泼的","机灵的","调皮的","古灵精怪的",
          });
f_name=({
        "小小","小","蓝","绿","鬼","银","白","黄","青",});
h_name=({
        "精灵","鬼头","丫头","妹妹","宝宝","玉童","小天使","孩儿","灵童","神童",
        });
run=({
        "",
        "突然跑出来",
        "不知哪里帽出来"
        "笑嘻嘻的跑过来",
        "从一道光芒走出来",
        "蹦蹦跳跳的过来",
        "迷迷忽忽的走来",
        });
speetch=({
        "问道，",
        "提出了个问题：",
        "说了句话，",
        "小声嘀咕句话，",});
askk   =({
        "请问以下问题答案是什么？\n",
        "如下的问题是什么答案？\n",
        "阁下可知如下的答案吗？\n",
        "你可解答这个问题吗？\n"
        "你能帮我解决这个问题吗？\n",
        "这个问题问题呀，好难呀，你能帮我吗？\n",});

        name=s_name[random(sizeof(s_name))]+f_name[random(sizeof(f_name))]+h_name[random(sizeof(h_name))];

        str=name+run[random(sizeof(run))]+speetch[random(sizeof(speetch))]+askk[random(sizeof(askk))];
     if(random(100)>65)
     {
       questions=random_jisuan();
        
        }
        else{
       questions=random_ask_question();
            }
         strddd=random_add(questions["data"]);
         ans=questions["answer"];
         type=questions["type"];
        str +=strddd + "\n";
        obj->set("question","on");
        obj->set("quiz/answer",ans);
        obj->set("quiz/type",type);
        obj->set("quiz/no",i);
        obj->set("quiz/id",victim->query("id"));
        obj->set("quiz/q_name",name);
        obj->set("quiz/str",strddd);
        obj->set("quiz/time",time());
        tell_object(victim,HIG+str+NOR+"\n");


}


