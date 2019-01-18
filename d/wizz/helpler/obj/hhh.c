#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIR "节日红包" NOR, ({"hongbao", "hong bao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "东方财神制作的节日礼物，祝大家快乐,赶快开拆（chai）红包把！。\n");
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
        int exper,dx,tt1,tt2,qn,improve=0;

        object baoshi,me;
        me = this_player();


        if (!id(arg))
        return notify_fail("你要拆什么？\n");

        if(random(400)<2)
        {
         baoshi=new("/d/quest/baoshi/baoshi");
        
         "/d/quest/baoshi/baoshi"->changename(baoshi,1+random(7));
          baoshi->move(me);
         message_vision(HIY"东方财神对$N道，恭喜恭喜，你拿到安慰奖了。\n"NOR,me);
         message_vision(HIY"$N拿到一个"+baoshi->name()+"。\n"NOR,me);
         destruct(this_object());
         return 1;
         }
         else if( random(1000) < 2)
        {
        dx= me->query("daoxing");
        qn= me->query("potential");
        if( (int)me->query("potential") > (int)me->query("learned_points"))
                        qn=(int)me->query("potential")-(int)me->query("learned_points");

        exper = me->query("combat_exp");
        improve=exper/50+random(exper/30)+3000;
        tt1= qn/100+random(qn/100)+300;
        tt2= dx/100+random(dx/100)+300;
        if(tt2 > 20000) tt2=20000;
        if(improve > 20000) improve=20000;
        message_vision(HIY"东方财神对$N道，恭喜恭喜，你拿到二等奖了。\n"NOR,me);
        me->set("daoxing",dx + tt2);
        message_vision(HIY+me->name()+"的道行大增"+tt2+"点。　\n"NOR,me);
        me->set("combat_exp",exper+improve);
        message_vision(HIY+me->name()+"的武学增加"+improve+"点。　\n"NOR,me);
        me->add("potential",tt1);
        message_vision(HIY+me->name()+"的潜能大增"+tt1+"点。　\n"NOR,me);
        }else
        {
               tell_object(me,HIY"突然东方财神现身对$N叹道，可惜呀，就差了一点，你就能拿到二等奖继续努力吧。\n"NOR);

         

          if( random(2500) < 2 && random(20)==1)
           {
                message_vision(HIY"恭喜发财,"+me->name()+"中了头奖。　\n"NOR,me);
         
                me->add("balance",30000000);
                message_vision(HIY+me->name()+"的存款增加了3000两黄金。\n"NOR,me);
             }
             else {
                tell_object(me,HIY"恭喜发财,"+me->name()+"没有中头奖,可惜呀,下次再来吧。　\n");
                  if (random(1500) <2 && random(6)==1)
                  {
                  baoshi=new("/d/quest/baoshi/baoshi");
                  baoshi->move(me);
                  "/d/quest/baoshi/baoshi"->changename(baoshi,29+random(7));
                  message_vision(HIY"东方财神对$N道，恭喜恭喜，你拿到特别奖了。\n"NOR,me);
                  message_vision(HIY"$N拿到一个"+baoshi->name()+"。\n"NOR,me);
                  }
                  }
         }
           
        destruct(this_object());
        return 1;


}




