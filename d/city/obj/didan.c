/******************************************/
/* MUDLIB：Biographies         〓悟空传〓  */
/* Created Admin By Waiwai@2001/02/18     */
/* Admin Email：wkzstory@21cn.com         */
/******************************************/
// Created by waiwai@2001/03/03
// Last modified by waiwai@2001/03/25

#include <ansi.h>

inherit ITEM;
void create()
{
set_name(HIY"地界"HIW"辟毒丹"NOR,({"pidu-dan","dan"}));
set("long","这是这是一颗世间难得的宝丹,可以用来解"HIR"（ｃｕｒｅ）"NOR"百毒！\n");
set("value",30000);
set("unit","枚");
//set("is_monitored",1);
}

void init()
{
if(this_player()==environment()) add_action("do_cure","cure");
}

int do_cure()
{
object me;me = this_player();
message_vision("$N一口将辟毒丹吞入腹中!\n",me);
me->clear_condition();
message_vision("$N只觉腹内一阵清凉直透全身经脉,身中剧毒居然不再发作了!\n",me);
destruct(this_object());
return 1;
}

int query_autoload() { return 1; }
