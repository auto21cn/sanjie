// cityd.c

#pragma optimize
#pragma save_binary

#include <ansi.h> 
#include <combat.h> 

inherit F_DBASE;

#include <combat_msg.h>

//hellfire部分
// 这个用*string会更好.
mapping hellskill_type = ([ //
    "sword"     :   0,
    "blade"     :   1,
    "hammer"    :   2,
    "staff"     :   3,
    "whip"      :   4,
    "axe"       :   5,
    "fork"      :   6,
    "spear"     :   7,
    "mace"      :   8,
    "stick"     :   9,
    "unarmed"   :   10,
    "dodge"     :   11,
]);

mapping skill_attack = ([ //
//                          0      1       2      3     4    5     6      7     8      9       10     11
//                      sword, blade, hammer, staff, whip, axe, fork, spear, mace, stick, unarmed, dodge,
    "刀剑侠"        :   ({100,   100,     20,    20,   10,  30,   10,    10,   10,    20,      65,    80,}),
    "魔法师"        :   ({ 10,    10,      5,   100,   50,   5,    5,     5,    5,     5,       5,    40,}),
    "终结者"        :   ({ 20,    20,     20,    50,   30,  30,   10,    10,  100,    20,      10,    50,}),
    "精灵族"        :   ({  5,     5,      5,     5,   80,  10,   50,    10,   50,   120,      20,    90,}),
    "暗黑地狱使者"  :   ({ 50,    50,     20,    20,  100,  30,  100,    10,   50,     5,      30,    50,}),
    "野蛮人"        :   ({ 80,    80,    100,    20,   10, 120,   10,    10,  100,    60,      80,    70,}),
]);

void create()
{
    seteuid(getuid());
    set("channel_id", "战斗精灵");
}

////***************************地狱火战斗////

