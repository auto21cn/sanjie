// by snowcat jan 22 1998

#include <ansi.h>
#include <quest.c>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "����",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "����",   "zai min" ,   "����(silver)", "5" }), 
// 12000   : ({ "kill",  "�׹Ǿ�", "baigu jing", "",             "3" });
 
//��һ�����ţ��ȼ������������ӣ�����׹Ǿ�������������

mapping quests_armor = ([
      20 : ({ "find", "�ֲ���",         "linen",              "", "1" }),
      40 : ({ "find", "Ƥ����",         "pi beixin",          "", "1" }),
      60 : ({ "find", "Ƥ��",           "pipao",              "", "1" }),
      80 : ({ "find", HIG"��ɴ��ȹ"NOR, "skirt",             "", "1" }),
     100 : ({ "find", "����",           "cloth",              "", "1" }),
     150 : ({ "find", "��ˮ����",       "nichang",            "", "1" }),
     200 : ({ "find", "����",           "magua",              "", "1" }),
     250 : ({ "find", "��а�",         "ao",                 "", "1" }),
     300 : ({ "find", "����",           "choupao",            "", "1" }),
     350 : ({ "find", "����",           "changpao",           "", "1" }),
     400 : ({ "find", "ţƤ��",         "leather shield",     "", "1" }),
     450 : ({ "find", "�ټ�",           "teng jia",           "", "1" }),
     500 : ({ "find", "ţƤѥ",         "leather boots",      "", "1" }),
     550 : ({ "find", "����ѥ",         "flower boots",       "", "1" }),
     600 : ({ "find", "����",           "cloth",              "", "1" }),
     650 : ({ "find", "Ƥ��",           "pipao",              "", "1" }),
     700 : ({ "find", "��ˮ����",       "nichang",            "", "1" }),
     750 : ({ "find", "Ӳľ��",         "ying mukui",         "", "1" }),

    1000 : ({ "find", "����",           "gong pao",           "", "1" }),
    1100 : ({ "find", "��ȹ",           "gong qun",           "", "1" }),
    1200 : ({ "find", "�ۺ����",       "pink cloth",         "", "1" }),
    1300 : ({ "find", "��ɫ÷ǳ��ȹ",   "pink skirt",         "", "1" }),
    1400 : ({ "find", "��̺",           "pi tan",             "", "1" }),
    1500 : ({ "find", "����̺",         "bai pitan",          "", "1" }),
    1600 : ({ "find", "��ɫ��̺",       "caise pitan",        "", "1" }),
    1700 : ({ "find", "��������",       "zirong pifeng",      "", "1" }),
    1800 : ({ "find", "����������",     "chang pao",          "", "1" }),
    1900 : ({ "find", "̫������",       "cloth",              "", "1" }),
    2000 : ({ "find", "ӡ��ȹ",         "skirt",              "", "1" }),
    2100 : ({ "find", "����Ͳȹ",       "skirt",              "", "1" }),
    2200 : ({ "find", "ˮȾ��ȹ",       "skirt",              "", "1" }),
    2300 : ({ "find", "�����س�ȹ",     "skirt",              "", "1" }),
    2400 : ({ "find", "����ȹ",         "skirt",              "", "1" }),
    2600 : ({ "find", "����",           "guan pao",           "", "1" }),
    2700 : ({ "find", "���ȹ",         "hong qun",           "", "1" }),
    2800 : ({ "find", "����",         "hua pao",            "", "1" }),
    2900 : ({ "find", "ˮӡ��ȹ",       "hua qun",            "", "1" }),
    3000 : ({ "find", "ϬţƤ��",       "xiniu piyi",         "", "1" }),

    5000 : ({ "find", "ϬƤ����",       "xipi beixin",        "", "1" }),
    5500 : ({ "find", "ţƤ��",         "niupi yi",           "", "1" }),
    6000 : ({ "find", "��Ƥ����",       "xiongpi duanpao",    "", "1" }),
    6500 : ({ "find", "��Ƥȹ",         "hupi qun",           "", "1" }),
    7000 : ({ "find", "ս��",           "zhan pao",           "", "1" }),
    7500 : ({ "find", "������",         "jinhua pao",         "", "1" }),
    8000 : ({ "find", "��Ƥȹ",         "shoupi qun",         "", "1" }),

   10000 : ({ "find", "����",           "iron armor",         "", "1" }),
   10500 : ({ "find", "������",         "silver armor",       "", "1" }),
   11000 : ({ "find", "ѩɽ����",       "baipao",             "", "1" }),
   11500 : ({ "find", "���Ե���",       "bagua pao",          "", "1" }),
   12000 : ({ "find", "��ͭ��",         "bronze armor",       "", "1" }),
   12500 : ({ "find", "���ս��",       "heaven armor",       "", "1" }),
   13000 : ({ "find", "��Ƥȹ",         "wolf skirt",         "", "1" }),
   13500 : ({ "find", "��Ƥȹ",         "shoupi qun",         "", "1" }),
   14000 : ({ "find", HIG "�Ž�ȹ" NOR, "palm skirt",         "", "1" }),
   15000 : ({ "find", "�����Ӽ�",     "golden armor",       "", "1" }),

   20000 : ({ "find", "���Ƥ",         "heipi pi",           "", "1" }),
   21000 : ({ "find", "����Ƥ",         "zongxiong pi",       "", "1" }),
   22000 : ({ "find", "�౷Ƥ",         "qingbei pi",         "", "1" }),
   23000 : ({ "find", "����Ƥ",         "mengma pi",          "", "1" }),

   30000 : ({ "find", "��ͷѥ",         "tie tou xue",        "", "1" }),
   31000 : ({ "find", "ͭͷѥ",         "tong tou xue",       "", "1" }),
   32000 : ({ "find", "��צ��",         "tie zhua tao",       "", "1" }),
   33000 : ({ "find", "ͭצ��",         "tong zhua tao",      "", "1" }),
   34000 : ({ "find", "������",         "tie shou tao",       "", "1" }),
   35000 : ({ "find", "ͭ����",         "tong shou tao",      "", "1" }),
   36000 : ({ "find", "��ͷ��",         "tie tou kui",        "", "1" }),
   37000 : ({ "find", "ͭͷ��",         "tong tou kui",       "", "1" }),
   38000 : ({ "find", "������",         "tie hu jian",        "", "1" }),
   39000 : ({ "find", "ͭ����",         "tong hu jian",       "", "1" }),
   40000 : ({ "find", "������",         "tie hu yao",         "", "1" }),
   41000 : ({ "find", "ͭ����",         "tong hu yao",        "", "1" }),
   42000 : ({ "find", "������",         "tie hu wan",         "", "1" }),
   43000 : ({ "find", "ͭ����",         "tong hu wan",        "", "1" }),

   44000 : ({ "find", HIY"��������"NOR, "jia sha",            "", "1" }),
   45000 : ({ "find", HIY"����"NOR,     "jia sha",            "", "1" }),
   46000 : ({ "find", "��Ƥ���",       "hupi dachang",       "", "1" }),

   47000 : ({ "find", "��ţƤ",         "maoniu pi",          "", "1" }),
   47500 : ({ "find", "ˮţƤ",         "shuiniu pi",         "", "1" }),
   48000 : ({ "find", "Ұ��Ƥ",         "yexiang pi",         "", "1" }),
   48500 : ({ "find", "��¹Ƥ",         "gonglu pi",          "", "1" }),
   49000 : ({ "find", "��Ƥ",           "chai pi",            "", "1" }),
   49500 : ({ "find", "�ڹ��",         "wugui jia",          "", "1" }),
   50000 : ({ "find", "���˼�",         "wangba jia",         "", "1" }),
   50500 : ({ "find", "ǧ�ۼ�",         "qianling jia",       "", "1" }),
   51000 : ({ "find", "��з��",         "juxie ke",           "", "1" }),
   51500 : ({ "find", "����Ƥ",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "�׻�Ƥ",         "baihu pi",           "", "1" }),
   52500 : ({ "find", "�ڻ�Ƥ",         "heihu pi",           "", "1" }),
   53000 : ({ "find", "��ʨƤ",         "jinshi pi",          "", "1" }),
   53500 : ({ "find", "��ëʨƤ",       "juanmao pi",         "", "1" }),
   54000 : ({ "find", "ɽèƤ",         "shanmao pi",         "", "1" }),

   55000 : ({ "find", "������",         "armor",              "", "1" }),
   55500 : ({ "find", "������",         "armor",              "", "1" }),
   56000 : ({ "find", "������",         "armor",              "", "1" }),
   56500 : ({ "find", "������",         "armor",              "", "1" }),
   57000 : ({ "find", "������",         "armor",              "", "1" }),
   57500 : ({ "find", "������",         "armor",              "", "1" }),
   58000 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   58500 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   59000 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   59500 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   60000 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   60500 : ({ "find", "��ͭ��",         "armor",              "", "1" }),

   61000 : ({ "find", "��Ƥ����",       "tiger surcoat",      "", "1" }),

   62000 : ({ "find", "�����ټ�",       "qingliu teng jia",   "", "1" }),
   63000 : ({ "find", "�����ټ�",       "chiliu teng jia",    "", "1" }),
   64000 : ({ "find", "�����ټ�",       "ziliu teng jia",     "", "1" }),
   65000 : ({ "find", "�����ټ�",       "heiliu teng jia",    "", "1" }),
   66000 : ({ "find", "�����ٶ�",       "qingluo dun",        "", "1" }),
   67000 : ({ "find", "�����ٶ�",       "ziluo dun",          "", "1" }),

   68000 : ({ "find", "��ľ��",         "zhangmu dun",        "", "1" }),
   69000 : ({ "find", "�ľ��",         "nanmu dun",          "", "1" }),
   70000 : ({ "find", "ϬţƤ��",       "xiniupi dun",        "", "1" }),
   71000 : ({ "find", "��Ƥ��",         "xiongpi dun",        "", "1" }),
   72000 : ({ "find", "��Ƥ��",         "xiangpi dun",        "", "1" }),
   73000 : ({ "find", "��Ƥ��",         "hupi dun",           "", "1" }),

   77051 : ({ "find", "������Ǽ�",     "armor",              "", "1" }),
   77052 : ({ "find", "ѹ�����Ǽ�",     "armor",              "", "1" }),
   77053 : ({ "find", "�λ����Ǽ�",     "armor",              "", "1" }),
   77054 : ({ "find", "������Ǽ�",     "armor",              "", "1" }),
   77055 : ({ "find", "�������Ǽ�",     "armor",              "", "1" }),
   77151 : ({ "find", "��߻����",     "armor",              "", "1" }),
   77152 : ({ "find", "ѹ�������",     "armor",              "", "1" }),
   77153 : ({ "find", "�λ������",     "armor",              "", "1" }),
   77154 : ({ "find", "��������",     "armor",              "", "1" }),
   77155 : ({ "find", "���Ļ����",     "armor",              "", "1" }),
   77251 : ({ "find", "���Ӳ�ټ�",     "armor",              "", "1" }),
   77252 : ({ "find", "ѹ��Ӳ�ټ�",     "armor",              "", "1" }),
   77253 : ({ "find", "�λ�Ӳ�ټ�",     "armor",              "", "1" }),
   77254 : ({ "find", "���Ӳ�ټ�",     "armor",              "", "1" }),
   77255 : ({ "find", "����Ӳ�ټ�",     "armor",              "", "1" }),
   77251 : ({ "find", "��߼�ľ��",     "armor",              "", "1" }),
   77352 : ({ "find", "ѹ����ľ��",     "armor",              "", "1" }),
   77353 : ({ "find", "�λ���ľ��",     "armor",              "", "1" }),
   77354 : ({ "find", "�����ľ��",     "armor",              "", "1" }),
   77355 : ({ "find", "���ļ�ľ��",     "armor",              "", "1" }),
   77451 : ({ "find", "��߹��Ƽ�",     "armor",              "", "1" }),
   77452 : ({ "find", "ѹ�����Ƽ�",     "armor",              "", "1" }),
   77453 : ({ "find", "�λ����Ƽ�",     "armor",              "", "1" }),
   77454 : ({ "find", "������Ƽ�",     "armor",              "", "1" }),
   77455 : ({ "find", "���Ĺ��Ƽ�",     "armor",              "", "1" }),
   77551 : ({ "find", "��߹�Ǧ��",     "armor",              "", "1" }),
   77552 : ({ "find", "ѹ����Ǧ��",     "armor",              "", "1" }),
   77553 : ({ "find", "�λ���Ǧ��",     "armor",              "", "1" }),
   77554 : ({ "find", "�����Ǧ��",     "armor",              "", "1" }),
   77555 : ({ "find", "���Ĺ�Ǧ��",     "armor",              "", "1" }),

   80000 : ({ "find", "��ɫ������ȹ",   "skirt",              "", "1" }),
   80001 : ({ "find", "��ɫ����սȹ",   "skirt",              "", "1" }),
   80002 : ({ "find", "��ɫ˿�޻�ȹ",   "skirt",              "", "1" }),
   80003 : ({ "find", "��ɫ˿��սȹ",   "skirt",              "", "1" }),
   80004 : ({ "find", "��ɫ��ɴ��ȹ",   "skirt",              "", "1" }),
   80005 : ({ "find", "��ɫ��ɴսȹ",   "skirt",              "", "1" }),
   80006 : ({ "find", "��ɫϸɴ��ȹ",   "skirt",              "", "1" }),
   80007 : ({ "find", "��ɫϸɴսȹ",   "skirt",              "", "1" }),
   80008 : ({ "find", "��ɫ��ɴ��ȹ",   "skirt",              "", "1" }),
   80009 : ({ "find", "��ɫ��ɴսȹ",   "skirt",              "", "1" }),
   80010 : ({ "find", "���������ȹ",   "skirt",              "", "1" }),
   80011 : ({ "find", "�������սȹ",   "skirt",              "", "1" }),
   80012 : ({ "find", "���˿�޻�ȹ",   "skirt",              "", "1" }),
   80013 : ({ "find", "���˿��սȹ",   "skirt",              "", "1" }),
   80014 : ({ "find", "�����ɴ��ȹ",   "skirt",              "", "1" }),
   80015 : ({ "find", "�����ɴսȹ",   "skirt",              "", "1" }),
   80016 : ({ "find", "���ϸɴ��ȹ",   "skirt",              "", "1" }),
   80017 : ({ "find", "���ϸɴսȹ",   "skirt",              "", "1" }),
   80018 : ({ "find", "�����ɴ��ȹ",   "skirt",              "", "1" }),
   80019 : ({ "find", "�����ɴսȹ",   "skirt",              "", "1" }),
   80020 : ({ "find", "����������ȹ",   "skirt",              "", "1" }),
   80021 : ({ "find", "��������սȹ",   "skirt",              "", "1" }),
   80022 : ({ "find", "����˿�޻�ȹ",   "skirt",              "", "1" }),
   80023 : ({ "find", "����˿��սȹ",   "skirt",              "", "1" }),
   80024 : ({ "find", "������ɴ��ȹ",   "skirt",              "", "1" }),
   80025 : ({ "find", "������ɴսȹ",   "skirt",              "", "1" }),
   80026 : ({ "find", "����ϸɴ��ȹ",   "skirt",              "", "1" }),
   80027 : ({ "find", "����ϸɴսȹ",   "skirt",              "", "1" }),
   80028 : ({ "find", "������ɴ��ȹ",   "skirt",              "", "1" }),
   80029 : ({ "find", "������ɴսȹ",   "skirt",              "", "1" }),
   80030 : ({ "find", "���������ȹ",   "skirt",              "", "1" }),
   80031 : ({ "find", "�������սȹ",   "skirt",              "", "1" }),
   80032 : ({ "find", "���˿�޻�ȹ",   "skirt",              "", "1" }),
   80033 : ({ "find", "���˿��սȹ",   "skirt",              "", "1" }),
   80034 : ({ "find", "�����ɴ��ȹ",   "skirt",              "", "1" }),
   80035 : ({ "find", "�����ɴսȹ",   "skirt",              "", "1" }),
   80036 : ({ "find", "���ϸɴ��ȹ",   "skirt",              "", "1" }),
   80037 : ({ "find", "���ϸɴսȹ",   "skirt",              "", "1" }),
   80038 : ({ "find", "�����ɴ��ȹ",   "skirt",              "", "1" }),
   80039 : ({ "find", "�����ɴսȹ",   "skirt",              "", "1" }),
   80040 : ({ "find", "�ϻ�������ȹ",   "skirt",              "", "1" }),
   80041 : ({ "find", "�ϻ�����սȹ",   "skirt",              "", "1" }),
   80042 : ({ "find", "�ϻ�˿�޻�ȹ",   "skirt",              "", "1" }),
   80043 : ({ "find", "�ϻ�˿��սȹ",   "skirt",              "", "1" }),
   80044 : ({ "find", "�ϻ���ɴ��ȹ",   "skirt",              "", "1" }),
   80045 : ({ "find", "�ϻ���ɴսȹ",   "skirt",              "", "1" }),
   80046 : ({ "find", "�ϻ�ϸɴ��ȹ",   "skirt",              "", "1" }),
   80047 : ({ "find", "�ϻ�ϸɴսȹ",   "skirt",              "", "1" }),
   80048 : ({ "find", "�ϻ���ɴ��ȹ",   "skirt",              "", "1" }),
   80049 : ({ "find", "�ϻ���ɴսȹ",   "skirt",              "", "1" }),

   90001 : ({ "find", "���޿�",         "cloth",              "", "1" }),
   90002 : ({ "find", "���ް�",         "cloth",              "", "1" }),
   90003 : ({ "find", "�����",         "cloth",              "", "1" }),
   90004 : ({ "find", "�����",         "cloth",              "", "1" }),
   90005 : ({ "find", "�����",         "cloth",              "", "1" }),
   90006 : ({ "find", "�����",         "cloth",              "", "1" }),
   90007 : ({ "find", "��˿��",         "cloth",              "", "1" }),
   90008 : ({ "find", "��˿��",         "cloth",              "", "1" }),

  100011 : ({ "find", "���޿�",         "cloth",              "", "1" }),
  100012 : ({ "find", "���ް�",         "cloth",              "", "1" }),
  100013 : ({ "find", "�����",         "cloth",              "", "1" }),
  100014 : ({ "find", "�����",         "cloth",              "", "1" }),
  100015 : ({ "find", "������",         "cloth",              "", "1" }),
  100016 : ({ "find", "������",         "cloth",              "", "1" }),
  100017 : ({ "find", "��˿��",         "cloth",              "", "1" }),
  100018 : ({ "find", "��˿��",         "cloth",              "", "1" }),

  110021 : ({ "find", "���޿�",         "cloth",              "", "1" }),
  110022 : ({ "find", "���ް�",         "cloth",              "", "1" }),
  110023 : ({ "find", "�����",         "cloth",              "", "1" }),
  110024 : ({ "find", "�����",         "cloth",              "", "1" }),
  110025 : ({ "find", "�ֽ���",         "cloth",              "", "1" }),
  110026 : ({ "find", "�ֽ���",         "cloth",              "", "1" }),
  110027 : ({ "find", "��˿��",         "cloth",              "", "1" }),
  110028 : ({ "find", "��˿��",         "cloth",              "", "1" }),

  120031 : ({ "find", "ϸ�޿�",         "cloth",              "", "1" }),
  120032 : ({ "find", "ϸ�ް�",         "cloth",              "", "1" }),
  120033 : ({ "find", "ϸ���",         "cloth",              "", "1" }),
  120034 : ({ "find", "ϸ���",         "cloth",              "", "1" }),
  120035 : ({ "find", "ϸ����",         "cloth",              "", "1" }),
  120036 : ({ "find", "ϸ����",         "cloth",              "", "1" }),
  120037 : ({ "find", "ϸ˿��",         "cloth",              "", "1" }),
  120038 : ({ "find", "ϸ˿��",         "cloth",              "", "1" }),

  130011 : ({ "find", "���޳�ȹ",       "skirt",              "", "1" }),
  130012 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130013 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130014 : ({ "find", "���г�ȹ",       "skirt",              "", "1" }),

  130021 : ({ "find", "���޳�ȹ",       "skirt",              "", "1" }),
  130022 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130023 : ({ "find", "�ؽ���ȹ",       "skirt",              "", "1" }),
  130024 : ({ "find", "�ضг�ȹ",       "skirt",              "", "1" }),

  130031 : ({ "find", "���޳�ȹ",       "skirt",              "", "1" }),
  130032 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130033 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130034 : ({ "find", "���г�ȹ",       "skirt",              "", "1" }),

  130041 : ({ "find", "ϸ�޳�ȹ",       "skirt",              "", "1" }),
  130042 : ({ "find", "ϸɴ��ȹ",       "skirt",              "", "1" }),
  130043 : ({ "find", "ϸ����ȹ",       "skirt",              "", "1" }),
  130044 : ({ "find", "ϸ�г�ȹ",       "skirt",              "", "1" }),

  130111 : ({ "find", "���޶�ȹ",       "skirt",              "", "1" }),
  130112 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130113 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130114 : ({ "find", "���ж�ȹ",       "skirt",              "", "1" }),

  130121 : ({ "find", "���޶�ȹ",       "skirt",              "", "1" }),
  130122 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130123 : ({ "find", "�ؽ���ȹ",       "skirt",              "", "1" }),
  130124 : ({ "find", "�ضж�ȹ",       "skirt",              "", "1" }),

  130131 : ({ "find", "���޶�ȹ",       "skirt",              "", "1" }),
  130132 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130133 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130134 : ({ "find", "���ж�ȹ",       "skirt",              "", "1" }),

  130141 : ({ "find", "ϸ�޶�ȹ",       "skirt",              "", "1" }),
  130142 : ({ "find", "ϸɴ��ȹ",       "skirt",              "", "1" }),
  130143 : ({ "find", "ϸ����ȹ",       "skirt",              "", "1" }),
  130144 : ({ "find", "ϸ�ж�ȹ",       "skirt",              "", "1" }),

  130211 : ({ "find", "���ޱ�ȹ",       "skirt",              "", "1" }),
  130212 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130213 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130214 : ({ "find", "���б�ȹ",       "skirt",              "", "1" }),

  130221 : ({ "find", "���ޱ�ȹ",       "skirt",              "", "1" }),
  130222 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130223 : ({ "find", "�ؽ���ȹ",       "skirt",              "", "1" }),
  130224 : ({ "find", "�ضб�ȹ",       "skirt",              "", "1" }),

  130231 : ({ "find", "���ޱ�ȹ",       "skirt",              "", "1" }),
  130232 : ({ "find", "��ɴ��ȹ",       "skirt",              "", "1" }),
  130233 : ({ "find", "������ȹ",       "skirt",              "", "1" }),
  130234 : ({ "find", "���б�ȹ",       "skirt",              "", "1" }),

  130241 : ({ "find", "ϸ�ޱ�ȹ",       "skirt",              "", "1" }),
  130242 : ({ "find", "ϸɴ��ȹ",       "skirt",              "", "1" }),
  130243 : ({ "find", "ϸ����ȹ",       "skirt",              "", "1" }),
  130244 : ({ "find", "ϸ�б�ȹ",       "skirt",              "", "1" }),

  140000 : ({ "find", "�ʱ���",         "color shell",        "", "1" }),
  150000 : ({ "find", "�����ȼ�",     "smoky armor",        "", "1" }),
  160000 : ({ "find", "��ˮ����",       "fancy skirt",        "", "1" }),
  200000 : ({ "find", "������",         "baipao",             "", "1" }),
  300000 : ({ "find", "��ħ��",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "����ս��",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "�ƻ�Ƥ",         "huang hupi",         "", "1" }),
  330000 : ({ "find", "��Ƥ����",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"������"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "�������",       "mangpao",            "", "1" }),
  800000 : ({ "find", HIY "������" NOR, "long pao",           "", "1" }),
 1000000 : ({ "find", HIY"�������"NOR, "tian yi",            "", "1" }),
 1100000 : ({ "find", "������",         "purple cloth",       "", "1" }),
 1200000 : ({ "find", HIY"��������"NOR, "jinlan jiasha",      "", "1" }),
 2000000 : ({ "find", HIG"��Ҷ��"NOR,   "xinye jia",          "", "1" }),

 2000010 : ({ "find", HIW"���ľ�"NOR,   "huxin jing",         "", "1" }),
 2000020 : ({ "find", YEL"��������"NOR, "sanjie shenpao",     "", "1" }),
 2000030 : ({ "find", CYN"��ľ��"NOR,   "heimu armor",        "", "1" }),
 2000040 : ({ "find", MAG"����ħ��"NOR, "poxian mokui",       "", "1" }),
 2000050 : ({ "find", HIR"̤�Ʒ�ѥ"NOR, "tayun feixue",       "", "1" }),
 2000060 : ({ "find", HIC"�߾�����"NOR, "qijue pifeng",       "", "1" }),
 2000070 : ({ "find", YEL"�ƽ�ս��"NOR, "gold armor",         "", "1" }),


]);


