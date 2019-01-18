// Fild：/d/npc/choose.c
// Changed to heart_beat() by mudring@sjsh......

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "盘丝洞",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "五庄观",
  "火云洞",
  "蜀山剑派",
  "三界山",
  "轩辕古墓",
});

void create()
{
        seteuid(getuid());
        set("channel_id","");
//
       call_out("start",5);
}
void start()
{
        this_object()->apply_condition("ximo_choose",360);
     this_object()->choose_mpc();
}

void choose_mpc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        list = users();
        i = sizeof(list);

        if (i < 10) return;

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 80000 )

                {
                newob = new(__DIR__"npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k ))
                ppl++;
                else
                destruct(newob);
                }
        }
        
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖";//
                        break;
                case "月宫":
                        m_name="西王母";//
                        break;
                case "阎罗地府":
                        m_name="地藏王菩萨";//
                        break;
                case "陷空山无底洞":
                        m_name="玉鼠精";//
                        break;
                case "将军府":
                        m_name="白发老人";//
                        break;
                case "火云洞":
                        m_name="黄飞虎";//
                        break;
                case "大雪山":
                        m_name="大鹏明王";//
                        break;
                case "五庄观":
                        m_name="镇元大仙";
                        break;
                case "南海普陀山":
                        m_name="观音菩萨";//
                        break;
                case "东海龙宫":
                        m_name="敖广";//
                        break;
                case "盘丝洞":
                        m_name="紫霞仙子";//
                        break;
                case "蜀山剑派":
                        m_name="蜀山剑圣";//                             
                        break;
                case "三界山":
                        m_name="纯阳天师";//
                        break;       
                case "轩辕古墓":
                        m_name="女娲";//
                        break;
        }
        if (ppl)
        {
        if (j != k)
//103          message("channel:job",HIG"〖"+HIR+families[k]+HIG+"〗"+HIW+m_name+HIG"：有"+chinese_number(ppl)+"名"+families[j]+"刺客正在本门滋事，众弟子速回护法。\n"NOR,users());
        message_job( HIW+m_name+HIG"：有"+chinese_number(ppl)+"名"+families[j]+"刺客正在本门滋事，众弟子速回护法。");
        else
//106          message("channel:job",HIG"〖"+HIR+families[k]+HIG+"〗"+HIW+m_name+HIG"：本派"+chinese_number(ppl)+"名不孝弟子，欺师灭祖，众弟子速回护法。\n"NOR,users());
        message_job( HIW+m_name+HIG"：本派"+chinese_number(ppl)+"名不孝弟子，欺师灭祖，众弟子速回护法。");
        }
        else
        {
        message_job( HIR"三界轮回帝 缥缈"+HIG"(Piao miao)：遥看世间情物，无限逍遥自在。");
        message_job( HIR"格月瓢彩 红霞"+HIG"(Hong xia)：紫若朝霞红似夕，亭风小曲别秋意。");
        }
}

