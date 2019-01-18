#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIW "节日礼物" NOR, ({"jieri liwu", "liwu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "东方财神制作的节日礼物，祝大家节日快乐,赶快开拆（chai）礼物把！。\n");
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
        
        object me = this_player();
 

        if (!id(arg))
        return notify_fail("你要拆什么？\n"); 

/*
       if ( this_object()->query("owner") != me->query("id"))
             {
           message_vision(HIR"\n偷吃礼物，达入天牢。\n"NOR,me);
           me->move("/d/wiz/jail");
           return 1;
           }
*/
        dx= me->query("daoxing");
        qn= me->query("potential");
        if( (int)me->query("potential") > (int)me->query("learned_points"))             
                        qn=(int)me->query("potential")-(int)me->query("learned_points");

        exper = me->query("combat_exp");
        improve=exper/30+random(exper/20)+5000;
        tt1= qn/30+random(qn/20)+5000;
        tt2= dx/30+random(dx/20)+5000;
        me->set("daoxing",dx + tt2);
        message_vision(HIY+me->name()+"的道行大增"+tt2+"点。　\n"NOR,me);
        me->set("combat_exp",exper+improve);
        message_vision(HIY+me->name()+"的武学大增"+improve+"点。　\n"NOR,me);
        me->add("potential",tt1);
        message_vision(HIY+me->name()+"的潜能大增"+tt1+"点。　\n"NOR,me);
           switch(random(4)){
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
     
        destruct(this_object());
        return 1;       
        
       
}

