// weapond.c
// added by steywen@21cn.com 10/12/2002

#pragma save_binary
#include <ansi.h>
#include <combat.h>
#define WW_NAME       0
#define WW_ID         1
#define WW_VALUE      2
#define WW_HARM       3
#define WW_MAR        4

void remove_broken_weapon(object ob);
int sharpless(object obj);

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "割伤",
                "action":               "$N挥动$w，斩向$n的$l",
                "parry":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "slice": ([
                "damage_type":  "劈伤",
                "action":               "$N用$w往$n的$l砍去",
                "dodge":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "chop": ([
                "damage_type":  "劈伤",
                "action":               "$N的$w朝著$n的$l劈将过去",
                "parry":                -20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "hack": ([
                "action":               "$N挥舞$w，对准$n的$l一阵乱砍",
                "damage_type":  "劈伤",
                "damage":               30,
                "dodge":                30,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "thrust": ([
                "damage_type":  "刺伤",
                "action":               "$N用$w往$n的$l刺去",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N的$w往$n的$l狠狠地一捅",
                "damage_type":  "刺伤",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "wave": ([
                "action":               "$N一扬$w，朝$n的$l一挥",
                "damage_type":  "鞭伤",
                "dodge":                -20,
                "parry":                30,
                ]),
        "whip": ([
                "action":               "$N将$w一扬，往$n的$l抽去",
                "damage_type":  "鞭伤",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N用$w往$n的$l直戳过去",
                "damage_type":  "刺伤",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "rake": ([
                "action":               "$N高举$w，往$n的$l死命一筑",
                "damage_type":  "筑伤",
                "dodge":                -15,
                "parry":                15,
                ]),
        "strike": ([
                "action":               "$N一个大舒臂抡起$w，对着$n的$l往下一砸",
                "damage_type":  "筑伤",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N挥舞$w，往$n的$l用力一砸",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N高高举起$w，往$n的$l当头砸下",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":               "$N手握$w，眼露凶光，猛地对准$n的$l挥了过去",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N将$w对准$n的$l射了过去",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
        "shoot": ([
                "action":               "$N弯弓搭箭，只听「嗖」的一声，$w已到$n的$l",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);
string *s_type=({"fire","ice","poison","air","earth",});
mapping name_type=([
   "sword":"剑","stick":"棍","hammer":"锤","staff":"杖","whip":"鞭","axe":"斧","blade":"刀",
   "fork":"叉","spear":"枪","mace":"锏",
]);
static mapping weapon_type = ([
 //类型           中文名     英文名          价值    附加伤害值 武器损害值
   "fire0": ({ HIR"火焰"NOR, "flame",        20000,     10,   30 , }),
   "fire1": ({ HIR"极烈火"NOR, "fire",         40000,     20,   40 , }),
   "fire2": ({ HIR"魔玄火"NOR, "magicfire",    70000,     30,   50 , }),
   "fire3": ({ HIR"天炙火"NOR, "skyfire",     150000,     40,   60 , }),
   "fire4": ({ HIR"火海"NOR, "inferno",     200000,     50,   70 , }),
   "fire5": ({ HIR"艳阳火"NOR, "fire",        250000,     60,   80 , }),
   "fire6": ({ HIR"烈日火"NOR, "inferno",     600000,     70,   90 , }),
   "fire7": ({ HIR"九阳火"NOR, "suns",        800000,     80,   100, }),
   "fire8": ({ HIR"爆裂火"NOR, "explosion",   900000,     95,   120, }),


  "ice0":   ({ HIC"寒冰"NOR, "ice",           20000,      10,   30 , }),
  "ice1":   ({ HIC"玄冰"NOR, "magicice",      40000,      20,   40 , }),
  "ice2":   ({ HIC"炙冰"NOR, "coolest",       70000,      30,   50 , }),
  "ice3":   ({ HIC"天冻"NOR, "skyice",       150000,      40,   60 , }),
  "ice4":   ({ HIC"冰极"NOR, "fearfully ice",      200000,      50,   70 , }),
  "ice5":   ({ HIC"千冰"NOR, "millenary ice",          250000,      60,   80 , }),
  "ice6":   ({ HIC"万冰"NOR, "myriad ice",      600000,      70,   90 , }),
  "ice7":   ({ HIC"九阴"NOR, "nineshade",         800000,      80,   100, }),
  "ice8":   ({ HIC"寒裂"NOR, "iceblow",    900000,      95,   120, }),



 "poison0": ({  HIG"散毒"NOR, "disperse",        20000,      10,   30 , }),
 "poison1": ({  HIG"鹤顶红"NOR, "crane",           40000,      20,   40 , }),
 "poison2": ({  HIG"蛇胆毒"NOR, "serpent",         70000,      30,   50 , }),
 "poison3": ({  HIG"蝎尾毒"NOR, "scorpion",        150000,      40,   60 , }),
 "poison4": ({  HIG"蛾粉毒"NOR, "moth",            200000,      50,   70 , }),
 "poison5": ({  HIG"蛊虫毒"NOR, "gu",              250000,      60,   80 , }),
 "poison6": ({  HIG"腐尸粉"NOR, "ptomaine",        600000,      70,   90 , }),
 "poison7": ({  HIG"妖魂毒"NOR, "evil spirit",        800000,      80,   100, }),
 "poison8": ({  HIG"魔血毒"NOR, "evil",               900000,      95,   120, }),




    "air0": ({ HIW"气暴弹"NOR, "air bomb",           20000,      10,   30 , }),
    "air1": ({ HIW"气箭"NOR,   "air arrow",              40000,      20,   40 , }),
    "air2": ({ HIW"魔气剑"NOR, "air sword",        70000,      30,   50 , }),
    "air3": ({ HIW"神气刀"NOR, "air falchion",   150000,      40,   60 , }),
    "air4": ({ HIW"疾风"NOR,   "high wind",      200000,      50,   70 , }),
    "air5": ({ HIW"烈风"NOR,   "strong wind",      250000,      60,   80 , }),
    "air6": ({ HIW"暴风"NOR,   "strom wind",   600000,      70,   90 , }),
    "air7": ({ HIW"雷电"NOR,   "thunder",       800000,      80,   100, }),
    "air8": ({ HIW"链电"NOR,   "chain thunder",        900000,      95,   120, }),



  "earth0": ({ YEL"五行玄土"NOR, "earth",              20000,      10,   30 , }),
  "earth1": ({ YEL"爆石裂片"NOR, "stone bump",     40000,      20,   40 , }),
  "earth2": ({ YEL"巨石轰顶"NOR, "megalith hit",    70000,      30,   50 , }),
  "earth3": ({ YEL"泰山压顶"NOR, "hill hit",      150000,      40,   60 , }),
  "earth4": ({ YEL"火山裂轰"NOR, "volcano hit",       200000,      50,   70 , }),
  "earth5": ({ YEL"流星火雨"NOR, "star hit",            250000,      60,   80 , }),
  "earth6": ({ YEL"金星撞击"NOR, "hesper bump",      600000,      70,   90 , }),
  "earth7": ({ YEL"九星聚轰"NOR, "stars bump ",    800000,      80,   100, }),
  "earth8": ({ YEL"地裂山崩"NOR, "earthquake",     900000,      95,   120, }),
]);
mapping *base_names = ({

  (["name": HIR"铜","id": "copper",]),
  (["name": HIR"钢","id": "steel",]),
  (["name": HIR"铁","id": "iron",]),
  (["name": HIR"金","id": "gold",]),
  (["name": HIC"灵玉","id": "jade",]),
  (["name": HIC"翠玉","id": "greenjade",]),
  (["name": HIC"霞玉","id": "sunjade",]),
  (["name": HIC"彩玉","id": "colourful jade",]),
  (["name": HIY"虎啸","id": "tiger",]),
  (["name": HIY"鱼肠","id": "harmful",]),
  (["name": HIY"龙吻","id": "dargonkiss",]),
  (["name": HIY"凤凰","id": "phoenix",]),
  (["name": HIW"雷龙","id": "thunder dragon",]),
  (["name": HIW"狂龙","id": "mad dradon",]),
  (["name": HIW"暴龙","id": "fury dragon",]),
  (["name": HIW"神龙","id": "deity dragon",]),
  (["name": HIW"光明","id": "light",]),
  (["name": HIW"黑暗","id": "dark",]),
  (["name": HIW"邪恶","id": "evil",]),
  (["name": HIW"正气","id": "justice",]),
  (["name": HIR"精灵","id": "spirit",]),
  (["name": HIR"天灵","id": "genius",]),
  (["name": HIR"神灵","id": "jinni",]),
  (["name": HIR"恶灵","id": "ahriman",]),
  (["name": BLINK+HIR"天界","id": "sky circles",]),
  (["name": BLINK+HIR"人界","id": "human circles",]),
  (["name": BLINK+HIR"地界","id": "abuttals",]),
  (["name": BLINK+HIR"神界","id": "gods circles",]),
  (["name": BLINK+HIR"三界巫师","id": "sanjie koradji",]),
  (["name": BLINK+HIR"三界巫神","id": "sanjie powwow",]),
  (["name": BLINK+HIR"三界天皇","id": "sanjie emperor",]),
  (["name": BLINK+HIR"三界天神","id": "sanjie deity",]),

});
varargs mapping query_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("verbs");

        // 4/27/98 mon changed following 4 "hit" to "impale"
        // as "hit" is not defined in weapon_actions.
        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }
}

varargs mapping query_apply_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("apply/verbs");

        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
                }
                weapon->add_amount(-1);
        }
}


void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2;
        string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon")) {
                  sharp1=weapon->query("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "cuprum" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                   case "silver" : z1=30 ;break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" :z1=40 ; break;
// 这样diamond是不磨损的，也避免了他可以轻易打断其他兵器。
//                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break ;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
 //                 case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }
                wap = (int)weapon->weight() / 500 +z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500 +z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$N只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",
                          random(300)+60,ob);
                        //added by mon 10/27/97
                        victim->reset_action();
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }
}

void fleshings_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2, onfall;
        string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->quary("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "bronze" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                  case "silver" : z1=30 ; break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" : z1=40 ; break;
//                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break ;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
//                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }
                    if (z1> 50)
                       z1=50;
                   onfall=(int)me->query("str")
                              -(int)victim->query("str");
                     if (onfall>20)
                           onfall=20;
                     else
                        {if (onfall<5)
                            onfall=5;}
           {
                wap = (int)weapon->keenness()
                                          + z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                                          + z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > wdp / 2 )
                 {

                        if (ob->query("weapon_prop/damage")>20)
                             {
                                            message_vision(HIW "$N只听得手中" + ob->name() + "[嘇啷]一声，原来是被削断一节！！\n" NOR,
                              victim);
                              ob->unequip();
                              ob->add("weapon_prop/damage", -onfall);
                              if (ob->query("weight") > 200)
                              ob->add("weight", -200);// xintai 3/18/2001
                              ob->wield ();
                             }
                        else
                            {
                                            message_vision(HIW "$N只觉得手中一轻，" + ob->name() + "被砍成两段！！\n" NOR,
                              victim);
                              ob->unequip();
                              ob->move(environment(victim));
                              ob->set("name", "断掉的" + ob->query("name"));
                              ob->set("value", 0);
                              ob->set("weapon_prop", 0);
                              ob->set("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,ob);
                              victim->reset_action();
                            }

                }
                  else     {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                            }
          }  }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}
void update_weapon(object ob)
{
  int ii,i, j,k,kk,ppl,hr,val;
    mapping nkl,mkl;
    string name,ad_type,type,ty,idd,*kn,*id,long;
   // k=random(100);
   long=ob->query("long");
/*   long+="天地初开之时，盘古开天的时代已经出现一个神秘的大师，他掌握天地间古今所有灵物秘密，/n
         +"就此他制做的许多武器已成后世各种神魔使用的宝物利器，后来在三界他化作无形灵气四处游荡，/n"
         +"于是三界就不断出现各种利器，此物乃其灵气所制，绝世罕有的武器！/n";
*/
    for (j = 0;j < 8; j++)
        {

       if(random((j+1)*(j+1)*40) < 5)
       {
        i=random(4)+j*4;
        ppl=1;
        break;
        }
        }
        if(ppl!=1)  i=random(8);

        nkl=base_names[i];
        ty=ob->query("skill_type");
        name=nkl["name"]+name_type[ty]+NOR;
        id=({nkl["id"]+ty,ty});
        ob->set("weapon_prop/damage", (48+i*2+random(i+1)));
        ob->set("w_lvl",i);
      long +="此乃一"+ob->query("unit")+nkl["name"]+name_type[ty]+"。/n"+NOR;

        hr=(48+i*2+random(i+1))*10;
       val=(i+1)*200000+(random(i+1)*20000);
      for(kk=0;kk<sizeof(s_type);kk++)
       {
        if(random(100)>80)
        {
                        ppl=0;
                         for (j = 0;j < 9; j++)
                         {

                        if(random((j+1)*(j+1)*40) < 5)
                        {
                        ii=j;
                         ppl=1;
                         break;
                         }
                         }
                         if(ppl!=1)ii=random(3);
                ad_type=s_type[kk]+ii;
                ob->set("h_w_"+s_type[kk],ii);
                val+=weapon_type[ad_type][WW_VALUE];
                hr+=(weapon_type[ad_type][WW_MAR])*10;
                ob->set("weapon_prop/"+s_type[kk]+"_damage",weapon_type[ad_type][WW_HARM]);
                long +="此物具有"+weapon_type[ad_type][WW_NAME]+"特殊攻击,伤害值:  "+HIC+weapon_type[ad_type][WW_HARM]+"/n"+NOR;
        }
        }
    ob->set("weapon_scar",hr);
   long +="此物损坏耐度值为:  "+hr+"度。/n";

    ob->set("long", long);


}
string get_look_msg(object weapon)
{
	string str,*c_type,ad_type;
	int i,k;
	
	c_type=({"火系","冰系","毒系","气系","土系",});
	str="\n----------------------------------------------\n\n";
	str+=sprintf("武器战斗经验： %-8d 损坏耐度值:  %-8d\n",weapon->query("combat_exp"),weapon->query("weapon_scar"));
	for(i=0;i<sizeof(s_type);i++)
    {
    if(weapon->query("h_w_"+s_type[i]) >=0 )
    {k=weapon->query("h_w_"+s_type[i]);
    ad_type=s_type[i]+k;
    str +=sprintf(WHT"%s特殊攻击"NOR":[%s]:%-12d\n",c_type[i],weapon_type[ad_type][WW_NAME],weapon->query("weapon_prop/"+s_type[i]+"_damage"));
    } 
    else str +=sprintf(WHT"%s特殊攻击"NOR":[%s]:%-12d\n",c_type[i],"  无  ",0);
    }
       return str;
}
void update_baoshi(object weapon,int bl,int i)
{
         object b_weapon;
        string ad_type;
        int k,l,j,ppl;
        mapping weapon_prop=([]);
               if(i >= sizeof(s_type)) i-=sizeof(s_type);
        k=0;
        
        weapon_prop = weapon->query("weapon_prop");
        if(weapon->query("weapon_prop/"+s_type[i]+"_damage"))
            k=weapon_prop[s_type[i]+"_damage"];


        k +=(bl/2);
        weapon_prop[s_type[i]+"_damage"]=k;
        for(j=0;j<9;j++)
        {
         if ( k > (j+1)*100 ) continue;
         else {
               ad_type=s_type[i]+j;
               weapon->set("look_w_msg/"+s_type[i],weapon_type[ad_type][WW_NAME]);
               weapon->set("h_w_"+s_type[i],j);
               break;
              }
         }
        weapon->add("add_baoshi",1);
       
        weapon->add("weapon_scar",bl*20);
        weapon->set("weapon_prop",weapon_prop);
        weapon->add("weapon_sp",1);
      b_weapon=find_object(base_name(weapon));
      destruct(b_weapon);
     return;

}
int radio(int vs)
{
    if (vs>300) return 100;
    return vs/300;
}
int do_s_attack(object me,object victim,object weapon)
{
    object shield;
    mapping my, your, action, victim_action;
    string limb, *limbs,*sst, result,fail_hit_msg,hit_ob_msg,sh_name;
    string ad_type,attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int i,k,ap, dp, pp, afp, vfp,sp,vd;   //afp: attacker->force power, vfp: victim->force power
    int damage, damage_bonus, defense_factor,force_adj;
    int wounded = 0;
           limbs = victim->query("limbs");
           limb = limbs[random(sizeof(limbs))];
            afp = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);

            vfp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);

                my = me->query_entire_dbase();
                your = victim->query_entire_dbase();

             if (weapon->query("use_apply_skill"))
            attack_skill = weapon->query("apply/skill_type");
        else
            attack_skill = weapon->query("skill_type");

       ap = COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        if( ap < 1) ap = 1;

       dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if (!userp(me)) ap *=3;
        if (!userp(victim)) dp *=3;
        if (random(ap+dp) < dp) return 0;

        
           sst=s_type;
        for(i=0;i<sizeof(s_type);i++)
        {
         if(!me->query_temp("apply/"+s_type[i]+"_damage"))
         sst -=({ s_type[i] });
        }
        i=random(sizeof(sst));
        k=weapon->query("h_w_"+s_type[i]);
        ad_type=s_type[i]+weapon->query("h_w_"+s_type[i]);
        hit_ob_msg="$N的"+weapon->name()+"突然发出"+weapon_type[ad_type][WW_NAME]+"攻击！\n";
        
        damage=me->query_temp("apply/"+s_type[i]+"_damage");
        if(!me->query_temp("apply/vs_"+s_type[i]+"_damage"))
           vd =1;
            else vd = me->query_temp("apply/vs_"+s_type[i]+"_damage");
          vd = radio(vd);
          damage *=(120-vd)/100;
        if(objectp(shield=victim->query_temp("armor/shield")))
          { sp=shield->query("weapon_prop/damage");
           
             if (sp < damage) damage -=sp;
               else {
                  damage=0;
                  weapon->add("weapon_scar",-2);
                  hit_ob_msg+="但是全打在$n的"+shield->name()+"上了。$n丝毫没有损伤。\n";
                  message_vision(hit_ob_msg,me,victim);
                  return damage;  
                    }
          }
        
         victim->receive_damage("kee",damage , me);
        weapon->add("combatd_exp",1);
        weapon->add("weapon_scar",-1);
        
//        hit_ob_msg="$N的"+weapon->name()+"突然发出"+weapon_type[ad_type][WW_NAME]+"攻击！\n";
                  message_vision(hit_ob_msg,me,victim);
        COMBAT_D->report_status(victim,damage);
        if(weapon->query("weapon_scar")<0)
        {   message_vision(HIW "$N只觉得手中一轻，" + weapon->name() + "被砍成两段！！\n" NOR,
                              me);
                              weapon->unequip();
                              weapon->move(environment(victim));
                              weapon->set("name", "断掉的" + weapon->query("name"));

                              weapon->set("value", 0);
                              weapon->delete("weapon_prop", 0);
                              weapon->delete("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,weapon);
        }
         
         if( damage >0 && random(damage) > (int)victim->query_temp("apply/armor") )
                {
                    // We are sure that damage is greater than victim's armor here.
                    victim->receive_wound("kee",
                        damage - (int)victim->query_temp("apply/armor"), me);

                }
                return damage;
}
