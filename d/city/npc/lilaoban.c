//Last Create  By PKYOU@DHXY 2002/05/04

inherit F_VENDOR_SALE;

void create()
{
  reload("laoli");
  set_name("老李", ({"lao li", "li"}));
  set("title","首饰店老板");
  set("changed", "长安");
  set("gender", "男性");
  set("age", 55);
  set("long","一位满脸笑容，和蔼可亲的老头儿。\n");
  set("attitude", "peaceful");
  set("combat_exp", 20000);
  set_skill("dodge", 100);
  set("vendor_goods", ([
         "1" : "/d/city/obj/touhua",
         "2" : "/d/city/obj/wanlian",
       ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{

  ::init();
  add_action("do_vendor_list", "list");
}
void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