varargs int hell_skill_power(object ob, string skill, int usage)
{
        string h_type;
        int status, level, power,sjshlevel,helllevel;

        if( !living(ob) ) return 0;


        sjshlevel=ob->query("level");
        if(sjshlevel<20) sjshlevel=20; //增加等级计算 20级起算
        if(ob->query("hell_type"))
        {
            h_type=ob->query("hell_type");
            if(ob->query("hell_type")=="剑侠") h_type="刀剑侠";
      if(undefinedp(ob->query("hell_type"))) h_type="野蛮人";
        } else h_type="暗黑地狱使者";

        if(!undefinedp(hellskill_type[skill]))
          {
                 helllevel=skill_attack[h_type][( hellskill_type[skill] )];
                 level=ob->query("hell_skill/"+skill);
                 if (!level) level=1;
           } else  {  helllevel=5; level=1;}

        switch(usage) {
                case SKILL_USAGE_ATTACK:

                        level += ob->query_temp("apply/attack");
                        level *=helllevel/100;//角色影响
                        break;
                case SKILL_USAGE_DEFENSE:
                        if( level > 300 )       level += 35 + (level-300)*2/5;
                        else if( level > 200 )  level += 15 + (level-200)/5;
                        else if( level > 100 )  level += 5 + (level-100)/10;
                        else                            level += level / 20;
                        level += ob->query_temp("apply/defense");
                        level =(level * helllevel)/100;
                        break;
                       }

        if( !level ) return (int)ob->query("hell_exp") / 2;

        power = (level*level*sjshlevel) /3;
        power +=  (ob->query("hell_exp")/5);
        if( (status = ob->query("eff_kee")) > 0 )  //受伤的直接影响！
                   power = (status/((int)ob->query("max_kee"))) * power ;

        if( (status = ob->query("eff_sen")) > 0 )
                   power = (status/((int)ob->query("max_sen"))) * power ;

        return power;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//

varargs int hell_attack(object me, object victim, object weapon, int attack_type)
{
        mapping my, your, action;
        string limb, *limbs, result;
        string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
        mixed foo;
        int ap, dp, pp, minflag=0;
        int damage, damage_bonus, defense_factor;
        int flag;
        int cost;

        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();
       if(!userp(me)){ if (me->query_temp("position/zz") != victim->query_temp("position/zz"))
                 { "/d/hellfire/npc/attack"->auto_attack(me,victim);
                    return 1;}
                      }
     if(userp(me) && me->query_temp("position/zz") != victim->query_temp("position/zz"))
                return 0;
     if(me->query_temp("position/xx") != victim->query_temp("position/xx") || me->query_temp("position/yy") != victim->query_temp("position/yy"))
           return 0;

        //
        // (1) Find out what action the offenser will take.
        //
           action = me->query("actions");
    if( !mapp(action) ) {
                    me->reset_action();
                    action = me->query("actions");
                 if( !mapp(action) )
                      {
                       CHANNEL_D->do_channel( this_object(), "sys",
                           sprintf("%s(%s): bad action = %O",
                               me->name(1), me->query("id"), me->query("actions", 1)));
                       return 0;
                      }
                        }
    if (action["name"])
                      me->set_temp("action_name",action["name"]);
        result = "\n" + action["action"] + "！\n";

    //取得me用什么兵器的数据
       if( objectp(weapon) )
               {
                if( weapon->query("use_apply_skill") )
                     attack_skill = weapon->query("apply/skill_type");
                else
                     attack_skill = weapon->query("skill_type");
               }
                else  attack_skill = "unarmed";
        if(undefinedp(hellskill_type[attack_skill]))
                              attack_skill="unarmed";
    limbs = victim->query("limbs");
    limb = limbs[random(sizeof(limbs))];

        /********/

//                      printf("%s\n",result);
        //
        // (2) Prepare AP, DP for checking if hit.
        //


        ap = hell_skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

        dp = hell_skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;
        if( victim->is_busy() ) dp /= 2;

        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];

         //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //
        if( random(ap + dp) < dp )
                  {       // Does the victim dodge this hit?

                result += SKILL_D("dodge")->query_dodge_msg();
                damage = RESULT_DODGE;

                  }
                  else
                    {

                        damage=0;
                        if(me->query("hell_skill/"+attack_skill)>0)
                        damage+=me->query("hell_skill/"+attack_skill);
                        if( action["damage"] )
                                damage += action["damage"];
                                damage+=me->query_temp("apply/damage");
                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage+= foo;
                        if(userp(me)) //specify damage
                        {
                         flag=0;
                             switch(me->query("hell_type"))
                             {
                             case "刀剑侠":
                                if(attack_skill=="sword")
                                flag=me->query("hell_skill/sword");
                                if(flag>=50) {
                                        if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                        else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);
                                        }
                                break;
                             case "魔法师":
                                if(attack_skill=="staff")
                                flag=me->query("hell_skill/staff");
                                if(flag>=50) {if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);}
                                break;
                             case "终结者":
                                if(attack_skill=="mace")
                                flag=me->query("hell_skill/mace");
                                if(flag>=50) {if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);}
                                break;
                              case "精灵族":
                                if(attack_skill=="stick")
                                flag=me->query("hell_skill/stick");
                                if(flag>=50) {if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);}
                                break;
                              case "暗黑地狱使者":
                                if(attack_skill=="whip")
                                flag=me->query("hell_skill/whip");
                                if(flag>=50) {if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);}
                                break;
                              case "野蛮人":
                                if(attack_skill=="axe")
                                flag=me->query("hell_skill/axe");
                                if(flag>=50) {if((random(100)>85)&&(random(100)<15)) damage*=3;}
                                else if(flag>=25) {if((random(100)>80)&&(random(100)<20)) damage+=(damage/2);}
                                break;
                             }
                         }
                         } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage+= foo;
                        }

                        if( damage < 0 ) damage = 0;

                        //
                        //      (6) Inflict the damage.
                        //
                        damage-=(int)victim->query_temp("apply/armor");
                        if(damage<1)damage=1;
                        damage = victim->receive_damage("kee", damage, me );
                        result += damage_msg(damage, action["damage_type"]);
