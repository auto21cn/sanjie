#include <ansi.h>
inherit NPC;
void create()
{
        set_name("魔礼红", ({ "tian wang", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "男性" );
        set("long",
                "魔家四将之一，使一杆方天画戟，秘授一把伞。名曰：「混元伞。」\n"
                "伞皆明珠穿成，有祖母绿，祖母碧，夜明珠，辟尘珠，辟火珠，辟水\n"
                "珠，消凉珠，九曲珠，定颜珠，定风珠。还有珍珠穿成「装载乾坤」\n"
                "四字，这把伞不敢撑，撑开时天昏地暗，日月无光，转一转乾坤晃动。\n"
        );
        set("age",50);
        set("title", "广目天王");
        set("attitude", "heroism");
        set("str",60);
        set("spi",60);
        set("int",30);
        set("max_kee",6100);
        set("kee",6100);
        set("max_sen",5100);
        set("sen",5100);
        set("combat_exp",5500000);
        set("daoxing",5500000);
        set("force",6000);
        set("max_force",3000);
        set("mana",3500);
        set("max_mana",5000);
        set("force_factor", 300);
        set("mana_factor",250);


        set("eff_dx", 3500000);
        set("nkgain", 800);

        
        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",380);
        set_skill("dodge",400);
        set_skill("spear",320);
        set_skill("bawang-qiang",350);
        set_skill("force",350);
        set_skill("spells", 350);

        set_skill("moshenbu", 300);
        map_skill("dodge", "moshenbu");
        map_skill("parry", "bawang-qiang");
        map_skill("spear","bawang-qiang");
        map_skill("unarmed", "yingzhaogong");
        set("inquiry", ([
                "name" : "在下广目天王魔礼红，奉圣谕把守东天门。",
                "here" : "这里就是东天门, 入内就是天界了。",
        ]) );

        setup();
        carry_object("/d/obj/weapon/spear/huaji")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("san",3+random(3),me,ob);  
  ::
kill_ob(ob);
}


void san (object me, object ob)
{
  object huobing;
  int damage;

  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision (HIY"$N从怀中抽出降魔伞，低声念了几声咒语，降魔伞如天罗地网般向；$n罩来！\n"NOR,me,ob);

  if ( ((int)ob->query_skill("dodge", 1)+ random(50)) > 400 )
     message_vision (HIY"$N纵身跃到降魔伞顶，闪过了这一击。\n"NOR,ob);
  else 
    {
     message_vision (HIY"结果$N被罩住不能行动！\n"NOR,ob,me);
     ob->start_busy(10+random(5));
    } 

  remove_call_out ("san");  
  call_out ("san",random(5)+5,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N吓得撒腿就跑。\n"NOR,me);
  destruct (this_object());
  return ;
}
