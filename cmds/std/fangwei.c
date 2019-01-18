#include <ansi.h>
inherit F_CLEAN_UP;
int X=20,Y=20;
int main(object me, string arg)
{
        object *obj,env;
        int pos,xx,yy,zz,c,i,ppl;
        string str,str3,strdd,strmm,struu,strme,output;

        if(me->query("kee")<40)
                return notify_fail("你的体力不太好了，先休息一下吧！\n");
        me->add("kee",-20);

        env=environment(me);
        if(!env->query("hellfireroom"))
              return notify_fail("这里不是立体房间！\n");

//      if(!arg) arg="here";

           pos=3;
           ppl=10;
        if(env->query("position_max") && (env->query("position_max") > 2 && env->query("position_max") < 8 ))
            pos=env->query("position_max");
        obj =all_inventory(env);

          for(i=0;i<sizeof(obj);i++)
         {
                     if (!obj[i]->query_temp("position"))
                      {
                        obj[i]->set_temp("position/xx",20-(pos-1)+random((2*pos)-1) );
                        obj[i]->set_temp("position/yy",20-(pos-1)+random((2*pos)-1) );
                        obj[i]->set_temp("position/zz",0);
                      }


         }

         //****//
         str=""; str3="";  strme="";strdd="";strmm="";struu="";
         for(yy=Y+(pos-1);yy>Y-(pos);yy--)
         {
                if(yy!=Y-(pos-1) || yy !=Y+(pos-1))
                str3+="━━";

                ////
                str+=HIW"┃"NOR;
                for(xx=X-(pos-1);xx<X+pos;xx++)
                {
                         c=0;
                        if(me->query_temp("position/xx")==xx
                                    && me->query_temp("position/yy")==yy)
                         {
                                str +=BLINK HIR "YOU "NOR;
                                strme="你的  (坐标方位)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                       +me->name()+"("+me->query("id")+")\n";
                                obj -=({ me });
                                c=2;
                          }
                        if(sizeof(obj)==0 && c!=2 ){ str +=BBLU HIG" xx "NOR; continue; }


                        
                        //
                        for(i=0;i<sizeof(obj);i++)
                        {
                                if(!obj[i]->query("name")|| !obj[i]->query("id"))
                                {
                                        str +=BBLU HIG" xx "NOR;
                                        continue;
                                }

                                if(obj[i]->query_temp("position/xx")==xx
                                    && obj[i]->query_temp("position/yy")==yy)
                                 {
                                        ppl++;c++;
                                        zz=obj[i]->query_temp("position/zz");


                                        if(c ==1) str +=BBLU HIY"MO"+ppl+NOR;
                                        switch(zz)
                                             {
                                             case 0:
                                                    strdd +="MO"+ppl+"  (坐标方位)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                             case 1:
                                                    strmm +="MO"+ppl+"  (坐标方位)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                             case 2:
                                                    struu +="MO"+ppl+"  (坐标方位)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                              }
                                   }
                             }
                             //
                             if(c==0) str +=BBLU HIG" xx "NOR;


                      }////
                      str+=HIW"┃\n"NOR;
              }
                //****//
        output  = HIW"┏━"+str3+"┓\n"NOR+str+HIW"┗━"+str3+"┛\n"NOR+strme;
        if (strdd!="") output += "地面:\n"+strdd;
        if (strmm!="") output += "空中:\n"+strmm;
        if (struu!="") output += "顶上:\n"+struu;
      write(output+"\n");
      return 1;
}

int help()
{
        write(@HELP
        即时房间方位图 v1.0 (Write By stey 200/12/08)
        命令用法：fangwei
        例子：
　　　　┏━━━━━━━━━━━━━━━┓
　　　　┃ xx  xx  xx  xx  xx  xx  xx ┃
　　　　┃ xx  xx  xx  xx MO11 xx  xx ┃
　　　　┃ xx  xx YOU  xx  xx  xx  xx ┃
　　　　┃ xx  xx  xx  xx  xx  xx  xx ┃(这行中间的xx坐标为X:0,Y:0)
　　　　┃ xx  xx MO12 xx  xx  xx  xx ┃
　　　　┃ xx  xx  xx  xx  xx  xx  xx ┃
　　　　┃ xx  xx  xx  xx  xx  xx  xx ┃
　　　　┗━━━━━━━━━━━━━━━┛
你的  (坐标方位)X:-1,Y:1  :地狱烈火(stey)
地面:
MO11  (坐标方位)X:1,Y:2  :四爪毛头(four claw bad-kid)
MO12  (坐标方位)X:-1,Y:-1  :小脚蝙蝠(small feet bat)

注释：
　　以上的图例xx:表示房间的每个方位或者方块。YOU表示你在房间所处的位置，MO11,MO12,
表示怪或者物品的所在的方位。如果你想走到MO12的面前就用gogogo south;gogogo sooth;
这样你就走到怪的面前，如果想到MO11面前就有两种走法，一、gogogo northeast;gogogo east;
二、gogogo north;gogogo east,gogogo east；房间出口有固定方位，例如east出口就在
房间方位图的右边中间的方位，你必须用gogogo指令走到那里，再使用gogo指令出去这个房间
(gogo实际就是go指令,目前暂用gogo指令，以后就是go指令)。而坐标指数是方便大家看的，
面前房间有三层平面这样就构造了一个简单的立体方位，一般怪在空中的，洞顶上和地面上，而
玩家和物品多数在地面上，注意不同层面的方位，玩家一般走不到的，必须使用角色神通才能到
达其他层面，而坐标是在一起的，这个图下面有注明不同层次有什么怪物！要理解这个图是所有
层次的坐标映射！以后可以用fangwei up;fangwei middle;fangwei stairs;来查看顶上，
空中，地面的层次有什么怪物！

HELP);
        return 1;
}

