

#include <ansi.h>

mixed names = ({
        ({
        "朱雀外门","青龙外门","白虎外门","玄武外门","天安门",
        "扬州武馆","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","长白天池","天山脚下",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        }),
        ({
                 "宋兵","流氓","偏将","裨将","佐将","小贩","男孩","郭芙","老先生",
                 "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
                 "静玄师太","静照师太","宋远桥","莫声谷","陆乘风","韩宝驹","黄药师","余沧海",
                 "殷野王","邓百川","尹志平","小龙女","刘承风","欧阳锋","白衣少女","九翼道人",
                 "阿紫","玉磬子","玉音子","岳夫人","岳不群","令狐冲","玄苦大师","清善比丘",
                 "独臂神尼","庄夫人","双儿","吴六奇","木婉清","萧远山","李沅芷","向问天",
                 "曲洋","黑白子","程瑶迦","程瑶迦","沐剑屏","天柏道人","本尘","本观",
                 "天山童姥","韦一笑","谢逊","澄坚","陆乘风","张翠山","宋青书","玄贞道长",
                 "石破天","苏星河","慕容复","朱丹臣","简长老","封不平",
                 "林震南","史青山","霍先生","钟四嫂","郑镖头","范一飞",
                 "陆冠英","李沅芷","刘菁","曲洋","袁紫衣","丹青生",
                 "刘国轩","乔三槐","天柏道人","程英","甘宝宝","刘承风",
                 "水岱","卓玛","刀白凤","成不忧","曲灵风","崔员外",
                 "康亲王","海公公","神照上人","乌夷老祭司","李可秀","张召重",
                 "彭连虎","钱青健","南海鳄神","余沧海","张淡月","左冷禅",
                 "星宿派号手","星宿派鼓手","采花子","丁当","进喜儿","吴青烈",
                 "马青雄","无量剑弟子","神农帮弟子","贵公子","舞蛇人","波斯商人",
                 "阿拉木罕","苏州少女","养蚕女","金花","贡唐仓国师","阿紫",
        }),
        });

string ask_jianxi()
{     
        object guo,ob;
        object *team;
        int i=0,count=0,minexp,maxexp;
        string where;
        guo =this_object();
        ob=this_player();
          
        if (guo->query_condition("zzz_busy"))
                return "目前尚未占卜出有魔界妖魔私自偷盗仙宫宝物。";//guo busy time 
          
        if(ob->query("combat_exp")<500000)
                return  "以你目前的修为尚不能担此大任。";//too low exp
        team=ob->query_team();
        count=sizeof(team);
       //write("\n"+sprintf("%d",count));
        if(count<=1)
                return "就你一个人恐怕势单力薄。"; //too few people
        if(count>=6)
                return "此事不宜张扬，还是人少为妙。"; //too many people
        minexp=team[0]->query("combat_exp");
        maxexp=minexp;
      
        for(i=1;i<count;i++)
        { if(team[i]!=0)
          { if(team[i]->query("combat_exp")<minexp)
                minexp=team[i]->query("combat_exp");
            if(team[i]->query("combat_exp")>maxexp)
                maxexp=team[i]->query("combat_exp");
          }
        }
        if ((maxexp-minexp)>1000000)
                return "你们的武功相差太过悬殊。";//exp too far
     //check ok
      
          where=names[0][random(40)];
          guo->apply_condition("zzz_busy",30);
          ob->set_temp("team_count",count);
          ob->apply_condition("zzz_busy",60);
          for(i=0;i<count;i++)
          //team[i]->set_temp("zzz_job_zhuji",1);
          team[i]->apply_condition("zzz_busy",60);
          for(i=100;i*i*i/10<=maxexp;i++);
          call_out("job",60,ob,where,i,count+2);
          //message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路?\n"NOR, obj);
          return    "三界不幸：听说魔界一窃贼偷盗了天宫的法宝。\n"+
                        "         你们速速去"+where+"设防阻截，抢回法宝后传送(chuansong)回天宫。\n"+
                            "          各路妖魔鬼怪肯定会去接应他，你们多加小心。"; 
}


void job(object ob,string where,int maxpot,int ckiller)
{    
        object *team,obj,gift;
        object guo=this_object();
        int i=0;
        //team=ob->query_team();
        //for(i=0;i<sizeof(team);i++)
        if(environment(ob)->query("short")!=where && ob->query_condition("zzz_busy"))
        {
             tell_object(ob, HIY "\n你拦截的地方不对吧！窃贼已经逃逸了，你任务失败了！\n" NOR); 
        }
        guo->apply_condition("zzz_busy",0);

        if(environment(ob)->query("short")==where&&ob->query_condition("zzz_busy"))
        { if (ckiller>0)
             { if (random(20)>16)
                  { obj=new(__DIR__"yaomoguiguai");   
                    obj->do_copy(ob,maxpot,3);
                    obj->set("nickname",HIY"天下第一魔"NOR);     
                    obj->move(environment(ob));
                    obj->kill_ob(ob);
                   }
                else 
                   { obj=new(__DIR__"yaomoguiguai"); 
                     obj->do_copy(ob,maxpot,1);
                     
                     obj->move(environment(ob));
                     obj->kill_ob(ob);
                     obj=new(__DIR__"yaomoguiguai");
                     if (random(20)>10)
                        { obj->do_copy(ob,maxpot,2);
                          obj->set("nickname",HIY"魔王座下护法"NOR);
                         }
                     else 
                         obj->do_copy(ob,maxpot,1);
                         obj->move(environment(ob));
                         obj->kill_ob(ob);
                    }  
                 call_out("job",120,ob,where,maxpot,ckiller-1);
              }
          else 
              { if (present("yaomo guiguai",environment(ob)))
                   {//present menggu dahan,then mission failed
                      tell_room(environment(ob),HIC"魔界帮凶妖魔鬼怪挥挥手，示意窃贼先走。\n魔界窃贼匆匆忙忙的离开了。\n"NOR);
                      tell_object(ob, HIY "\n盗贼逃逸了，你任务失败！\n" NOR); 
                    }
                else{
                                obj=new(__DIR__"thief"); 
                                obj->do_copy(ob,maxpot);
                                obj->set("nickname",HIR"妙手空空"NOR);
                                obj->move(environment(ob));
                                message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路？\n"NOR, obj);
                                obj->kill_ob(ob);
                                gift=new(__DIR__"fabao");
                                gift->set_temp("host",ob->query("id"));
                                gift->move(obj);
                     }
              }
         }
      else
              tell_object(ob, HIY "\n窃贼偷偷溜出了天宫，你任务失败！\n" NOR); 
          
              return;

}                       
       
           
       
     