//                                       }

        }

        result = replace_string( result, "$l", limb );
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );

        message_vision(result, me, victim );

        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )
         {
                if( damage > 0 )
                 tell_object(me, sprintf( GRN "HELLFIRE_COMBAT AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,ap, dp, pp, damage));
                else
                  tell_object(me, sprintf( GRN "HELLFIRE_COMBAT AP：%d，DP：%d，PP：%d\n" NOR,ap, dp, pp));
         }

        if( damage > 0 ) {
                COMBAT_D->report_status(victim, 0);
                if( victim->is_busy() ) victim->interrupt_me(me);
                if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) ) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
                        message_vision(winner_msg[random(sizeof(winner_msg))], me, victim);
                }
        }

        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);

}

//
// 攻城部分
varargs int city_attack(object me, object victim,object who)     //功城的执行
{
    int myda,vda;
    int one,two,three;
    int ap,dp;

    one=me->query("soilder");
    two=victim->query("soilder");
    three=victim->query("defendance");

    message_vision("$N将手中长刀一挥。兵将蚁聚，涌至城边，一边架起云梯攀越城墙，一边掘土而进。\n",me);
    message_vision("$N只见城墙上万箭齐飞，擂石并发，守得是雷打不动，水泼不进。\n",me);
    ap=one*me->query("train_level");
    dp=two*(victim->query("train_level")+three);
    if((ap<=0)&&(dp>0))
    {
        message("vision",HIY+"【战火纷飞】:"+NOR+HIC+me->query("name")+"对"+
        victim->query("short")+"的进攻无功而返。"+who->query("name")+"守卫胜利.\n"NOR,users());
        tell_object(who,"你保卫了城市，得到了一年的道行奖励。\n");
        who->add("daoxing",1000);
        me->set("soilder",0);
        me->set("train_level",0);
        me->remove_enemy(victim);
        me->delete("attacking");
        victim->delete("receive_attack");
        victim->save();
        return 1;
    }

    if((ap>0)&&(dp<=0) )
    {
        message("vision",HIY+"【战火纷飞】:"+NOR+HIC+me->query("name")+"攻占了"+
        victim->query("short")+" ,"+who->query("name")+"守卫失利.\n"NOR,users());
        victim->set("owner",me->query("id"));
        victim->set("soilder",0);
        victim->set("train_level",0);
        me->remove_enemy(victim);
        me->delete("attacking");
        victim->delete("receive_attack");
        victim->save();
        return 1;
    }

    if(ap < dp )
    {
        message_vision("$N的守势当真牢靠，在一阵激烈的肉搏之后，$n的攻势缓了下来。\n",who,me);
        myda=(dp-ap)/1000;
        if(myda<=0) myda=-1*myda+1;
        tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
        me->add("soilder",-myda);
        tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(myda/2)+"名人马。\n");
        victim->add("soilder",-myda/5);
    }

    else if(ap < 5*dp)
    {
        message_vision("$N的守势当真顽强，在一阵激烈的肉搏之后，$n还是拿不下来。\n",who,me);
        myda=(ap-dp)*dp/(ap*1000);
        vda=(ap-dp)*ap/(dp*1000);
        if(vda<=0) vda=-1*vda+1;
        if(myda<=0) myda=-1*myda+1;
        tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
        me->add("soilder",-myda);
        tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
        victim->add("soilder",-vda);
        victim->add("defendance",-1);
        if(victim->query("defendance")<0) victim->set("defendance",0);
    }
    else
    {
        message_vision("$N的守势虽然顽强，在一阵激烈的肉搏之后，$n还是渐渐占了优势。\n",who,me);
        myda=(ap-dp)*dp/(ap*2000);
        vda=(ap-dp)*ap/(dp*500);
        if(vda<=0) vda=-1*vda+1;
        if(myda<=0) myda=-1*myda+1;

        tell_object(me,"敌人抵抗渐弱，你折损了:"+chinese_number(myda)+"名人马。\n");
        me->add("soilder",-myda);
        tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
        victim->add("soilder",-vda);
        victim->add("defendance",-2);
        if(victim->query("defendance")<0) victim->set("defendance",0);
    }
}

