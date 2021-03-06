// cigar 轮回转世NPC

#include <ansi.h>
inherit NPC;

string *fo_names = ({
    "阿弥陀佛",
    "无量寿佛",
    "金刚不坏佛",
    "宝光佛",
    "龙尊王佛",
    "精进善佛",
    "宝月光佛",
    "现无愚佛",
    "婆留那佛",
    "那罗延佛",
    "功德华佛",
    "才功德佛",
    "善游步佛",
    "旃檀光佛",
    "摩尼幢佛",
    "慧炬照佛",
    "海德光明佛",
    "大慈光佛",
    "慈力王佛",
    "贤善首佛",
    "广主严佛",
    "金华光佛",
    "才光明佛",
    "智慧胜佛",
    "世静光佛",
    "日月光佛",
    "日月珠光佛",
    "慧幢胜王佛",
    "金海光佛",
    "大通光佛",
});

int query;
void create() 
{  
    set_name("如来佛祖", ({ "rulai fozu", "rulai", "fo" })); 
    set("title", "佛祖多陀阿伽陀"); 
    set("long", "大慈大悲灵山雷音古刹佛祖多陀阿伽陀如来佛爷。\n"); 
    set("gender", "男性"); 
    set("age", 10000); 
    set("attitude", "peaceful"); 
    set("rank_info/self", "贫僧"); 
    set("rank_info/respect", "佛祖爷爷"); 
    // set("class", "bonze"); 
    set("str",100); 
    set("per",100); 
    set("max_kee", 10000); 
    set("max_gin", 10000); 
    set("max_sen", 10000); 
    set("force", 10000); 
    set("max_force", 10000); 
    set("force_factor", 500); 
    set("max_mana", 10000); 
    set("mana", 10000); 
    set("mana_factor", 500); 
    set("combat_exp", 4000000); 
    set("daoxing", 10000000); 
    query = 1;
   
    setup();
    carry_object("/d/obj/cloth/jia_sha")->wear(); 

}

void init()
{
    if (query = 1)
    {
        STATU_D->set_npc_skill(this_object(), 300, "南海普陀山");
        query = 0;
    }
    add_action("do_shouli", "baili");
}

void announce(string str) 
{ 
    command("mete " + str); 
} 

int do_shouli(string arg)
{
    int i, j, level;
    mapping skill;
    object who;
    string *skillnames;
    who = this_player();

    seteuid(getuid());
        
    if (!metep(who))
    {
        command("say 你从哪里来？。");
        return 1;
    }
         
    who->command("say 拜见如来佛祖，弟子转生回来求受佛身！");

    level = who->query("opinion/mete");
    i = sizeof(fo_names);
    if (who->query("opinion/mete_name") == fo_names[i-level] )
    {
        command("say 你已经受本座的佛礼！");
        return 1;
    }

    if (level > i)
    {
        command("say 你已经经历凡尘无数风雨！");
        who->set("opinion/done","无天无量真佛");
        who->set("title",HIR"无天无量真佛"NOR);
        return 1;
    }

    who->set("opinion/mete_name",fo_names[i-level]);
    who->set("shouli_where",fo_names[i-level]);

    announce("菩提本无树，明镜亦非台。本来无一物，何处染尘埃。");
    announce("人世间那来的那么多尘烟？看看无垠的蓝天，那是永恒的虚空。");
    announce("所有一切众生类摄。若卵生若胎生若湿生若化生。");
    announce("若有色若无色。若有想若无想。若非有想若非无想。乃至众生界及假名说。");
    announce("不应生住法心。不应生住非法心。不应生有所住心。何以故。若心有住则为非住故。");
    announce("轮回转世空空荡去，世间万物终有一度，" + who->query("name") +
        "破红尘之身，化世俗凡念，心归我佛，轮回转世。");
    announce("本座授予" + who->name() + fo_names[i-level] + "，位居灵山宝殿"
        + fo_names[i-level] + "佛堂听道！");

    who->set("rank", COLOR_D->random_color(4) 
        + fo_names[i-level] + NOR);
    who->save();
              
    return 1;
}

 
void die() 
{ 
    if (environment()) 
        message("sound", "\n\n如来缓缓一点头：佛法无边！\n\n", environment()); 
    NPC_D->full_hp_status(this_object());
} 
 
void unconcious() 
{ 
    die (); 
}


