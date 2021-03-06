// choose.c
// modify by mudring

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山", "方寸山三星洞", "月宫",
  "南海普陀山", "阎罗地府", "盘丝洞",
  "将军府", "东海龙宫", "陷空山无底洞",
  "五庄观", "火云洞", "蜀山剑派",
  "三界山", "轩辕古墓",
});

int filter_user(object ob, string family)
{
    if (!ob || wizardp(ob))
        return 0; 

    if (ob->query("family/family_name") != family)
        return 0;

    if (ob->query("combat_exp") < 80000)
        return 0;

    return 1;
}

void choose_mpc()
{
    int i, j ,k,ppl;
    object *list, newob;
    string m_name;

    j = random(sizeof(families));
    k = random(sizeof(families));
    m_name = STATU_D->family_master(families[k]);
    list = filter_array(users(), (: filter_user :), families[j]);
    i = sizeof(list);
    while (i--)
    {
        newob = new(__DIR__"npc");
        newob->set("target",families[k]);
        if (newob->invocation(list[i], k ))
            ppl++;
        else
            destruct(newob);
    }

    if (ppl)
    {
        if (j != k)
            message_job(HIW+m_name+HIG"：有"+chinese_number(ppl)
                        +"名"+families[j]+"刺客正在本门滋事，众弟子速回护法。");
        else
            message_job(HIW+m_name+HIG"：本派"+chinese_number(ppl)
                        +"名不孝弟子，欺师灭祖，众弟子速回护法。");
    } else
    {
        message_job( HIR"三界轮回帝 缥缈"+HIG"(Piao miao)：遥看世间情物，无限逍遥自在。");
        message_job( HIR"格月瓢彩 红霞"+HIG"(Hong xia)：紫若朝霞红似夕，亭风小曲别秋意。");
    }
}

