 //
// edquiz.c
// writed by stey sanjie-lib

inherit F_CLEAN_UP;

string k;
int main(object me, string arg)
{
        int i;
        mapping quizz;
        string str;

        if (! SECURITY_D->valid_grant(me, "(immortal)"))
                return 0;

        seteuid(getuid());

        if (! arg) return notify_fail("你要增加什么 question？\n");


        if (sscanf(arg, "-c %d", i))
        {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("没有这道题，或者数字超出题库数目。\n");

                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("没有这道题，或者数字超出题库数目。\n");
                write("第"+i+"问题类型:  "+quizz["type"]+"\n");
                write("第"+i+"问题内容:  "+quizz["data"]+"\n");
                write("第"+i+"问题答案:  "+quizz["answer"]+"\n");
         return 1;
        }
         if (sscanf(arg, "-cut %d", i))
        {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("没有这道题，或者数字超出题库数目。\n");

                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("没有这道题，或者数字超出题库数目。\n");
                write("第"+i+"问题类型:  "+quizz["type"]+"\n");
                write("第"+i+"问题内容:  "+quizz["data"]+"\n");
                write("第"+i+"问题答案:  "+quizz["answer"]+"\n");
                if(QUIZ_D->delete_quiz(i))      write("cut ok\n");
         return 1;
        }
         if (sscanf(arg, "-m %d", i))
         {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("没有这道题，或者数字超出题库数目。\n");
                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("没有这道题，或者数字超出题库数目。\n");
                write("第"+i+"问题原类型:  "+quizz["type"]+"\n");
                write("第"+i+"问题原内容:  "+quizz["data"]+"\n");
                write("第"+i+"问题原答案:  "+quizz["answer"]+"\n");
                write("第"+i+"问题进入修改：\n");
                write("题库 第"+i+"问题———问题类型：(例：如果是历史题，请输入历史以中文为主)：\n->");
                k="m";
                log_file("cmds/edquiz", sprintf("%s(%s) modify quiz %s on %s.\n",
                 me->name(1), geteuid(me), arg, ctime(time()) ) );
                input_to("get_type", i,k);
                return 1;
           }

        if (arg == "-add")
           {

          i=QUIZ_D->sizeof_quiz();
          k="add";

          log_file("cmds/edquiz", sprintf("%s(%s) modify quiz %s on %s.\n",
                 me->name(1), geteuid(me), arg, ctime(time()) ) );
          write("题库 第"+(i+1)+"问题———问题类型：(例：如果是历史题，请输入“历史”_以中文为主)：\n->");
           i++;
          input_to("get_type", i,k);

          return 1;
            }
        return notify_fail("你要增加什么 question？\n");
}

int get_type(string msg,int i,string k)
{
          mapping pattern;
          int j,m,ppl;
           pattern=([]);
/*
        if(CHINESE_D->is_chinese(msg) !=1 && strlen(msg)> 24)
                {
                 write("（请输入中文）问题类型：\n->");
                 input_to("get_type", i,k);
                  return 1;
                }
*/
        
        if(msg=="q")   return 1;
         
         j=strlen(msg);
         for(m=0;m<j;m+=2){
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("你输入的文字中间带了空格，。\n（请输入中文）重新输入问题类型：\n->");
                        input_to("get_type", i,pattern,k);
                       return 1;
                      } 
        
        pattern["type"]=msg;
        write("题库 第"+i+"问题———问题答案：\n->");
        input_to("get_answer", i,pattern,k);
        return 1;
}
int get_answer(string msg,int i, mapping pattern,string k )
{

         int j,m,ppl;
         if(msg=="q")   return 1; 
         
         if(strlen(msg)<1)
                {
                write("\n->");
                input_to("get_answer", i,pattern);
               
               return 1; }
          
          j=strlen(msg);  
          ppl=0;
         for(m=0;m<j;m+=2){
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("你输入的文字中间带了空格。\n（请输入中文）重新输入问题答案：\n->");
                        input_to("get_answer", i,pattern,k);
                       return 1;
                      } 
 
        if(strlen(msg)<1)
                {
                write("你输入的文字太短可能引起误会。\n->");
                input_to("get_answer", i,pattern);
                }
        pattern["answer"]=msg;
        write("题库 第"+i+"问题——问题内容：\n->");
        input_to("get_data", i,pattern,k);
        return 1;
}

int get_data(string msg,int i, mapping pattern ,string k)
{
        int m,j,ppl;
         if(msg=="q")   return 1;
         if( msg[j..j]==" " )
                {write("你输入的文字后面带有空格。\n（请输入中文）重新输入问题答案：\n->");
                 input_to("get_data", i,pattern,k);
                 return 1;}
        if((j=strlen(msg))<10)
                {
                write("你输入的文字太短可能引起误会。\n（请输入中文）重新输入问题内容：\n->");
                input_to("get_data", i,pattern,k);
                  return 1; }
        ppl=0;
         for(m=0;m<j;m+=2){
/*
                     if (msg[m] < 176 || msg[m] > 247)  { ppl++;continue;}
                     if (msg[m+1] < 161 || msg[m] > 254) { ppl++;continue;}
                     if (msg[m] == 215 && msg[m+1] > 249) {ppl++;continue;}
*/  
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("你输入的文字中间有单字节字串或者带了空格，请保持双字节结构方便加入随机码。\n（请输入中文）重新输入问题内容：\n->");
                       input_to("get_data", i,pattern,k);
                       return 1;
                      }
        pattern["data"]=msg;
        write("\n第"+i+"问题类型为："+pattern["type"]);
        write("\n第"+i+"问题答案为："+pattern["answer"]);
        write("\n第"+i+"问题内容为："+pattern["data"]);
        write("\n如果你确认无错，请用yes,重新修改请用no！请严格查误，防止被骂！\n");
        input_to("get_comfirm", i,pattern,k);
        return 1;

}
//137  int get_comfirm(string msg,int i, mapping pattern ,string k)
int get_comfirm(string msg,int i, mapping pattern)
{
                if(msg=="no")
                {
                        write("题库 第"+i+"问题——问题类型：\n->");
                        input_to("get_type", i,k);
                        return 1;
                }
              if(msg=="yes")
              {

                if( k=="add")
                {
                QUIZ_D->add_quiz(pattern);
                write("quiz 增加结束。\n");
                return 1;
                }
                if( k=="m")
                {
                QUIZ_D->set_quiz(i,pattern);
                write("quiz 修改结束。\n");

                return 1; }
                return 1;
               }
        write("\n如果你确认无错，请用yes,重新修改请用no\n");
        input_to("get_comfirm",i,pattern,k);
        return 1;
}


int help(object me)
{
write(@HELP
指令格式 : edquiz [-add]                  (增加)
          edquiz [-c|-m|-cut] <NO.>     (查看|修改|删除)
          输入时用q取消
这个指令可以修改，删除 题库NO.x题 或列出其内容。
-add 参数 会增加 题库的最后一题。
HELP );
    return 1;
}




