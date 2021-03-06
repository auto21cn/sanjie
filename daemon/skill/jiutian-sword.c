//九天黄泉剑法 BY Cigar 2002.04.19
inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N身形一幌，使出",
        "$N妍然一笑，一式",
        "$N飞身跃起，使出",
});
string* skill_tail =({
        "，手中$w化为一道无力月光刺向$n的$l。",
        "，手中$w舞出满天剑影罩向$n。",
        "，手中$w不偏一歪，直封$n的$l。",
        "，手中$w如飞，发出点点月光。",
        "，$w从右肩急甩向后，撒出点点微光击向$n$l。",
});

mapping *action = ({
   ([   "action":
"$n只觉眼前一闪，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开，一招"+BLINK""+HIM"「九天无恨泣江川」"NOR"已悄然划向$n的后心",
     "dodge":     -5,
                "parry":                -10,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"飞身跃起，$n抬眼一望，月光失色，但见得$N手中$w舞出满天剑影，"+BLINK""+HIC"[黄泉遮月荒凝神]"NOR"已将$n笼罩",
     "dodge":     -15,
                "parry":                -25,
     "damage":     40,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中$w轻轻一刺，手中$w如幽灵一般,一式"+BLINK""+HIB"[月纹瑕疵掩蝠影]"NOR"无形的点向$n的左肋",
     "dodge":     -10,
                "parry":                -15,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w犹似一条柔丝，竟如没半分重量，化成片片雪花，在$n身周飘荡不定，正是一招"+BLINK""+HIW"[风花雪月寒九天]"NOR"",
     "dodge":     -10,
                "parry":                -5,
     "damage":     50,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"突然之间天地失色，$N身形拖出一道道寒光，使出一招"+BLINK""+HIG"「逐神」"NOR"，$w从上空急甩向后，击向$n$l，正如点点剑影无处不及",
     "dodge":     -20,
                "parry":                -10,
     "damage":     55,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;
    if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练九天黄泉剑法。\n");

   if( (string)me->query_skill_mapped("force")!= "huxiaolunhui-force")
     return notify_fail("九天黄泉剑法必须配合呼啸轮回神功才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先用剑才能练习。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("jiutianhuangquan_perform");
 if( ! me->query_temp("jiutianhuangquan_perform"))
      {
     if(me->query("skill_jiutianhuangquan-sword")==0) return action[random(5)];
     if(random(2))return action[random(5)];
     m_actions=me->query("skill_jiutianhuangquan-sword");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[5];
  }
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 10 )
     return notify_fail("你的内力或气不够，没有办法练习九天黄泉剑法。\n");
   me->receive_damage("kee", 25);
   me->add("force", -3);
   write("你按所学练了一遍九天黄泉剑法，真气灌涌全身。\n");
   return 1;
}


string perform_action_file(string func)
{
return __DIR__"jiutian-sword/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("jiutianhuangquan-sword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIR"你对九天黄泉剑法的领悟加深了，你的九天黄泉剑法进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中产生了一种失落感，似乎缺少点什么？\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"你心中杂念丛生，无法安静的修行，似乎轮回大碍你还没有领悟。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然被九天黄泉的灵气所召唤，对九天黄泉剑法领悟出了新的绝招！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_jiutianhuangquan-sword");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="九天黄泉剑法必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIR"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_jiutianhuangquan-sword",m_actions);
}
