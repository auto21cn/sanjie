// 归位天尊

inherit NPC;

#include <ansi.h>

int send_back(object me);
string ask_shuizhu();
string ask_qingsuojian();

void create()
{
        set_name(HIC"归位天尊"NOR, ({ "guiwei tianzun", "tianzun"}) );
        set("gender", "男性" );
        set("age", 45);
        set("long",
                "这是天庭的一名使者,你可以(ask tianzun about back)返回。\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
                "回去" : (: send_back :),
                "back" : (: send_back :),
                "归位" : (: send_back :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        setup();
        carry_object("/obj/money/gold");
        carry_object("/d/obj/armor/jinjia")->wear();
}

int send_back(object me)
{
        me=this_player();
        command("sigh " + me->query("id"));
        command("say " + "知来不知去...唉～～好吧，你这就回去吧。\n");
        tell_object(me,"\n归位天尊甩动长袖，在你眼前一拂...\n\n你飘飘然地 ...\n\n");
        if(!me->query("dream_place")) me->move("/d/lanling/兰陵城心");
        else me->move((string)me->query("dream_place"));
        return 1;
}
void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fly");
// add_action("do_error", "perform");
//add_action("do_error", "cast");
add_action("do_error", "fight");
//add_action("do_error", "kill");
}

int do_error(string arg)
{
object who = this_player();
message_vision("不要捣蛋哦,小心被天界引起重视！\n",who);
return 1;
}
