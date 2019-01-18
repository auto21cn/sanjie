#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIR "春节红包" NOR, ({"hongbao", "hong bao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "东方财神制作的节日礼物，祝大家国庆快乐,赶快开拆（chai）红包把！。\n"+
                            "命令格式chai hongbao (0-4)。\n"
                            "0：道行奖励 1：潜能奖励 2：武学奖励 3：宝石奖励  4：黄金奖励！");
                set("value", 100000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," 嘿嘿，做梦吧! \n");
        set("no_drop","这么宝贵的东东，哪能乱扔! \n");
        set("no_give","你太慷慨了吧！\n");
        set("no_put","你别做梦了！\n");
        set("no_sell","这么宝贵的东西，哪里可以买卖的！\n");
       }
        add_action("do_kai", "chai");
       

}

int do_kai(string arg)

{
        object me,newob;
        int exper,dx,tt1,tt2,qn,i,improve=0;

        me = this_player();


        if (!arg)
        return notify_fail("你要拆什么？\n");

       if ( this_object()->query("owner") != me->query("id"))
       {
           message_vision(HIR"\n偷吃礼物，达入天牢。\n"NOR,me);
           me->move("/d/wiz/jail");
           return 1;
       }
      
        
       switch(arg){
        case "hongbao 0":
               dx= me->query("daoxing");
               tt2= dx/60+random(dx/100)+300;
               if(tt2 > 100000) tt2=100000;
               message_vision(HIY"$n对$N道，恭喜恭喜，你拿到春节礼物了。\n"NOR,me,this_object());
               me->set("daoxing",dx + tt2);
               message_vision(HIY+me->name()+"的道行大增"+tt2+"点。　\n"NOR,me);
               break;
        case "hongbao 1":
               qn= me->query("potential");
               if( (int)me->query("potential") > (int)me->query("learned_points"))
                        qn=(int)me->query("potential")-(int)me->query("learned_points");
               tt1= qn/60+random(qn/100)+60;
               me->add("potential",tt1);
               message_vision(HIY"$n对$N道，恭喜恭喜，你拿到春节礼物了。\n"NOR,me,this_object());
               message_vision(HIY+me->name()+"的潜能大增"+tt1+"点。　\n"NOR,me);
               break;
       case "hongbao 2":
               exper = me->query("combat_exp");
               improve=exper/50+random(exper/30)+3000;
               if(improve > 100000) improve=100000;
               message_vision(HIY"$n对$N道，恭喜恭喜，你拿到春节礼物了。\n"NOR,me,this_object());
               me->set("combat_exp",exper+improve);
               message_vision(HIY+me->name()+"的武学增加"+improve+"点。　\n"NOR,me);
               break;
        case "hongbao 3":
                for(i=0;i<3;i++)
                {
                        
                newob=new("/d/quest/baoshi/baoshi");
                newob->move(me);
                }
                message_vision(HIY"$n对$N道，恭喜恭喜，你拿到春节礼物了。\n"NOR,me,this_object());
                message_vision(HIY+me->name()+"等到若干个宝石！。　\n"NOR,me);
                break;
        case "hongbao 4":
                newob=new("/obj/money/gold");
                newob->set_amount((me->query("daoxing"))/10000+1);
                newob->move(me);
                message_vision(HIY"$n对$N道，恭喜恭喜，你拿到春节礼物了。\n"NOR,me,this_object());
                message_vision(HIY+me->name()+"等到"+(me->query("daoxing"))/10001+"两黄金！。　\n"NOR,me);
                break;
       default :
                tell_object(me,"命令格式chai hongbao (0-4)。\n");
                return 1;
        }               
        if( random(400) < 2)
          {
           message_vision(HIY"恭喜发财,"+me->name()+"中了头奖。　\n"NOR,me);
           switch(random(5)){
              case 0:
              me->add("str",1);
              message_vision(HIY+me->name()+"的体格大增一点。　\n"NOR,me);
              me->add("cor",1);
              message_vision(HIY+me->name()+"的胆识又增加了一点。\n"NOR,me);
              break;
              case 1:
              me->add("per",1);
              message_vision(HIY+me->name()+"的容貌又漂亮了一点。\n"NOR,me);
              me->add("cor",1);
              message_vision(HIY+me->name()+"的胆识又增加了一点。\n"NOR,me);
              break;
              case 2:
              me->add("cor",1);
              message_vision(HIY+me->name()+"的胆识又增加了一点。\n"NOR,me);
              me->add("cps",1);
              message_vision(HIY+me->name()+"的定力又增加了一点。\n"NOR,me);
              break;
              case 3:
              me->add("cps",1);
              message_vision(HIY+me->name()+"的定力又增加了一点。\n"NOR,me);
              me->add("str",1);
              message_vision(HIY+me->name()+"的体格大增一点。　\n"NOR,me);
              break;
              case 4:
              me->add("cps",1);
              message_vision(HIY+me->name()+"的定力又增加了一点。\n"NOR,me);
              me->add("per",1);
              message_vision(HIY+me->name()+"的容貌又漂亮了一点。\n"NOR,me);
              break;
                }
                me->add("balance",30000000);
                message_vision(HIY+me->name()+"的存款增加了3000两黄金。\n"NOR,me);
             }
       else {
             message_vision(HIY"恭喜发财,"+me->name()+"没有中头奖,可惜呀,下次再来吧。　\n"NOR,me);

           }
        destruct(this_object());
        return 1;


}


