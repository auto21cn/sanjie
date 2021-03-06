// vote unchblk
#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;       // valid voter numbers
  int vc;       // vote count;
  int df;
  string channel;
  string *juror, my_id;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
        return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

  if(victim->query("channel/chblk_on"))
  {
        channel = "交谈";
  } else if(victim->query("channel/chblk_party"))
  {
        channel = "门派";
  } else if(victim->query("channel/chblk_chat"))
  {
        channel = "聊天";
  } else if (victim->query("channel/chblk_rumor")) 
  {
        channel = "谣言";
  } else if (victim->query("channel/chblk_es")) 
  {
        channel = "网际";
  } else if (victim->query("channel/chblk_club")) 
  {
        channel = "帮会";
  } else if (victim->query("channel/chblk_new")) 
  {
        channel = "新手";
  } else if (victim->query("channel/chblk_sldh")) 
  {
        channel = "水陆大会";
  } else return notify_fail(victim->name()+"的频道已经是打开的了。\n");
  

  if (reason <= 0)
  {
        victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
        victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
        victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
        me->add("vote/abuse", 10);
        return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
  }

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/10;
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 10) df = 10 - vc;
  
  my_name = me->name(1);
  if (me == victim) v_name = "自己";
        else  v_name = victim->name(1);

  if (df>0)
  {
        shout( HIW "【表决】"+my_name+"投票打开"+v_name+"("+capitalize(victim->query("id"))+")"+"的"+channel+"频道，还差"
                        +chinese_number(df)+"票。\n" NOR);
        write( HIW "【表决】"+my_name+"投票打开" +v_name +"的"+channel+"频道，还差"
                        +chinese_number(df)+"票。\n" NOR);
    
        victim->apply_condition("vote_clear", 10);
                                
  } else 
  {
        if (me != victim)
        {
        shout( HIW "【表决】"+my_name+"投票打开"+v_name+"("+capitalize(victim->query("id"))+")"+"的"+channel+"频道。"
                +v_name+"的"+channel+"频道被打开了！\n" NOR);
        write( HIW "【表决】"+my_name+"投票打开" +v_name+"的"+channel+"频道。"
                +v_name+"的"+channel+"频道被打开了！\n" NOR);
        } else 
        {
        shout( HIW "【表决】"+my_name+"投票打开自己的"+channel+"频道。"
                +my_name+"的"+channel+"频道被打开了！\n" NOR);
        write( HIW "【表决】"+my_name+"投票打开自己的"+channel+"频道。"
                +my_name+"的"+channel+"频道被打开了！\n" NOR);
        }               
        
        victim->delete_condition("maren");
        victim->apply_condition("vote_clear", -10);
  } 
        victim->delete("channel");
  
  return 1;
}

